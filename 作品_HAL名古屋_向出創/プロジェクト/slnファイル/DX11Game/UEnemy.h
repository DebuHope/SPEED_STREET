//======================================================================================
// 空中敵処理まとめ
// 制作：向出創
//======================================================================================
#pragma once

#include "Main.h"

// マクロ定義
#define MAX_UENEMY  (200)     //弾の数

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT LoadUEnemy(void);
void InitUEnemy(void);
void UninitUEnemy(void);
void UpdateUEnemy(void);
void DrawUEnemy(void);

// 設置(pos = 出現位置, dir = 進む方向の速度, type = 挙動の種類)
int SetUEnemy(XMFLOAT3 pos, XMFLOAT3 dir, int type);

XMFLOAT3 GetUEnemyPos(int no);
XMFLOAT3 GetUEnemySize(int no);
bool	 IsUEnemy(int no);
void	 DestroyUEnemy(int no);

void	KillUEnemy(int no);
int		GetUEnemy(int no);