//======================================================================================
// �X�R�A�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include"main.h"

// �}�N����`
#define MAX_SCORE	(3)	// �ő�e��

// �v���g�^�C�v�錾
void	InitScore();	// ������
void	UninitScore();	// �I��
void	UpdateScore();	// �X�V
void	DrawScore();	// �`��

void	AddCountItem(int num);		// �A�C�e���J�E���g
void	AddCountCombo(int num);		// �R���{�J�E���g
void	AddCountKill(int num);		// ���j�J�E���g
int		GetScore(int no);
int		GetScore2(int no1, int no2);
void	SetBeforeScore();
int		GetComboCount();
void	SetComboCount();
bool	GetSPStateS();
bool	GetSPStateF();
bool	GetSPStateN();