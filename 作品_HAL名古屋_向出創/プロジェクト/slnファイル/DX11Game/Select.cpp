//=============================================================================
// ���C�����j���[����
// ����F���o�n
//=============================================================================

#include "Main.h"
#include "Select.h"
#include "Input.h"
#include "Bg.h"
#include "Street.h"
#include "Field.h"
#include "Player.h"
#include "Object.h"
#include "DEnemy.h"
#include "UEnemy.h"
#include "Car.h"
#include "Hole.h"
#include "Hint.h"
#include "EF_Acceleration.h"
#include "UI.h"
#include "Transition.h"
#include "Shadow.h"
#include "CheckPoint.h"
#include "Score.h"

//=============================================================================
// ����������
//=============================================================================
void InitSelect()
{
	InitBg();
	InitUI();
	InitCheckPoint();
	SetCheckFlag(0, false);
	InitStreet();
	InitField();
	InitObject();
	InitPlayer();
	InitDEnemy();
	InitUEnemy();
	InitCar();
	InitHole();
	InitScore();
	InitHole();

	SetHole(XMFLOAT3(0.0f, 0.1f, 75000.0f), XMFLOAT3(1.0f, 1.0f, 1.0f));

	SetDrawTexNo(UI_MAINSELECT);
}

//=============================================================================
// �I������
//=============================================================================
void UninitSelect()
{
	UninitBg();
	UninitUI();
	UninitStreet();
	UninitField();
	UninitObject();
	UninitPlayer();
	UninitHole();
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateSelect()
{
	UpdateBg();
	UpdateUI();
	UpdateStreet();
	UpdateField();
	UpdateObject();
	UpdatePlayer();
	UpdateHole();

	if (GetPlayerPos(0).z > 80000.0f)	StartChange(SCENE_SELECT, 0);
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawSelect()
{
	// Z�o�b�t�@����
	SetZBuffer(false);
	DrawBg();
	// Z�o�b�t�@�L��
	SetZBuffer(true);
	DrawStreet();
	DrawField();
	DrawObject();
	DrawHole();
	DrawPlayer();
	SetZWrite(false);	// �e�ݒ�ύX�e���Y���
	DrawShadow();
	SetZWrite(true);
	// Z�o�b�t�@����
	SetZBuffer(false);
	SetBlendState(BS_ALPHABLEND);
	DrawUI();
	DrawTransition();
	SetBlendState(BS_NONE);
	// Z�o�b�t�@�L��
	SetZBuffer(true);
}