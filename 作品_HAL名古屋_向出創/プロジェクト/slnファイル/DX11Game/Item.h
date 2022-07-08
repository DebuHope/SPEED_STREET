//======================================================================================
// �A�C�e�������܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

// �}�N����`
#define MAX_ITEM  (300)     //�e�̐�


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadItem(void);
void InitItem(void);
void UninitItem(void);
void UpdateItem(void);
void DrawItem(void);

// �ݒu(pos = �o���ʒu, scl = �傫��)
int SetItem(XMFLOAT3 pos, int scl);

XMFLOAT3 GetItemPos(int no);
XMFLOAT3 GetItemSize(int no);
bool	 IsItem(int no);
void	 DestroyItem(int no);
