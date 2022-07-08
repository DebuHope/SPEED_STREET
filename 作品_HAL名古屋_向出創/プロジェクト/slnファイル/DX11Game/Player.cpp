//=============================================================================
// プレイヤー処理
// 制作：向出創
//=============================================================================
#include <math.h>
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Player.h"
#include "Shadow.h"
#include "main.h"
#include "Camera.h"
#include "input.h"
#include "UI.h"
#include "Transition.h"
#include "Life.h"
#include "CheckPoint.h"
#include "Sound.h"
#include "Score.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define MODEL_RUN		"data/model/player/running.fbx"
#define MODEL_FASTRUN	"data/model/player/fastrun.fbx"
#define MODEL_BREAK		"data/model/player/break.fbx"
#define MODEL_JUMP		"data/model/player/jump.fbx"
#define MODEL_SLIDE		"data/model/player/slide.fbx"
#define MODEL_WDOWN		"data/model/player/fall.fbx"
#define MODEL_SDOWN		"data/model/player/stunned.fbx"
#define MODEL_FALL		"data/model/player/falling.fbx"
#define MODEL_SITTING	"data/model/player/sitting.fbx"

#define MAX_PLAYER_MODEL	(11)

#define ROT_Y			(180.0f)
#define VALUE_MOVE		(4.0f)
#define VALUE_ROTATE	(5.0f)
#define GRAVITY			(-0.50f)

//*****************************************************************************
// 構造体定義
//*****************************************************************************
typedef struct _tPlayer
{
	XMFLOAT4X4	mtxWorld;

	XMFLOAT3 pos;	// 座標
	XMFLOAT3 rot;	// 回転
	XMFLOAT3 scl;	// 拡大率
	XMFLOAT3 vel;	// 速度
	XMFLOAT2 velXZ;	// 前移動用速度

	int		nPhase;	// 行動パターンの段階
	int		nState;	// 行動(0以下:未使用 1以上:通常)
	int		nShadowIdx;	// 影の番号
}tPlayer;

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static CAssimpModel	g_model[MAX_PLAYER_MODEL];	// モデルデータ
static tPlayer		g_player[MAX_PLAYER];	// プレイヤー数
static PlayerPhose DrawModelNo;	// 表示するモデル
static int AnimCount;
static int DashCount;
static int SlideCount;
static int JumpCount;
static int JoyZCount;
static int InvincibleCount;
static int StartInvincibleCount;
static bool DownFlag;
static bool JoyTriggerFalg;

HRESULT LoadPlayer(void)
{
	HRESULT hr = S_OK;
	ID3D11Device* pDevice = GetDevice();
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// モデルデータの読み込み
	hr = g_model[RUN].Load(pDevice, pDeviceContext,
		MODEL_RUN);
	hr = g_model[DASH].Load(pDevice, pDeviceContext,
		MODEL_FASTRUN);
	hr = g_model[BREAK].Load(pDevice, pDeviceContext,
		MODEL_BREAK);
	hr = g_model[JUMP].Load(pDevice, pDeviceContext,
		MODEL_JUMP);
	hr = g_model[SLIDE].Load(pDevice, pDeviceContext,
		MODEL_SLIDE);
	hr = g_model[WDOWN].Load(pDevice, pDeviceContext,
		MODEL_WDOWN);
	hr = g_model[SDOWN].Load(pDevice, pDeviceContext,
		MODEL_SDOWN);
	hr = g_model[FALL].Load(pDevice, pDeviceContext,
		MODEL_FALL);
	hr = g_model[SITTING].Load(pDevice, pDeviceContext,
		MODEL_SITTING);

	return hr;
}

//=============================================================================
// 初期化処理
//=============================================================================
void InitPlayer(void)
{
	// 位置・回転・スケールの初期設定
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		g_player[i].pos = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_player[i].rot = XMFLOAT3(0.0f, ROT_Y, 0.0f);
		g_player[i].scl = XMFLOAT3(4.0f, 4.0f, 4.0f);
		g_player[i].vel = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_player[i].velXZ = XMFLOAT2(0.0f, 0.0f);
		g_player[i].nPhase = 0;
		g_player[i].nState = 1;	// プレイヤー初期は生存

		if (GetCheckFlag(0))				g_player[i].pos = GetCheckPointPos(0);

		if(GetSceneNo() == SCENE_ENDING)	g_player[i].pos = XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	DrawModelNo = RUN;
	AnimCount = 0;
	DashCount = 120;
	SlideCount = 40;
	JumpCount = 40;
	JoyZCount = 0;
	InvincibleCount = 0;
	StartInvincibleCount = 0;
	DownFlag = false;
	JoyTriggerFalg = false;

	// ワールドマトリックスの初期化
	XMMATRIX mtxWorld;
	mtxWorld = XMMatrixIdentity();
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		XMStoreFloat4x4(&g_player[i].mtxWorld, mtxWorld);
	}

	// 影の作成
	for (int i = 0; i < MAX_PLAYER; i++) {
		g_player[i].nShadowIdx = CreateShadow(g_player[i].pos, 20.0f);
	}


	if (GetSceneNo() != SCENE_TITLE && DrawModelNo == RUN) {
		PlaySound(SOUND_LABEL_SE_RUN);
	}
}


