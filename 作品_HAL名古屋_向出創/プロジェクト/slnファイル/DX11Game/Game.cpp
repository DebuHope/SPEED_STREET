//=============================================================================
// メインゲーム処理
// 制作：向出創
//=============================================================================
#include <time.h>
#include "Main.h"
#include "Game.h"
#include "Input.h"
#include "Bg.h"
#include "Street.h"
#include "Field.h"
#include "Player.h"
#include "Object.h"
#include "DEnemy.h"
#include "UEnemy.h"
#include "Car.h"
#include "Hole.h"
#include "Hint.h"
#include "EF_Acceleration.h"
#include "Transition.h"
#include "Shadow.h"
#include "Life.h"
#include "UI.h"
#include "Score.h"
#include "Item.h"
#include "PlayerIcon.h"
#include "CheckPoint.h"
#include "Goal.h"
#include "Stage.h"
#include "EF_Maneger.h"
#include "Sound.h"
#include "Combo.h"
#include "Gauge.h"
#include "Endroll.h"

//*****************************************************************************
// グローバル変数
//*****************************************************************************
static int	state;	// tips情報
static bool	stateFlag;

//=============================================================================
// 初期化処理
//=============================================================================
void InitGame()
{
	// 加速エフェクト
	InitAcceleration();
	// Effekseerエフェクト初期化
	InitEFManeger();
	// 背景
	InitBg();
	// ライフ
	InitLife();
	// 道路
	InitStreet();
	// フィールド
	InitField();
	// プレイヤー
	InitPlayer();
	// 地上敵
	InitDEnemy();
	// 空中敵
	InitUEnemy();
	// 車
	InitCar();
	// 穴
	InitHole();
	// オブジェクト
	InitObject();
	// エンドロール
	InitText();
	// 道路ヒント
	InitHint();
	// チェックポイント
	InitCheckPoint();
	// ゴール
	InitGoal();
	// スコア
	InitScore();
	// アイテム
	InitItem();
	// プレイヤーアイコン
	InitPlayerIcon();
	// UI
	InitUI();
	// コンボ
	InitCombo();
	AddCountCombo(-999);

	state = 0;
	stateFlag = false;

	SetDrawTexNo(UI_UE_UI);

	SetStage();
}

//=============================================================================
// 終了処理
//=============================================================================
void UninitGame()
{
	// 加速エフェクト
	UninitAcceleration();
	// 背景
	UninitBg();
	// ライフ
	UninitLife();
	// 道路
	UninitStreet();
	// フィールド
	UninitField();
	// プレイヤー
	UninitPlayer();
	// オブジェクト
	UninitObject();
	// エンドロール
	UninitText();
	// 車
	UninitCar();
	// 穴
	UninitHole();
	// エネミー
	UninitDEnemy();
	UninitUEnemy();
	// 道路ヒント
	UninitHint();
	// スコア
	UninitScore();
	// アイテム
	UninitItem();
	// プレイヤーアイコン
	UninitPlayerIcon();
	// チェックポイント
	UninitCheckPoint();
	// ゴール
	UninitGoal();
	// UI
	UninitUI();
	// コンボ
	UninitCombo();
}

