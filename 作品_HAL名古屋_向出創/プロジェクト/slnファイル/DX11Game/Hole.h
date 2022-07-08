//======================================================================================
// 落とし穴処理まとめ
// 制作：向出創
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_HOLE (100)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT LoadHole(void);
void InitHole(void);
void UninitHole(void);
void UpdateHole(void);
void DrawHole(void);

// 設置(pos = 出現位置, scl = 大きさ)
int SetHole(XMFLOAT3 pos, XMFLOAT3 scl);

XMFLOAT3 GetHolePos(int no);
XMFLOAT3 GetHoleSize(int no);
bool IsHole(int no);