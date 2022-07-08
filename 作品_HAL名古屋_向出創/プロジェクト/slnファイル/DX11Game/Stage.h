//======================================================================================
// ステージ管理まとめ
// 制作：向出創
//======================================================================================
#pragma once

#include "Main.h"

void SetStage();
void SetStageHint();
void SetItemQuantity(int no, XMFLOAT3 pos, int type);
void SetAllEnemyType(XMFLOAT2 no/*X列,Z列*/, XMFLOAT4 no2/*敵の種類（1体目,2体目,3体目,4体目）*/, float pos/*(最初のZの位置)*/);