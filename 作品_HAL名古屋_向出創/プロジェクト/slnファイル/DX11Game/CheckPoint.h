//======================================================================================
// �`�F�b�N�|�C���g�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

// �}�N����`
#define MAX_CHECKPOINT  (1)     //�e�̐�


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadCheckPoint(void);
void InitCheckPoint(void);
void UninitCheckPoint(void);
void UpdateCheckPoint(void);
void DrawCheckPoint(void);
// �ݒu(pos = �o���ʒu)
int SetCheckPoint(XMFLOAT3 pos);

XMFLOAT3 GetCheckPointPos(int no);
XMFLOAT3 GetCheckPointSize(int no);
bool	 IsCheckPoint(int no);
void	 DestroyCheckPoint(int no);

bool	 GetCheckFlag(int no);
void	SetCheckFlag(int no, bool flag);
