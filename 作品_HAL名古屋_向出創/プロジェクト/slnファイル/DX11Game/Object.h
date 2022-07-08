//======================================================================================
// ���������܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

#define MAX_OBJECT		(40)

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT		LoadObject(void);
void		InitObject(void);
void		UninitObject(void);
void		UpdateObject(void);
void		DrawObject(void);

// �ݒu(pos = �o���ʒu, rot = ����)
void		SetSign(XMFLOAT3 pos, XMFLOAT3 rot);

XMFLOAT3	GetObjectPos(int no); 
XMFLOAT3	GetObjectRot(int no);
