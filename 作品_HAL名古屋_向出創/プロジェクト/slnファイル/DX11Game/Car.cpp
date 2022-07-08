//======================================================================================
// 車処理
// 制作：向出創
//======================================================================================
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Car.h"
#include "Shadow.h"
#include "main.h"
#include "Player.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define MODEL_BASIC	"data/model/car/basic1.fbx"
#define MODEL_TAXI	"data/model/car/taxi1.fbx"
#define MODEL_TRACK	"data/model/car/track.fbx"
#define MODEL_RACE	"data/model/car/race1.fbx"
#define MODEL_COP	"data/model/car/cop1.fbx"

#define MAX_CAR_MODEL		(5)

#define CAR_SPEED		(1.0f)

//*****************************************************************************
// 構造体定義
//*****************************************************************************
typedef struct _tCar
{
	XMFLOAT4X4	mtxWorld;

	int	nType;	// 種類
	XMFLOAT3 pos;	// 座標
	XMFLOAT3 rot;	// 回転
	XMFLOAT3 scl;	// 拡大率
	XMFLOAT3 vel;	// 速度

	int		nState;	// 行動(0以下:未使用 1以上:通常)
	int		nShadowIdx;	// 影の番号
}tCar;

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static CAssimpModel	g_model[MAX_CAR_MODEL];	// モデルデータ
static tCar			g_car[MAX_CAR];

HRESULT LoadCar(void)
{
	HRESULT hr = S_OK;
	ID3D11Device* pDevice = GetDevice();
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// モデルデータの読み込み
	hr = g_model[0].Load(pDevice, pDeviceContext,
		MODEL_BASIC);
	hr = g_model[1].Load(pDevice, pDeviceContext,
		MODEL_TAXI);
	hr = g_model[2].Load(pDevice, pDeviceContext,
		MODEL_TRACK);
	hr = g_model[3].Load(pDevice, pDeviceContext,
		MODEL_RACE);
	hr = g_model[4].Load(pDevice, pDeviceContext,
		MODEL_COP);

	return hr;
}

//=============================================================================
// 初期化処理
//=============================================================================
void InitCar(void)
{
	// 位置・回転・スケールの初期設定
	for (int i = 0; i < MAX_CAR; i++)
	{
		g_car[i].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
		g_car[i].rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_car[i].scl = XMFLOAT3(1.0f, 1.0f, 1.0f);
		g_car[i].vel = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_car[i].nState = 0;	// 初期は存在しない
	}

	// ワールドマトリックスの初期化
	XMMATRIX mtxWorld;
	mtxWorld = XMMatrixIdentity();
	for (int i = 0; i < MAX_CAR; i++)
	{
		XMStoreFloat4x4(&g_car[i].mtxWorld, mtxWorld);
	}
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitCar(void)
{
	// 影の解放
	for (int i = 0; i < MAX_CAR; i++) {
		ReleaseShadow(g_car[i].nShadowIdx);
	}
	// モデルの解放
	//for (int i = 0; i < MAX_CAR_MODEL; i++) {
	//	g_model[i].Release();
	//}
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateCar(void)
{
	for (int i = 0; i < MAX_CAR; i++)
	{
		if (g_car[i].nState == 0)	continue;

		// モデルの動きを記述するならここ========================================

		if (g_car[i].pos.z < GetPlayerPos(0).z + 3200.0f) {

			// 位置の更新
			g_car[i].pos.x += g_car[i].vel.x;
			g_car[i].pos.y += g_car[i].vel.y;
			g_car[i].pos.z += g_car[i].vel.z;
		}

		// 画面に近づいたら消す
		if (g_car[i].pos.z < GetPlayerPos(0).z - 5000.0f) {
			DestroyCar(i);
		}

		if (g_car[i].pos.z < GetPlayerPos(0).z - 500.0f) {
			g_car[i].rot.y = 180.0f;
		}
		// ===================================================================

		// ワールドマトリックスの初期化
		XMMATRIX mtxWorld, mtxRot, mtxScl, mtxTranslate;
		mtxWorld = XMMatrixIdentity();

		// スケールを反映
		mtxScl = XMMatrixScaling(
			g_car[i].scl.x,
			g_car[i].scl.y,
			g_car[i].scl.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxScl);

		// 回転を反映
		mtxRot = XMMatrixRotationRollPitchYaw(
			XMConvertToRadians(g_car[i].rot.x),
			XMConvertToRadians(g_car[i].rot.y),
			XMConvertToRadians(g_car[i].rot.z)
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxRot);

		// 移動を反映
		mtxTranslate = XMMatrixTranslation(
			g_car[i].pos.x,
			g_car[i].pos.y,
			g_car[i].pos.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxTranslate);

		// ワールドマトリックス設定
		XMStoreFloat4x4(&g_car[i].mtxWorld, mtxWorld);

		// 影の移動
		MoveShadow(g_car[i].nShadowIdx, g_car[i].pos);
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawCar(void)
{
	for (int i = 0; i < MAX_CAR; i++)
	{
		if (g_car[i].pos.z > GetPlayerPos(0).z - 200.0f) {
			ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

			// モデル表示
			if (g_car[i].nState == 0)	continue;
			g_model[g_car[i].nType].Draw(pDeviceContext, g_car[i].mtxWorld);
		}
	}
}

// 車スポーン
int SetCar(XMFLOAT3 pos, XMFLOAT3 dir, int type)
{
	_tCar* pCar = g_car;
	for (int i = 0; i < MAX_CAR; ++i, ++pCar)
	{	// 出現している場合スルー
		if (pCar->nState != 0) continue;

		pCar->pos = pos;
		pCar->vel.x = dir.x * CAR_SPEED;
		pCar->vel.y = dir.y * CAR_SPEED;
		pCar->vel.z = dir.z * CAR_SPEED;
		pCar->nState = 1;	// 出現
		pCar->nType = type;

		// 影の作成
		pCar->nShadowIdx = CreateShadow(pCar->pos, 90.0f);

		return i;	// 番号を返す
	}
	return -1;	// 見つからなかった
}

XMFLOAT4X4 GetCarWorld(int no)
{
	return g_car[no].mtxWorld;
}

// 中心座標所得
XMFLOAT3 GetCarCenter(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	XMFLOAT3 pos = g_model[g_car[no].nType].GetCenter();
	pos.x += g_car[no].pos.x;
	pos.y += g_car[no].pos.y;
	pos.z += g_car[no].pos.z;
	return pos;
}

// モデルサイズ所得
XMFLOAT3 GetCarBBox(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	// モデルからサイズ半分を所得
	XMFLOAT3 size = g_model[g_car[no].nType].GetBBox();
	return XMFLOAT3(
		size.x * g_car[no].scl.x,
		size.y * (g_car[no].scl.y / 3.0f),
		size.z * g_car[no].scl.z);
}

// 座標所得
XMFLOAT3 GetCarPos(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_car[no].pos;
}

// サイズ所得
XMFLOAT3 GetCarSize(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_car[no].scl;
}

// 生存しているか
bool IsCar(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return false;
	}
	return true;
}

// 表示しない
void DestroyCar(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return;
	}
	g_car[no].nState = 0;
	ReleaseShadow(g_car[no].nShadowIdx);
	g_car[no].nShadowIdx = -1;
	g_car[no].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
}