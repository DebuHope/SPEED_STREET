//======================================================================================
// チェックポイント処理まとめ
// 制作：向出創
//======================================================================================
#pragma once

#include "Main.h"

// マクロ定義
#define MAX_CHECKPOINT  (1)     //弾の数


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT LoadCheckPoint(void);
void InitCheckPoint(void);
void UninitCheckPoint(void);
void UpdateCheckPoint(void);
void DrawCheckPoint(void);
// 設置(pos = 出現位置)
int SetCheckPoint(XMFLOAT3 pos);

XMFLOAT3 GetCheckPointPos(int no);
XMFLOAT3 GetCheckPointSize(int no);
bool	 IsCheckPoint(int no);
void	 DestroyCheckPoint(int no);

bool	 GetCheckFlag(int no);
void	SetCheckFlag(int no, bool flag);
