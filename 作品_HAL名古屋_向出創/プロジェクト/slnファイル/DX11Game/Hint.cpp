//======================================================================================
// ヒント処理
// 制作：向出創
//======================================================================================
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Hint.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "Object.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define TEXTURE_HINT1	L"data/texture/icon_Lollipop2.png"
#define TEXTURE_HINT2	L"data/texture/HintSlime.png"
#define TEXTURE_HINT3	L"data/texture/HintWingeye.png"
#define TEXTURE_HINT4	L"data/texture/car.png"		
#define TEXTURE_HINT5	L"data/texture/HintSita.png"
#define TEXTURE_HINT6	L"data/texture/HintUe.png"	
#define TEXTURE_HINT7	L"data/texture/HintLeft.png"
#define TEXTURE_HINT8	L"data/texture/HintRight.png"

#define MAX_HINT_TEXTURE	(8)

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define SIZE_X			(50.0f)
#define SIZE_Y			(0.0f)
#define SIZE_Z			(50.0f)

//*****************************************************************************
// 構造体定義
//*****************************************************************************
typedef struct _tHint {
	XMFLOAT3 pos;	// 位置
	XMFLOAT3 rot;	// 回転
	XMFLOAT3 scl;	// 拡大
}tHint;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT MakeVertexHint(ID3D11Device* pDevice, int i);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static MESH			g_mesh[MAX_HINT_TEXTURE];		// メッシュ情報（オブジェクトの表面）
static MATERIAL		g_material;	// マテリアル情報

static tHint g_hint[MAX_HINT];
static int DrawHintNo;			// 表示するヒントNo

HRESULT LoadHint(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr = S_OK;

	// マテリアルの初期設定
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 1.0f;
	g_material.Emissive = M_EMISSIVE;

	for (int i = 0; i < MAX_HINT_TEXTURE; i++) {
		g_mesh[i].pMaterial = &g_material;
	}

	// テクスチャの読み込み
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT1, &g_mesh[0].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT2, &g_mesh[1].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT3, &g_mesh[2].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT4, &g_mesh[3].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT5, &g_mesh[4].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT6, &g_mesh[5].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT7, &g_mesh[6].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HINT8, &g_mesh[7].pTexture);
	if (FAILED(hr))	return hr;

	// ワールドマトリクス初期化
	for (int i = 0; i < MAX_HINT_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, XMMatrixIdentity());
		XMStoreFloat4x4(&g_mesh[i].mtxWorld, XMMatrixIdentity());
	}

	// 頂点情報の作成
	for (int i = 0; i < MAX_HINT_TEXTURE; i++) {
		hr = MakeVertexHint(pDevice, i);
	}

	return hr;
}

//=============================================================================
// 初期化処理
//=============================================================================
void InitHint(void)
{
	// 変数の初期化
	for (int i = 0; i < MAX_HINT; i++) {
		g_hint[i].pos = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_hint[i].rot = XMFLOAT3(-90.0f, 0.0f, 0.0f);
		g_hint[i].scl = XMFLOAT3(0.5f, 0.5f, 0.5f);
	}
	DrawHintNo = 0;
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitHint(void)
{
	// メッシュ解放
	//ReleaseMesh(&g_mesh);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateHint(void)
{
	for (int i = 0; i < MAX_HINT; i++) {
		// 移動など更新処理をこの下に記述
		// ====================================================================
		g_hint[i].pos.x = GetObjectPos(17).x;
		g_hint[i].pos.y = GetObjectPos(17).y + 65.0f;
		g_hint[i].pos.z = GetObjectPos(17).z - 5.0f;

		g_hint[i].rot.x = GetObjectRot(17).x - 90.0f;
		g_hint[i].rot.y = GetObjectRot(17).y;
		g_hint[i].rot.z = GetObjectRot(17).z;
		// ====================================================================
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawHint(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// 半透明を合成する
	SetBlendState(BS_ALPHABLEND);

	for (int i = 0; i < MAX_HINT; i++) {

		for (int j = 0; j < MAX_HINT_TEXTURE; j++) {
			g_mesh[j].scl = g_hint[i].scl;
			g_mesh[j].pos = g_hint[i].pos;
			g_mesh[j].rot = g_hint[i].rot;

			// メッシュ更新
			UpdateMesh(&g_mesh[j]);
		}
		// メッシュの描画
		DrawMesh(pDeviceContext, &g_mesh[DrawHintNo]);
	}

	// 半透明元を戻す
	SetBlendState(BS_NONE);
}

int SetHint(int drawno)
{
	for (int i = 0; i < MAX_HINT; i++)
	{
		DrawHintNo = drawno;

		return i;	// 番号を返す
	}

	return -1;	// 見つからなかった
}

HRESULT MakeVertexHint(ID3D11Device* pDevice, int i)
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

// 座標所得
XMFLOAT3 GetHintPos(int no)
{
	if (no < 0 || no >= MAX_HINT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_hint[no].pos;
}

// サイズ所得
XMFLOAT3 GetHintSize(int no)
{
	if (no < 0 || no >= MAX_HINT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return XMFLOAT3(SIZE_X, SIZE_Y, SIZE_Z);
}

// 地面があるか
bool IsHint(int no)
{
	if (no < 0 || no >= MAX_HINT) {
		return false;
	}
	return true;
}