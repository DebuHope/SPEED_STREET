//======================================================================================
// ���C�t�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

// �w�b�_�t�@�C���̃C���N���[�h
#include"main.h"

// �v���g�^�C�v�錾
HRESULT LoadLife();		// ������
void	InitLife();		// ������
void	UninitLife();	// �I��
void	UpdateLife();	// �X�V
void	DrawLife();		// �`��

int		RemainingLife(int num);
int		RecoveryLife(int num);