//=============================================================================
// 終了処理
//=============================================================================
void UninitPlayer(void)
{
	// 影の解放
	for (int i = 0; i < MAX_PLAYER; i++) {
		ReleaseShadow(g_player[i].nShadowIdx);
	}
	// モデルの解放
	//for (int i = 0; i < MAX_PLAYER_MODEL; i++) {
	//	g_model[i].Release();
	//}
	StopSound(SOUND_LABEL_SE_RUN);
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdatePlayer(void)
{
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		if (g_player[i].nState == 0)	continue;

		// モデルの動きを記述するならここ====================================================

		if (GetDrawTexNo() == UI_MANUAL || GetSceneNo() == SCENE_STAGE1_1 || GetSceneNo() == SCENE_STAGE1_2
			|| GetSceneNo() == SCENE_STAGE1_3 || GetSceneNo() == SCENE_STAGE1_4 || GetSceneNo() == SCENE_STAGE2_1
			|| GetSceneNo() == SCENE_STAGE2_2 || GetSceneNo() == SCENE_STAGE2_3 || GetSceneNo() == SCENE_STAGE2_4
			|| GetSceneNo() == SCENE_STAGE3_1 || GetSceneNo() == SCENE_STAGE3_2 || GetSceneNo() == SCENE_STAGE3_3
			|| GetSceneNo() == SCENE_STAGE3_4 || GetSceneNo() == SCENE_ENDING) {
			// 向いている方向に移動
			if (GetSceneNo() != SCENE_ENDING) {
				if (GetKeyPress(VK_A) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 22500 && GetJoyPOV(0) <= 31500) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) < -30000) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// ブレーキ時
						g_player[i].vel.x = -VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// ダッシュ時
						g_player[i].vel.x = -VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = -VALUE_MOVE;
					}
					// 滑らかに方向転換
					if (g_player[i].rot.y > ROT_Y - 20.0f) {
						g_player[i].rot.y -= 5.0f;
					}
				}
				else if (GetKeyPress(VK_D) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 4500 && GetJoyPOV(0) <= 13500) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) > 30000) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// スライディング時
						g_player[i].vel.x = VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// ダッシュ時
						g_player[i].vel.x = VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = VALUE_MOVE;
					}
					// 滑らかに方向転換
					if (g_player[i].rot.y < ROT_Y + 20.0f) {
						g_player[i].rot.y += 5.0f;
					}
				}
				else {
					// 常に前を向かせる
					if (g_player[i].rot.y < ROT_Y) {
						// 滑らかに方向転換
						g_player[i].rot.y += 5.0f;
					}
					else if (g_player[i].rot.y > ROT_Y) {
						g_player[i].rot.y -= 5.0f;
					}
				}
			}
			//　エンディング
			else{
				if (GetKeyPress(VK_D) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 22500 && GetJoyPOV(0) <= 31500) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) < -30000) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// ブレーキ時
						g_player[i].vel.x = -VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// ダッシュ時
						g_player[i].vel.x = -VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = -VALUE_MOVE;
					}
					// 滑らかに方向転換
					if (g_player[i].rot.y > ROT_Y - 20.0f) {
						g_player[i].rot.y -= 5.0f;
					}
				}
				else if (GetKeyPress(VK_A) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 4500 && GetJoyPOV(0) <= 13500) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) > 30000) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// スライディング時
						g_player[i].vel.x = VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// ダッシュ時
						g_player[i].vel.x = VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = VALUE_MOVE;
					}
					// 滑らかに方向転換
					if (g_player[i].rot.y < ROT_Y + 20.0f) {
						g_player[i].rot.y += 5.0f;
					}
				}
				else {
					// 常に前を向かせる
					if (g_player[i].rot.y < ROT_Y) {
						// 滑らかに方向転換
						g_player[i].rot.y += 5.0f;
					}
					else if (g_player[i].rot.y > ROT_Y) {
						g_player[i].rot.y -= 5.0f;
					}
				}
			}

			// ダッシュ
			if (GetKeyTrigger(VK_W) && DrawModelNo == RUN && DashCount > 120 && GetSceneNo() != SCENE_STAGE1_4||
				JoyZCount >= 1 && JoyZCount <= 110 && DrawModelNo == RUN && DashCount > 120 && GetSceneNo() != SCENE_STAGE1_4) {
				AnimCount = 0;
				DashCount = 0;
				DrawModelNo = DASH;
				g_player[i].rot.x = -20.0f;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_DASH);
			}
			// ブレーキ
			if (GetKeyTrigger(VK_S) && DrawModelNo == RUN && GetSceneNo() != SCENE_STAGE1_4||
				JoyZCount <= -1 && JoyZCount >= -30 && DrawModelNo == RUN && GetSceneNo() != SCENE_STAGE1_4) {
				AnimCount = 0;
				DrawModelNo = BREAK;
				g_player[i].vel.z = 8.0f;
				g_player[i].rot.x = 0.0f;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_SLIDE);
			}
			// ジャンプ
			if (GetKeyTrigger(VK_K) && DrawModelNo == RUN && DrawModelNo != FALL && JumpCount > 40 ||
				GetKeyTrigger(VK_K) && DrawModelNo == DASH && DrawModelNo != FALL && JumpCount > 40 ||
				GetKeyTrigger(VK_K) && DrawModelNo == SLIDE && DrawModelNo != FALL && JumpCount > 40 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON1) && DrawModelNo == RUN && DrawModelNo != FALL && JumpCount > 40 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON1) && DrawModelNo == DASH && DrawModelNo != FALL && JumpCount > 40 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON1) && DrawModelNo == SLIDE && DrawModelNo != FALL && JumpCount > 40)
			{
				DrawModelNo = JUMP;
				g_player[i].vel.y += 8.0f;
				g_player[i].rot.x = 0.0f;
				JumpCount = 0;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_JUMP);
			}
			// スライディング
			if (GetKeyTrigger(VK_L) && DrawModelNo == RUN && SlideCount > 50 ||
				GetKeyTrigger(VK_L) && DrawModelNo == DASH && SlideCount > 50 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON2) && DrawModelNo == RUN && SlideCount > 50 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON2) && DrawModelNo == DASH && SlideCount > 50)
			{
				AnimCount = 0;
				SlideCount = 0;
				DrawModelNo = SLIDE;
				g_player[i].rot.x = 15.0f;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_SLIDE);
			}
		}// タイトル時
		else if (GetSceneNo() == SCENE_TITLE) {
			g_player[i].pos = XMFLOAT3(-66.0f, 0.0f, 300.0f);
			//g_player[i].pos = XMFLOAT3(0.0f, 0.0f, 300.0f);
			g_player[i].rot.y = 0.0f;
		}
		// 常に前移動
		if (DrawModelNo == RUN) {	// 通常時
			g_player[i].vel.z = 8.0f;
			if (GetSceneNo() == SCENE_STAGE1_4) {
				g_player[i].vel.z = 25.0f;
			}
			if (GetSceneNo() == SCENE_ENDING) {
				g_player[i].vel.z = 5.0f;
			}
		}
		else if (DrawModelNo == DASH) {	// ダッシュ時
			g_player[i].vel.z = 22.0f;
		}
		else if (DrawModelNo == BREAK) {	// ブレーキ時
			g_player[i].vel.z -= 0.25f;	// だんだん減速
			if (g_player[i].vel.z <= 0) {	// スピードが０になったらRUNに戻す
				DrawModelNo = RUN;
				PlaySound(SOUND_LABEL_SE_RUN);
			}
		}
		else if (DrawModelNo == SDOWN) {	// ダウン時
			g_player[i].vel.z += 0.2f;
			if (g_player[i].vel.z >= 0) {	// スピードが０になったら０のまま
				g_player[i].vel.z = 0.0f;
			}
		}
		else if (DrawModelNo == WDOWN) {	// ダウン時
			g_player[i].vel.z -= 0.2f;
			if (g_player[i].vel.z <= 0) {	// スピードが０になったら０のまま
				g_player[i].vel.z = 0.0f;
			}
		}

		// 重力を座標に加算
		g_player[i].vel.y += GRAVITY;

		// 速度を座標に加算
		g_player[i].pos.x += g_player[i].vel.x;
		g_player[i].pos.y += g_player[i].vel.y;
		g_player[i].pos.z += g_player[i].vel.z;

		// 初期化(キーを押していない間)
		g_player[i].vel.x = 0.0f;

		// 着地判定
		if (DrawModelNo != FALL && g_player[i].pos.y <= 0.0f)
		{
			if (DrawModelNo == JUMP) {
				PlaySound(SOUND_LABEL_SE_RUN);
				DrawModelNo = RUN;
			}
			g_player[i].vel.y = 0.0f;
			g_player[i].pos.y = 0.0f;
		}

		//================================================================
		XMMATRIX mtxWorld, mtxRot, mtxScl, mtxTranslate;

		// ワールドマトリックスの初期化
		mtxWorld = XMMatrixIdentity();

		// スケールを反映
		mtxScl = XMMatrixScaling(
			g_player[i].scl.x,
			g_player[i].scl.y,
			g_player[i].scl.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxScl);

		// 回転を反映
		mtxRot = XMMatrixRotationRollPitchYaw(
			XMConvertToRadians(g_player[i].rot.x),
			XMConvertToRadians(g_player[i].rot.y),
			XMConvertToRadians(g_player[i].rot.z)
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxRot);

		// 移動を反映
		mtxTranslate = XMMatrixTranslation(
			g_player[i].pos.x,
			g_player[i].pos.y,
			g_player[i].pos.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxTranslate);

		// ワールドマトリックス設定
		XMStoreFloat4x4(&g_player[i].mtxWorld, mtxWorld);

		// 影の移動
		MoveShadow(g_player[i].nShadowIdx, g_player[i].pos);

		// カメラ設定
		if (GetSceneNo() != SCENE_SELECT && GetSceneNo() != SCENE_TITLE && GetSceneNo() != SCENE_ENDING) {

			if (DrawModelNo != FALL) {	// 通常時
				// カメラターゲット設定
				GetCamera()->SetTarget(
					g_player[0].pos.x,
					g_player[0].pos.y + 15.0f,
					g_player[0].pos.z + 50.0f);
				// カメラ座標設定
				GetCamera()->SetPos(
					g_player[0].pos.x,
					65.0f + g_player[0].pos.y / 10.0f,
					g_player[0].pos.z - 130.0f);
			}
			else if (DrawModelNo == FALL) {	// 落下時
				// カメラターゲット設定
				GetCamera()->SetTarget(
					g_player[0].pos.x,
					g_player[0].pos.y + 15.0f,
					g_player[0].pos.z + 50.0f);
				// カメラ座標設定
				GetCamera()->SetPos(
					g_player[0].pos.x,
					65.0f + g_player[0].pos.y / 1.5f,
					g_player[0].pos.z - 130.0f);
			}
		}
		// エンディング
		else if (GetSceneNo() == SCENE_ENDING) {
			// カメラターゲット設定
			GetCamera()->SetTarget(
				0.0f,
				30.0f,
				g_player[0].pos.z + 50.0f);
			// カメラ座標設定
			GetCamera()->SetPos(
				0.0f,
				70.0f,
				g_player[0].pos.z + 450.0f);
		}
		else {
			// カメラターゲット設定
			GetCamera()->SetTarget(
				-50.0f,
				g_player[0].pos.y + 15.0f,
				g_player[0].pos.z + 50.0f);
			// カメラ座標設定
			GetCamera()->SetPos(
				10.0f,
				65.0f + g_player[0].pos.y / 10.0f,
				g_player[0].pos.z - 130.0f);
		}


		// ゲームオーバー
		if (RemainingLife(0) <= 0 && AnimCount >= 50) {
			StartChange(GetSceneNo(), 1);
		}
		if (g_player[i].pos.y < -1500.0f && DrawModelNo == FALL) {
			StartChange(GetSceneNo(), 1);
		}
	}

	// 一定時間経過でモデルを戻す
	if (DrawModelNo == SLIDE && AnimCount > 33) {	// スライド時
		DrawModelNo = RUN;
		g_player[0].rot.x = 0.0f;
		PlaySound(SOUND_LABEL_SE_RUN);
	}
	else if (DrawModelNo == DASH && AnimCount > 60) {	// ダッシュ時
		DrawModelNo = RUN;
		g_player[0].rot.x = 0.0f;
		PlaySound(SOUND_LABEL_SE_RUN);
	}
	else if (DrawModelNo == WDOWN && AnimCount > 70 ||
			 DrawModelNo == SDOWN && AnimCount > 70) {	// ダウン時
		DrawModelNo = RUN;
		g_player[0].rot.x = 0.0f;
		PlaySound(SOUND_LABEL_SE_RUN);
	}

	AnimCount++;
	DashCount++;
	SlideCount++;
	JumpCount++;
	StartInvincibleCount++;

	// パッドZ軸フラグ
	if (GetJoyCountSimple() == 1 && (GetJoyZ(0) < -20000)) {
		JoyZCount++;
	}
	else if (GetJoyCountSimple() == 1 && (GetJoyZ(0) > 20000)) {
		JoyZCount--;
	}
	else {
		JoyZCount = 0;
	}

	if(DownFlag) InvincibleCount++;
	if (InvincibleCount > 150) DownFlag = false;

	////  ストリート
	//if (GetUIState() == 0) {
	//	g_player[0].scl = XMFLOAT3(4.0f, 4.0f, 4.0f);
	//	DrawModelNo = RUN;
	//}
	////  フォレスト
	//if (GetUIState() == 1) {
	//	g_player[0].scl = XMFLOAT3(0.3f, 0.3f, 0.3f);
	//	DrawModelNo = RUN2;
	//}
	////  ナイトストリート
	//if (GetUIState() == 2) {
	//	g_player[0].scl = XMFLOAT3(0.3f, 0.3f, 0.3f);
	//	DrawModelNo = RUN3;
	//}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawPlayer(void)
{
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

		if (InvincibleCount < 70 || InvincibleCount > 150 || GetSceneNo() == SCENE_TITLE) {

			g_model[DrawModelNo].Draw(pDeviceContext, g_player[i].mtxWorld);
		}
		else if (DownFlag && InvincibleCount > 70 && (DashCount % 5) == 1) {
			// モデル表示
			g_model[DrawModelNo].Draw(pDeviceContext, g_player[i].mtxWorld);
		}
	}
}