//=============================================================================
// 更新処理
//=============================================================================
void UpdateGame()
{
	if (state == 0) {
		// 加速エフェクト
		UpdateAcceleration();
		// Effekseerエフェクト
		UpdateEFManeger();
		// 背景
		UpdateBg();
		// ライフ
		UpdateLife();
		// 道路
		UpdateStreet();
		// フィールド
		UpdateField();
		// プレイヤー
		UpdatePlayer();
		// エネミー
		UpdateDEnemy();
		UpdateUEnemy();
		// 車
		UpdateCar();
		// 穴
		UpdateHole();
		// オブジェクト
		UpdateObject();
		// エンドロール
		UpdateText();
		// 道路ヒント
		UpdateHint();
		// スコア
		UpdateScore();
		// アイテム
		UpdateItem();
		// プレイヤーアイコン
		UpdatePlayerIcon();
		// チェックポイント
		UpdateCheckPoint();
		// ゴール
		UpdateGoal();
		// コンボ
		UpdateCombo();
	}
	// UI
	UpdateUI();

	// ヒント
	SetStageHint();

	// ポーズ切り替え
	if (GetKeyTrigger(VK_ESCAPE) || GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON8)){
		if (state == 0) state = 1;
		StopSound(SOUND_LABEL_SE_RUN);
	}

	// tips表示
	if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 800.0f && GetPlayerPos(0).z <= 850.0f && stateFlag == false) {
		if (state == 0) state = 2;
		stateFlag = true;
		StopSound(SOUND_LABEL_SE_RUN);
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 9000.0f && GetPlayerPos(0).z <= 9550.0f && stateFlag == false) {
		if (state == 0) state = 3;
		stateFlag = true;
		StopSound(SOUND_LABEL_SE_RUN);
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 18000.0f && GetPlayerPos(0).z <= 18050.0f && stateFlag == false) {
		if (state == 0) state = 4;
		stateFlag = true;
		StopSound(SOUND_LABEL_SE_RUN);
	}

	// tipsフラグ回収
	if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 860.0f && GetPlayerPos(0).z <= 900.0f) {
		stateFlag = false;
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 9560.0f && GetPlayerPos(0).z <= 9600.0f) {
		stateFlag = false;
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 18600.0f && GetPlayerPos(0).z <= 18700.0f) {
		stateFlag = false;
	}

	// 3-2 後ろから車
	if (GetSceneNo() == SCENE_STAGE3_2) {
		if (GetPlayerPos(0).z >= 2000.0f && GetPlayerPos(0).z <= 2050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(-50.0f, 0.0f, 1000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 6000.0f && GetPlayerPos(0).z <= 6050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 10000.0f && GetPlayerPos(0).z <= 10050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 14000.0f && GetPlayerPos(0).z <= 14050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(-50.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 18000.0f && GetPlayerPos(0).z <= 18050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(0.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 22000.0f && GetPlayerPos(0).z <= 22050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(0.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 26000.0f && GetPlayerPos(0).z <= 26050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 30000.0f && GetPlayerPos(0).z <= 30050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(-50.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 34000.0f && GetPlayerPos(0).z <= 34050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 38000.0f && GetPlayerPos(0).z <= 38050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}

		time_t t = time(NULL);
		t %= 7;
		if (t == 0) {
			stateFlag = false;
		}
	}

	if (GetSceneNo() == SCENE_ENDING && GetPlayerPos(0).z >= 19000.0f) {
		StartChange(SCENE_SELECT, 2);
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void DrawGame()
{
	// Zバッファ無効
	SetZBuffer(false);
	// 背景
	DrawBg();
	// Zバッファ有効
	SetZBuffer(true);
	// フィールド
	DrawField();
	// 道路
	DrawStreet();
	// 道路ヒント
	DrawHint();
	// プレイヤー
	DrawPlayer();
	// エネミー
	DrawDEnemy();
	DrawUEnemy();
	// オブジェクト
	DrawObject();
	// 車
	DrawCar();
	// エンドロール
	DrawTex();
	// 穴
	DrawHole();
	// アイテム
	DrawItem();
	// チェックポイント
	DrawCheckPoint();
	// ゴール
	DrawGoal();
	// Effekseerエフェクト
	DrawEFManeger();

	SetZWrite(false);	// 影設定変更影を綺麗に
	DrawShadow();
	SetZWrite(true);
	// Zバッファ有効
	SetZBuffer(false);
	SetBlendState(BS_ALPHABLEND);
	if (GetSceneNo() != SCENE_ENDING) {
		// 加速エフェクト
		DrawAcceleration();
		if (state == 1 || state != 2) {	// ポーズ時
			DrawCombo();
			DrawLife();
		}
		if (GetPlayerDashCount() <= 1.0f)	DrawGaugeX(XMFLOAT2(-75.0f, -200.0f), XMFLOAT2(150.0f, 15.0f), GetPlayerDashCount(), 0);
		if (GetPlayerJumpCount() <= 1.0f)	DrawGaugeY1(XMFLOAT2(-150.0f, -130.0f), XMFLOAT2(15.0f, 150.0f), GetPlayerJumpCount(), 1);
		if (GetPlayerSlide() <= 1.0f)	DrawGaugeY2(XMFLOAT2(150.0f, -130.0f), XMFLOAT2(15.0f, 150.0f), GetPlayerSlide(), 2);
	}
	DrawUI();
	if (GetSceneNo() != SCENE_ENDING) {
		if (state == 2) {	// tips時
			DrawCombo();
			DrawLife();
		}
		DrawScore();
		DrawPlayerIcon();
	}
	DrawTransition();
	SetBlendState(BS_NONE);
	// Zバッファ有効
	SetZBuffer(true);
}

int GetState()
{
	return state;
}

void SetState(int no)
{
	state = no;
}