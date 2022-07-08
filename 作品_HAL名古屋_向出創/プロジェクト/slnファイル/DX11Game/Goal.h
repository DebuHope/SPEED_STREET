//======================================================================================
// �S�[���|�C���g�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

// �}�N����`
#define MAX_GOAL  (1)     //�e�̐�


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadGoal(void);
void InitGoal(void);
void UninitGoal(void);
void UpdateGoal(void);
void DrawGoal(void);

// �ݒu(pos = �o���ʒu)
int SetGoal(XMFLOAT3 pos);

XMFLOAT3 GetGoalPos(int no);
XMFLOAT3 GetGoalSize(int no);
bool	 IsGoal(int no);
void	 DestroyGoal(int no);