XMFLOAT4X4 GetPlayerWorld(int no)
{
	return g_player[no].mtxWorld;
}

// 中心座標所得
XMFLOAT3 GetPlayerCenter(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	XMFLOAT3 pos = g_model[DrawModelNo].GetCenter();
	pos.x += g_player[no].pos.x;
	pos.y += g_player[no].pos.y;
	pos.z += g_player[no].pos.z;
	return pos;
}

// モデルサイズ所得
XMFLOAT3 GetPlayerBBox(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	// モデルからサイズ半分を所得
	XMFLOAT3 size = g_model[DrawModelNo].GetBBox();
	return XMFLOAT3(
		size.x * g_player[no].scl.x,
		size.y * g_player[no].scl.y,
		size.z * g_player[no].scl.z);
}

// 座標所得
XMFLOAT3 GetPlayerPos(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_player[no].pos;
}

// サイズ所得
XMFLOAT3 GetPlayerSize(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_player[no].scl;
}

// 生存しているか
bool IsPlayer(int no)
{
	if (no < 0 || no >= MAX_PLAYER || DrawModelNo != SDOWN && DownFlag || StartInvincibleCount <= 50) {
		return false;
	}
	return true;
}

// 表示しない
void DestroyPlayer(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return;
	}
	g_player[no].nState = 0;
	ReleaseShadow(g_player[no].nShadowIdx);
	g_player[no].nShadowIdx = -1;
}

// モデル情報所得
PlayerPhose GetPlayerPhose(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return RUN;
	}

	return DrawModelNo;
}

// ダウンモデル変更
void PlayerPhoseChange(int no, PlayerPhose phose)
{
	if (no < 0 || no >= MAX_PLAYER) return;

	if (DrawModelNo != SDOWN && DrawModelNo != WDOWN && phose != FALL &&
		g_player[no].pos.y <= 0.0f) {
		g_player[no].vel.y += 7.0f;
	}
	// モデルによって移動量を変える
	if (phose == SDOWN) {
		g_player[no].vel.z = -10.0f;
	}
	else if (phose == WDOWN) {
		g_player[no].vel.z = 8.0f;
	}
	g_player[no].rot.x = 0.0f;
	AnimCount = 0;
	InvincibleCount = 0;
	DrawModelNo = phose;
	
	DownFlag = true;
}

// 速度所得
XMFLOAT3 GetPlayerVel(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_player[no].vel;
}

float GetPlayerDashCount()
{
	return (float)DashCount / 120.0f;
}

float GetPlayerJumpCount()
{
	return (float)JumpCount / 40.0f;
}

float GetPlayerSlide()
{
	return (float)SlideCount / 50.0f;
}
