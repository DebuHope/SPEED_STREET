//======================================================================================
// 背景処理まとめ
// 制作：向出創
//======================================================================================
#pragma once	//ヘッダファイルを一回だけ読み込んでビルド時間短縮する

//ヘッダファイルのインクルード
#include"main.h"

//プロトタイプ宣言
HRESULT LoadBg();	//初期化
void	InitBg();	//初期化
void	UninitBg();	//終了
void	UpdateBg();	//更新
void	DrawBg();	//描画