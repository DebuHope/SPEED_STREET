//======================================================================================
// 落とし穴処理
// 制作：向出創
//======================================================================================
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Hole.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TEXTURE_HOLE	L"data/texture/hole3.png"
#define TEXTURE_IKE		L"data/texture/ike.png"
#define TEXTURE_HOLE3	L"data/texture/hole4.png"
#define MAX_HOLE_TEXTURE	(3)

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define SIZE_X			(50.0f)
#define SIZE_Y			(0.0f)
#define SIZE_Z			(70.0f)

//*****************************************************************************
// 構造体定義
//*****************************************************************************
typedef struct _tHole {
	XMFLOAT3 pos;	// 位置
	XMFLOAT3 rot;	// 回転
	XMFLOAT3 scl;	// 拡大

	int nState;		// 状態(0以下:未使用 1以上:通常)
}tHole;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT MakeVertexHole(ID3D11Device* pDevice, int i);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static MESH			g_mesh[MAX_HOLE_TEXTURE];		// メッシュ情報（オブジェクトの表面）
static MATERIAL		g_material;	// マテリアル情報

static tHole g_hole[MAX_HOLE];	// フィールド数

int		DrawTexNo;

HRESULT LoadHole(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr;

	// マテリアルの初期設定
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 1.0f;
	g_material.Emissive = M_EMISSIVE;

	for (int i = 0; i < MAX_HOLE_TEXTURE; i++) {
		g_mesh[i].pMaterial = &g_material;
	}

	// テクスチャの読み込み
	hr = CreateTextureFromFile(pDevice,TEXTURE_HOLE,&g_mesh[0].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_IKE, &g_mesh[1].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HOLE3, &g_mesh[2].pTexture);
	if (FAILED(hr))	return hr;

	// ワールドマトリクス初期化
	for (int i = 0; i < MAX_HOLE_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, XMMatrixIdentity());
		XMStoreFloat4x4(&g_mesh[i].mtxWorld, XMMatrixIdentity());
	}

	// 頂点情報の作成
	for (int i = 0; i < MAX_HOLE_TEXTURE; i++) {
		hr = MakeVertexHole(pDevice, i);
	}

	return hr;
}

//=============================================================================
// 初期化処理
//=============================================================================
void InitHole(void)
{
	// 変数の初期化
	for (int i = 0; i < MAX_HOLE; i++) {
		g_hole[i].nState = 0;
		g_hole[i].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
		g_hole[i].rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_hole[i].scl = XMFLOAT3(1.0f, 1.0f, 1.0f);
	}
	DrawTexNo = 0;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitHole(void)
{
	// メッシュ解放
	//ReleaseMesh(&g_mesh);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateHole(void)
{
	for (int i = 0; i < MAX_HOLE; i++) {
		if (g_hole[i].nState == 0)	continue;
		// 移動など更新処理をこの下に記述
		// ====================================================================
		// ====================================================================
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawHole(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// 半透明を合成する
	SetBlendState(BS_ALPHABLEND);

	for (int i = 0; i < MAX_HOLE; i++) {
		if (g_hole[i].nState == 0) continue;

		for (int j = 0; j < MAX_HOLE_TEXTURE; j++) {
			g_mesh[j].scl = g_hole[i].scl;
			g_mesh[j].pos = g_hole[i].pos;
			g_mesh[j].rot = g_hole[i].rot;


			// メッシュ更新
			UpdateMesh(&g_mesh[j]);
		}
		// メッシュの描画
		switch (GetSceneNo())
		{
		case SCENE_STAGE1_1:
		case SCENE_STAGE1_2:
		case SCENE_STAGE1_3:
		case SCENE_STAGE1_4:
			DrawTexNo = 0;
			break;
		case SCENE_STAGE2_1:
		case SCENE_STAGE2_2:
		case SCENE_STAGE2_3:
		case SCENE_STAGE2_4:
			DrawTexNo = 1;
			break;
		case SCENE_STAGE3_1:
		case SCENE_STAGE3_2:
		case SCENE_STAGE3_3:
		case SCENE_STAGE3_4:
			DrawTexNo = 2;
			break;
		}
		DrawMesh(pDeviceContext, &g_mesh[DrawTexNo]);
	}
	// 半透明元を戻す
	SetBlendState(BS_NONE);
}

HRESULT MakeVertexHole(ID3D11Device* pDevice, int i)
{
	VERTEX_3D vertexWk[NUM_VERTEX]; //作業用頂点情報
	int		  indexWk[NUM_VERTEX];	//作業用インデックス

	// 頂点座標の設定
	g_mesh[i].nNumVertex = NUM_VERTEX;
	vertexWk[0].vtx	= XMFLOAT3(-SIZE_X, 0.0f,  SIZE_Z);
	vertexWk[1].vtx	= XMFLOAT3( SIZE_X, 0.0f,  SIZE_Z);
	vertexWk[2].vtx	= XMFLOAT3(-SIZE_X, 0.0f, -SIZE_Z);
	vertexWk[3].vtx	= XMFLOAT3( SIZE_X, 0.0f, -SIZE_Z);
	
	// ディフューズの設定								alpha値
	vertexWk[0].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[1].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[2].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[3].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	// 法線ベクトルの設定
	vertexWk[0].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertexWk[1].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertexWk[2].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertexWk[3].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);

	// テクスチャ座標の設定
	vertexWk[0].tex = XMFLOAT2(0.0f, 0.0f);
	vertexWk[1].tex = XMFLOAT2(1.0f, 0.0f);
	vertexWk[2].tex = XMFLOAT2(0.0f, 1.0f);
	vertexWk[3].tex = XMFLOAT2(1.0f, 1.0f);

	// インデックス配列の設定
	g_mesh[i].nNumIndex = NUM_VERTEX;
	indexWk[0] = 0;
	indexWk[1] = 1;
	indexWk[2] = 2;
	indexWk[3] = 3;

	return MakeMeshVertex(pDevice, &g_mesh[i], vertexWk, indexWk);
}

// 穴出現
int SetHole(XMFLOAT3 pos, XMFLOAT3 scl)
{
	for (int i = 0; i < MAX_HOLE; i++)
	{	// 出現している弾はスルー
		if (g_hole[i].nState > 0) continue;

		g_hole[i].pos = pos;
		g_hole[i].scl = scl;
		g_hole[i].nState = 1;	// 出現
		
		return i;	// 番号を返す
	}

	return -1;	// 見つからなかった
}

// 座標所得
XMFLOAT3 GetHolePos(int no)
{
	if (no < 0 || no >= MAX_HOLE) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_hole[no].pos;
}

// サイズ所得
XMFLOAT3 GetHoleSize(int no)
{
	if (no < 0 || no >= MAX_HOLE) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return XMFLOAT3(SIZE_X / 1.5f, SIZE_Y, SIZE_Z / 1.6f);
}

// 地面があるか
bool IsHole(int no)
{
	if (no < 0 || no >= MAX_HOLE) {
		return false;
	}
	return true;
}