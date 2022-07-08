//======================================================================================
// �n��G�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "Main.h"

// �}�N����`
#define MAX_DENEMY  (200)     //�e�̐�

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT LoadDEnemy(void);
void InitDEnemy(void);
void UninitDEnemy(void);
void UpdateDEnemy(void);
void DrawDEnemy(void);

// �ݒu(pos = �o���ʒu, dir = �i�ޕ����̑��x, type = �����̎��)
int SetDEnemy(XMFLOAT3 pos, XMFLOAT3 dir, int type);

XMFLOAT3 GetDEnemyPos(int no);
XMFLOAT3 GetDEnemySize(int no);
bool	 IsDEnemy(int no);
void	 DestroyDEnemy(int no);

void	KillDEnemy(int no);

int		GetDEnemy(int no);