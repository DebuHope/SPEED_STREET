//======================================================================================
// �󒆓G�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

// �}�N����`
#define MAX_UENEMY  (200)     //�e�̐�

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadUEnemy(void);
void InitUEnemy(void);
void UninitUEnemy(void);
void UpdateUEnemy(void);
void DrawUEnemy(void);

// �ݒu(pos = �o���ʒu, dir = �i�ޕ����̑��x, type = �����̎��)
int SetUEnemy(XMFLOAT3 pos, XMFLOAT3 dir, int type);

XMFLOAT3 GetUEnemyPos(int no);
XMFLOAT3 GetUEnemySize(int no);
bool	 IsUEnemy(int no);
void	 DestroyUEnemy(int no);

void	KillUEnemy(int no);
int		GetUEnemy(int no);