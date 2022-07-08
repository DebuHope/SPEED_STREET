//======================================================================================
// チェックポイント処理
// 制作：向出創
//======================================================================================
#include <stdlib.h>
#include "CheckPoint.h"
#include "Shader.h"
#include "Texture.h"
#include "mesh.h"
#include "Shadow.h"
#include "Player.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TEXTURE_CHECKPOINT	L"data/texture/UI/Check.png"

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define CHECKPOINT_RADIUS		(40.0F)

//*****************************************************************************
// 構造体定義
//*****************************************************************************
typedef struct _tCheckPoint{
	int			nState;		// 状態
	XMFLOAT3	pos;		// 座標
	int			nShadowIdx;	// 影番号
	bool		CheckFlag;

}tCheckPoint;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT MakeVertexCheckPoint(ID3D11Device* pDevice);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static MESH		g_mesh;		// メッシュ情報
static MATERIAL	g_material;	// マテリアル情報

static tCheckPoint	g_checkpoint[MAX_CHECKPOINT];

HRESULT LoadCheckPoint(void)
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
	hr = CreateTextureFromFile(pDevice, TEXTURE_CHECKPOINT, &g_mesh.pTexture);
	if (FAILED(hr))	return hr;

	// ワールドマトリクス初期化
	XMStoreFloat4x4(&g_mesh.mtxTexture, XMMatrixIdentity());
	XMStoreFloat4x4(&g_mesh.mtxWorld, XMMatrixIdentity());

	// 頂点情報の作成
	hr = MakeVertexCheckPoint(pDevice);

	return hr;
}
//=============================================================================
// 初期化処理
//=============================================================================
void InitCheckPoint(void)
{
	// 変数の初期化
	for (int i = 0; i < MAX_CHECKPOINT; i++) {
		g_checkpoint[i].nShadowIdx = -1;
		g_checkpoint[i].nState = 0;
		//g_checkpoint[i].CheckFlag = false;
	}
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitCheckPoint(void)
{
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT;
		++i, ++pCheckPoint)
	{
		if (pCheckPoint->nState == 0) continue;
		pCheckPoint->nState = 0;
		// 影との関連を切る
		ReleaseShadow(pCheckPoint->nShadowIdx);
		pCheckPoint->nShadowIdx = -1;
	}

	// メッシュ解放
	//for (int i = 0; i < 2; i++) {
	//	ReleaseMesh(&g_mesh[i]);
	//}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateCheckPoint(void)
{
	// 更新処理
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT; i++, ++pCheckPoint)
	{
		if (pCheckPoint->nState == 0) continue;

		// 影の移動
		MoveShadow(pCheckPoint->nShadowIdx, pCheckPoint->pos);

		// 画面に近づいたら消す
		if (pCheckPoint->pos.z < GetPlayerPos(0).z - 60.0f) {
			DestroyCheckPoint(i);
		}

		// 影を消す
		if (pCheckPoint->pos.y <= 0.0f) {
			ReleaseShadow(pCheckPoint->nShadowIdx);
			pCheckPoint->nShadowIdx = -1;
		}
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawCheckPoint(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();
	// 合成設定
	SetBlendState(BS_ALPHABLEND);

	XMFLOAT4X4 mView = GetCamera()->GetViewMatrix();	// ビューマトリックス
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT; i++, pCheckPoint++) {
		// 出てない弾は処理しない
		if (pCheckPoint->nState == 0) {
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
		XMMATRIX mtxScl = XMMatrixScaling(CHECKPOINT_RADIUS, CHECKPOINT_RADIUS, CHECKPOINT_RADIUS);
		XMMATRIX mtxRot;
		mtxRot = XMLoadFloat4x4(&g_mesh.mtxWorld);
		mtxRot = XMMatrixMultiply(mtxRot, mtxScl);
		XMStoreFloat4x4(&g_mesh.mtxWorld, mtxRot);

		// 位置を反映
		g_mesh.mtxWorld._41 = pCheckPoint->pos.x;
		g_mesh.mtxWorld._42 = pCheckPoint->pos.y;
		g_mesh.mtxWorld._43 = pCheckPoint->pos.z;

		DrawMesh(pDeviceContext, &g_mesh);
	}
	// もとに戻す
	SetBlendState(BS_NONE);
}

// 設置
int SetCheckPoint(XMFLOAT3 pos)
{
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT;	++i, ++pCheckPoint)
	{	// 出現している弾はスルー
		if (pCheckPoint->nState > 0) continue;

		pCheckPoint->pos = pos;
		pCheckPoint->nState = 1;	// 出現
		// 影の作成
		pCheckPoint->nShadowIdx = CreateShadow(pCheckPoint->pos, 20.0f);

		return i;	// 番号を返す
	}

	return -1;	// 見つからなかった
}

XMFLOAT3 GetCheckPointPos(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return XMFLOAT3(0.0f,0.0f,0.0f);
	}

	return g_checkpoint[no].pos;
}

XMFLOAT3 GetCheckPointSize(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	return XMFLOAT3(CHECKPOINT_RADIUS / 2.2f, CHECKPOINT_RADIUS, CHECKPOINT_RADIUS / 2.0f);
}

bool IsCheckPoint(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return false;
	}
	return g_checkpoint[no].nState > 0 ? true : false;	// 0より上＝true 0以下＝false
}

void DestroyCheckPoint(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return;
	}
	g_checkpoint[no].nState = 0;
	ReleaseShadow(g_checkpoint[no].nShadowIdx);
	g_checkpoint[no].nShadowIdx = -1;
}

bool GetCheckFlag(int no)
{
	return g_checkpoint[no].CheckFlag;
}

void SetCheckFlag(int no, bool flag)
{
	g_checkpoint[no].CheckFlag = flag;
}

HRESULT MakeVertexCheckPoint(ID3D11Device* pDevice)
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