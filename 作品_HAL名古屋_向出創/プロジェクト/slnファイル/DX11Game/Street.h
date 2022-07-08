//======================================================================================
// �������܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_STREET (230)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadStreet(void);
void InitStreet(void);
void UninitStreet(void);
void UpdateStreet(void);
void DrawStreet(void);

XMFLOAT3 GetStreetPos(int no);
XMFLOAT3 GetStreetSize(int no);
bool IsStreet(int no);