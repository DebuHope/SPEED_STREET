//======================================================================================
// �V�[���J�ڏ����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

//�w�b�_�t�@�C���̃C���N���[�h
#include"main.h"

//�v���g�^�C�v�錾
HRESULT LoadTransition();	//������
void	InitTransition();	//������
void	UninitTransition();	//�I��
void	UpdateTransition();	//�X�V
void	DrawTransition();	//�`��

void	StartChange(ETypeScene nextscene, int no);		// �V�[���؂�ւ