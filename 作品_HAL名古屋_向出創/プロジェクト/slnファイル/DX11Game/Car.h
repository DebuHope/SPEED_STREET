//======================================================================================
// �ԏ����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_CAR		(100)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadCar(void);
void InitCar(void);
void UninitCar(void);
void UpdateCar(void);
void DrawCar(void);

// �ݒu(pos = �o���ʒu, dir = �i�ޕ����̑��x, type = ���f���̎��)
int SetCar(XMFLOAT3 pos, XMFLOAT3 dir, int type);

XMFLOAT4X4 GetCarWorld(int no);
XMFLOAT3 GetCarCenter(int no);
XMFLOAT3 GetCarBBox(int no);

XMFLOAT3 GetCarPos(int no);
XMFLOAT3 GetCarSize(int no);
bool IsCar(int no);
void DestroyCar(int no);