//======================================================================================
// 車処理まとめ
// 制作：向出創
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_CAR		(100)

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT LoadCar(void);
void InitCar(void);
void UninitCar(void);
void UpdateCar(void);
void DrawCar(void);

// 設置(pos = 出現位置, dir = 進む方向の速度, type = モデルの種類)
int SetCar(XMFLOAT3 pos, XMFLOAT3 dir, int type);

XMFLOAT4X4 GetCarWorld(int no);
XMFLOAT3 GetCarCenter(int no);
XMFLOAT3 GetCarBBox(int no);

XMFLOAT3 GetCarPos(int no);
XMFLOAT3 GetCarSize(int no);
bool IsCar(int no);
void DestroyCar(int no);