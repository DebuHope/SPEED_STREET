//======================================================================================
// �e�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadShadow(void);
void InitShadow(void);
void UninitShadow(void);
void UpdateShadow(void);
void DrawShadow(void);

int CreateShadow(XMFLOAT3 pos, float radius);
void MoveShadow(int nShadow, XMFLOAT3 pos);
void ReleaseShadow(int nShadow);