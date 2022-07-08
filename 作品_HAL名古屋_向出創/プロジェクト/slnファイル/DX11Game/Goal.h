//======================================================================================
// ゴールポイント処理まとめ
// 制作：向出創
//======================================================================================
#pragma once

#include "Main.h"

// マクロ定義
#define MAX_GOAL  (1)     //弾の数


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT LoadGoal(void);
void InitGoal(void);
void UninitGoal(void);
void UpdateGoal(void);
void DrawGoal(void);

// 設置(pos = 出現位置)
int SetGoal(XMFLOAT3 pos);

XMFLOAT3 GetGoalPos(int no);
XMFLOAT3 GetGoalSize(int no);
bool	 IsGoal(int no);
void	 DestroyGoal(int no);
