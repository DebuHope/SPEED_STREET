//======================================================================================
// �q���g�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_HINT (25)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadHint(void);
void InitHint(void);
void UninitHint(void);
void UpdateHint(void);
void DrawHint(void);

// �ݒu(drawno = �q���g�̎��)
int SetHint(int drawno);

XMFLOAT3 GetHintPos(int no);
XMFLOAT3 GetHintSize(int no);
bool IsHint(int no);

