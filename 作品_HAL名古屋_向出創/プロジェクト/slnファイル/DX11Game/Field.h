//======================================================================================
// �n�ʏ����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_FIELD (200)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadField(void);
void InitField(void);
void UninitField(void);
void UpdateField(void);
void DrawField(void);

XMFLOAT3 GetFieldPos(int no);
XMFLOAT3 GetFieldSize(int no);
bool IsField(int no);