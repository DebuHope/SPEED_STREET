//======================================================================================
// UI�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

//�w�b�_�t�@�C���̃C���N���[�h
#include"main.h"

enum UIType {
	UI_TITLE_PRINT,
	UI_MAINSELECT,
	UI_STAGESELECT,
	UI_STAGESTREET,
	UI_OPTIONSELECT,
	UI_MANUAL,
	UI_KETTEIMODORU1,
	UI_KETTEIMODORU2,
	UI_NOWSELECT1,
	UI_NOWSELECT2,
	UI_LIFE1,
	UI_LIFE2,
	UI_UE_UI,
	UI_PAUSE,
	UI_PAUSEBACK,
	UI_TIPAS1,
	UI_TIPAS2,
	UI_TIPAS3,
	UI_STREETFIRE,
	UI_RESULT,
	UI_DANGER,
	UI_1_4,
	UI_STAGEFOREST,
	UI_2_4,
	UI_FORESTFIRE,
	UI_STAGENIGHT,
	UI_3_4,
	UI_NIGHTFIRE,
	UI_MANUAL2,

	MAX_UI_TYPE
};

//�v���g�^�C�v�錾
HRESULT LoadUI();	//������
void	InitUI();	//������
void	UninitUI();	//�I��
void	UpdateUI();	//�X�V
void	DrawUI();	//�`��

UIType	GetDrawTexNo();
void	SetDrawTexNo(UIType type);

XMFLOAT3 GetUIPos(int no);
int		GetUIState();