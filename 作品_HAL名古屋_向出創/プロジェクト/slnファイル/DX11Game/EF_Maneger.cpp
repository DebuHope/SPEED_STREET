//======================================================================================
// エフェクト管理
// 制作：向出創
//======================================================================================
#include "EF_Maneger.h"
#include "EffekseerManeger.h"
#include "Player.h"
#include "Game.h"

//*****************************************************************************
// グローバル変数
//*****************************************************************************
EffekseerManeger*	g_effekt;
Effekseer::Handle	g_Handle;

//*****************************************************************************
// 初期化
//*****************************************************************************
void InitEFManeger()
{
	// Effekseerエフェクト
	g_effekt = new EffekseerManeger(GetDevice(), GetDeviceContext());
}

//*****************************************************************************
// 更新（管理部分）
//*****************************************************************************
void UpdateEFManeger()
{
	if (GetSceneNo() != SCENE_SELECT && GetSceneNo() != SCENE_ENDING) {
		// プレイヤーダッシュ
		if (GetPlayerPhose(0) == DASH) {

			g_effekt->setScale(g_Handle, XMFLOAT3(1.0f, 1.0f, 1.0f));
			g_Handle = g_effekt->play(0, XMFLOAT3(GetPlayerPos(0).x, 0.0f, GetPlayerPos(0).z - 300.0f));
		}
		//　プレイヤーブレーキ
		else if (GetPlayerPhose(0) == BREAK) {

			g_effekt->setScale(g_Handle, XMFLOAT3(1.0f, 1.0f, 1.0f));
			g_Handle = g_effekt->play(1, XMFLOAT3(GetPlayerPos(0).x, -10.0f, GetPlayerPos(0).z));
		}
		// プレイヤースライド
		else if (GetPlayerPhose(0) == SLIDE) {

			g_effekt->setScale(g_Handle, XMFLOAT3(1.0f, 1.0f, 1.0f));
			g_Handle = g_effekt->play(2, XMFLOAT3(GetPlayerPos(0).x, 0.0f, GetPlayerPos(0).z));
		}

		if (GetState() == 0) {
			g_effekt->update();
		}
	}
}

//*****************************************************************************
// 描画
//*****************************************************************************
void DrawEFManeger()
{
	g_effekt->Draw();
}