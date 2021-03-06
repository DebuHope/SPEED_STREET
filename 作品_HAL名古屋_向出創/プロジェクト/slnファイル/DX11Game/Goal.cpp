//======================================================================================
// ゴールポイント処理
// 制作：向出創
//======================================================================================
#include <stdlib.h>
#include "Goal.h"
#include "Shader.h"
#include "Texture.h"
#include "mesh.h"
#include "Shadow.h"
#include "Player.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TEXTURE_GOAL	L"data/texture/UI/Goal.png"

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define GOAL_RADIUS		(40.0F)

//*****************************************************************************
// 構造体定義
//*****************************************************************************
typedef struct _tGoal{
	int			nState;		// 状態
	XMFLOAT3	pos;		// 座標
	int			nShadowIdx;	// 影番号
	bool		CheckFlag;

}tGoal;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT MakeVertexGoal(ID3D11Device* pDevice);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static MESH		g_mesh;		// メッシュ情報
static MATERIAL	g_material;	// マテリアル情報

static tGoal	g_goal[MAX_GOAL];

HRESULT LoadGoal(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr = S_OK;

	// マテリアルの初期設定
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 50.0f;
	g_material.Emissive = M_EMISSIVE;
	g_mesh.pMaterial = &g_material;

	// テクスチャの読み込み
	hr = CreateTextureFromFile(pDevice, TEXTURE_GOAL, &g_mesh.pTexture);
	if (FAILED(hr))	return hr;

	// ワールドマトリクス初期化
	XMStoreFloat4x4(&g_mesh.mtxTexture, XMMatrixIdentity());
	XMStoreFloat4x4(&g_mesh.mtxWorld, XMMatrixIdentity());

	// 頂点情報の作成
	hr = MakeVertexGoal(pDevice);

	return hr;
}
//=============================================================================
// 初期化処理
//=============================================================================
void InitGoal(void)
{
	// 変数の初期化
	for (int i = 0; i < MAX_GOAL; i++) {
		g_goal[i].nShadowIdx = -1;
		g_goal[i].nState = 0;
	}
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitGoal(void)
{
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL;
		++i, ++pGoal)
	{
		if (pGoal->nState == 0) continue;
		pGoal->nState = 0;
		// 影との関連を切る
		ReleaseShadow(pGoal->nShadowIdx);
		pGoal->nShadowIdx = -1;
	}

	// メッシュ解放
	//for (int i = 0; i < 2; i++) {
	//	ReleaseMesh(&g_mesh[i]);
	//}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateGoal(void)
{
	// 更新処理
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL; i++, ++pGoal)
	{
		if (pGoal->nState == 0) continue;

		// 影の移動
		MoveShadow(pGoal->nShadowIdx, pGoal->pos);

		// 画面に近づいたら消す
		if (pGoal->pos.z < GetPlayerPos(0).z - 60.0f) {
			DestroyGoal(i);
		}

		// 影を消す
		if (pGoal->pos.y <= 0.0f) {
			ReleaseShadow(pGoal->nShadowIdx);
			pGoal->nShadowIdx = -1;
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawGoal(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();
	// 合成設定
	SetBlendState(BS_ALPHABLEND);

	XMFLOAT4X4 mView = GetCamera()->GetViewMatrix();	// ビューマトリックス
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL; i++, pGoal++) {
		// 出てない弾は処理しない
		if (pGoal->nState == 0) {
			continue;
		}

		// ビュー行列の回転成分の転置行列を設定
		g_mesh.mtxWorld._11 = mView._11;
		g_mesh.mtxWorld._12 = mView._21;
		g_mesh.mtxWorld._13 = mView._31;
		g_mesh.mtxWorld._21 = mView._12;
		g_mesh.mtxWorld._22 = mView._22;
		g_mesh.mtxWorld._23 = mView._32;
		g_mesh.mtxWorld._31 = mView._13;
		g_mesh.mtxWorld._32 = mView._23;
		g_mesh.mtxWorld._33 = mView._33;

		// 拡大縮小
		XMMATRIX mtxScl = XMMatrixScaling(GOAL_RADIUS, GOAL_RADIUS, GOAL_RADIUS);
		XMMATRIX mtxRot;
		mtxRot = XMLoadFloat4x4(&g_mesh.mtxWorld);
		mtxRot = XMMatrixMultiply(mtxRot, mtxScl);
		XMStoreFloat4x4(&g_mesh.mtxWorld, mtxRot);

		// 位置を反映
		g_mesh.mtxWorld._41 = pGoal->pos.x;
		g_mesh.mtxWorld._42 = pGoal->pos.y;
		g_mesh.mtxWorld._43 = pGoal->pos.z;

		DrawMesh(pDeviceContext, &g_mesh);
	}
	// もとに戻す
	SetBlendState(BS_NONE);
}

// 設置
int SetGoal(XMFLOAT3 pos)
{
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL;	++i, ++pGoal)
	{	// 出現している弾はスルー
		if (pGoal->nState > 0) continue;

		pGoal->pos = pos;
		pGoal->nState = 1;	// 出現
		// 影の作成
		pGoal->nShadowIdx = CreateShadow(pGoal->pos, 20.0f);

		return i;	// 番号を返す
	}

	return -1;	// 見つからなかった
}

XMFLOAT3 GetGoalPos(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return XMFLOAT3(0.0f,0.0f,0.0f);
	}

	return g_goal[no].pos;
}

XMFLOAT3 GetGoalSize(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	return XMFLOAT3(GOAL_RADIUS / 2.2f, GOAL_RADIUS, GOAL_RADIUS / 2.0f);
}

bool IsGoal(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return false;
	}
	return g_goal[no].nState > 0 ? true : false;	// 0より上＝true 0以下＝false
}

void DestroyGoal(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return;
	}
	g_goal[no].nState = 0;
	ReleaseShadow(g_goal[no].nShadowIdx);
	g_goal[no].nShadowIdx = -1;
}

HRESULT MakeVertexGoal(ID3D11Device* pDevice)
{
	VERTEX_3D vertexWk[NUM_VERTEX]; //作業用頂点情報
	int		  indexWk[NUM_VERTEX];	//作業用インデックス

	// 頂点座標の設定
	g_mesh.nNumVertex = NUM_VERTEX;
	vertexWk[0].vtx = XMFLOAT3(-0.5f, 0.5f, 0.0f);
	vertexWk[1].vtx = XMFLOAT3(0.5f, 0.5f, 0.0f);
	vertexWk[2].vtx = XMFLOAT3(-0.5f, -0.5f, 0.0f);
	vertexWk[3].vtx = XMFLOAT3(0.5f, -0.5f, 0.0f);

	// ディフューズの設定
	vertexWk[0].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[1].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[2].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[3].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	// 法線ベクトルの設定
	vertexWk[0].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);
	vertexWk[1].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);
	vertexWk[2].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);
	vertexWk[3].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);

	// テクスチャ座標の設定
	vertexWk[0].tex = XMFLOAT2(0.0f, 0.0f);
	vertexWk[1].tex = XMFLOAT2(1.0f, 0.0f);
	vertexWk[2].tex = XMFLOAT2(0.0f, 1.0f);
	vertexWk[3].tex = XMFLOAT2(1.0f, 1.0f);

	// インデックス配列の設定
	g_mesh.nNumIndex = NUM_VERTEX;
	indexWk[0] = 0;
	indexWk[1] = 1;
	indexWk[2] = 2;
	indexWk[3] = 3;

	return MakeMeshVertex(pDevice, &g_mesh, vertexWk, indexWk);
}