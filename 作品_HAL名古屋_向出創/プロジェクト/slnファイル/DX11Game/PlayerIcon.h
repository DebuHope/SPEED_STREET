//======================================================================================
// マップ進行度処理まとめ
// 制作：向出創
//======================================================================================
#pragma once

//ヘッダファイルのインクルード
#include"main.h"

//プロトタイプ宣言
HRESULT LoadPlayerIcon();	//初期化
void	InitPlayerIcon();	//初期化
void	UninitPlayerIcon();	//終了
void	UpdatePlayerIcon();	//更新
void	DrawPlayerIcon();	//描画

XMFLOAT3 GetPlayerIconPos();

int		GetStageProgress();