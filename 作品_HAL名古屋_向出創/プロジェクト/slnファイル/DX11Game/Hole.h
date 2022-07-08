//======================================================================================
// ���Ƃ��������܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_HOLE (100)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadHole(void);
void InitHole(void);
void UninitHole(void);
void UpdateHole(void);
void DrawHole(void);

// �ݒu(pos = �o���ʒu, scl = �傫��)
int SetHole(XMFLOAT3 pos, XMFLOAT3 scl);

XMFLOAT3 GetHolePos(int no);
XMFLOAT3 GetHoleSize(int no);
bool IsHole(int no);