//======================================================================================
// ヒント処理まとめ
// 制作：向出創
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_HINT (25)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT LoadHint(void);
void InitHint(void);
void UninitHint(void);
void UpdateHint(void);
void DrawHint(void);

// 設置(drawno = ヒントの種類)
int SetHint(int drawno);

XMFLOAT3 GetHintPos(int no);
XMFLOAT3 GetHintSize(int no);
bool IsHint(int no);

