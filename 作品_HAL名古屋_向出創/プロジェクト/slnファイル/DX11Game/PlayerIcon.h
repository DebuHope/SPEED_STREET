//======================================================================================
// �}�b�v�i�s�x�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

//�w�b�_�t�@�C���̃C���N���[�h
#include"main.h"

//�v���g�^�C�v�錾
HRESULT LoadPlayerIcon();	//������
void	InitPlayerIcon();	//������
void	UninitPlayerIcon();	//�I��
void	UpdatePlayerIcon();	//�X�V
void	DrawPlayerIcon();	//�`��

XMFLOAT3 GetPlayerIconPos();

int		GetStageProgress();