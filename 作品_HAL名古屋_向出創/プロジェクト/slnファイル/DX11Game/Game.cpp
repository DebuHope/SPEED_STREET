//=============================================================================
// ���C���Q�[������
// ����F���o�n
//=============================================================================
#include <time.h>
#include "Main.h"
#include "Game.h"
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
#include "Transition.h"
#include "Shadow.h"
#include "Life.h"
#include "UI.h"
#include "Score.h"
#include "Item.h"
#include "PlayerIcon.h"
#include "CheckPoint.h"
#include "Goal.h"
#include "Stage.h"
#include "EF_Maneger.h"
#include "Sound.h"
#include "Combo.h"
#include "Gauge.h"
#include "Endroll.h"

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static int	state;	// tips���
static bool	stateFlag;

//=============================================================================
// ����������
//=============================================================================
void InitGame()
{
	// �����G�t�F�N�g
	InitAcceleration();
	// Effekseer�G�t�F�N�g������
	InitEFManeger();
	// �w�i
	InitBg();
	// ���C�t
	InitLife();
	// ���H
	InitStreet();
	// �t�B�[���h
	InitField();
	// �v���C���[
	InitPlayer();
	// �n��G
	InitDEnemy();
	// �󒆓G
	InitUEnemy();
	// ��
	InitCar();
	// ��
	InitHole();
	// �I�u�W�F�N�g
	InitObject();
	// �G���h���[��
	InitText();
	// ���H�q���g
	InitHint();
	// �`�F�b�N�|�C���g
	InitCheckPoint();
	// �S�[��
	InitGoal();
	// �X�R�A
	InitScore();
	// �A�C�e��
	InitItem();
	// �v���C���[�A�C�R��
	InitPlayerIcon();
	// UI
	InitUI();
	// �R���{
	InitCombo();
	AddCountCombo(-999);

	state = 0;
	stateFlag = false;

	SetDrawTexNo(UI_UE_UI);

	SetStage();
}

//=============================================================================
// �I������
//=============================================================================
void UninitGame()
{
	// �����G�t�F�N�g
	UninitAcceleration();
	// �w�i
	UninitBg();
	// ���C�t
	UninitLife();
	// ���H
	UninitStreet();
	// �t�B�[���h
	UninitField();
	// �v���C���[
	UninitPlayer();
	// �I�u�W�F�N�g
	UninitObject();
	// �G���h���[��
	UninitText();
	// ��
	UninitCar();
	// ��
	UninitHole();
	// �G�l�~�[
	UninitDEnemy();
	UninitUEnemy();
	// ���H�q���g
	UninitHint();
	// �X�R�A
	UninitScore();
	// �A�C�e��
	UninitItem();
	// �v���C���[�A�C�R��
	UninitPlayerIcon();
	// �`�F�b�N�|�C���g
	UninitCheckPoint();
	// �S�[��
	UninitGoal();
	// UI
	UninitUI();
	// �R���{
	UninitCombo();
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateGame()
{
	if (state == 0) {
		// �����G�t�F�N�g
		UpdateAcceleration();
		// Effekseer�G�t�F�N�g
		UpdateEFManeger();
		// �w�i
		UpdateBg();
		// ���C�t
		UpdateLife();
		// ���H
		UpdateStreet();
		// �t�B�[���h
		UpdateField();
		// �v���C���[
		UpdatePlayer();
		// �G�l�~�[
		UpdateDEnemy();
		UpdateUEnemy();
		// ��
		UpdateCar();
		// ��
		UpdateHole();
		// �I�u�W�F�N�g
		UpdateObject();
		// �G���h���[��
		UpdateText();
		// ���H�q���g
		UpdateHint();
		// �X�R�A
		UpdateScore();
		// �A�C�e��
		UpdateItem();
		// �v���C���[�A�C�R��
		UpdatePlayerIcon();
		// �`�F�b�N�|�C���g
		UpdateCheckPoint();
		// �S�[��
		UpdateGoal();
		// �R���{
		UpdateCombo();
	}
	// UI
	UpdateUI();

	// �q���g
	SetStageHint();

	// �|�[�Y�؂�ւ�
	if (GetKeyTrigger(VK_ESCAPE) || GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON8)){
		if (state == 0) state = 1;
		StopSound(SOUND_LABEL_SE_RUN);
	}

	// tips�\��
	if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 800.0f && GetPlayerPos(0).z <= 850.0f && stateFlag == false) {
		if (state == 0) state = 2;
		stateFlag = true;
		StopSound(SOUND_LABEL_SE_RUN);
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 9000.0f && GetPlayerPos(0).z <= 9550.0f && stateFlag == false) {
		if (state == 0) state = 3;
		stateFlag = true;
		StopSound(SOUND_LABEL_SE_RUN);
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 18000.0f && GetPlayerPos(0).z <= 18050.0f && stateFlag == false) {
		if (state == 0) state = 4;
		stateFlag = true;
		StopSound(SOUND_LABEL_SE_RUN);
	}

	// tips�t���O���
	if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 860.0f && GetPlayerPos(0).z <= 900.0f) {
		stateFlag = false;
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 9560.0f && GetPlayerPos(0).z <= 9600.0f) {
		stateFlag = false;
	}
	else if (GetSceneNo() == SCENE_STAGE1_1 && GetPlayerPos(0).z >= 18600.0f && GetPlayerPos(0).z <= 18700.0f) {
		stateFlag = false;
	}

	// 3-2 ��납���
	if (GetSceneNo() == SCENE_STAGE3_2) {
		if (GetPlayerPos(0).z >= 2000.0f && GetPlayerPos(0).z <= 2050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(-50.0f, 0.0f, 1000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 6000.0f && GetPlayerPos(0).z <= 6050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 5000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 10000.0f && GetPlayerPos(0).z <= 10050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 9000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 14000.0f && GetPlayerPos(0).z <= 14050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(-50.0f, 0.0f, 13000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 18000.0f && GetPlayerPos(0).z <= 18050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(0.0f, 0.0f, 17000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 22000.0f && GetPlayerPos(0).z <= 22050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(0.0f, 0.0f, 21000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 26000.0f && GetPlayerPos(0).z <= 26050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 25000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 30000.0f && GetPlayerPos(0).z <= 30050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(-50.0f, 0.0f, 29000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 3);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 34000.0f && GetPlayerPos(0).z <= 34050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(0.0f, 0.0f, 33000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}
		if (GetPlayerPos(0).z >= 38000.0f && GetPlayerPos(0).z <= 38050.0f && stateFlag == false) {
			SetCar(XMFLOAT3(50.0f, 0.0f, 37000.0f), XMFLOAT3(0.0f, 0.0f, 20.0f), 4);
			stateFlag = true;
		}

		time_t t = time(NULL);
		t %= 7;
		if (t == 0) {
			stateFlag = false;
		}
	}

	if (GetSceneNo() == SCENE_ENDING && GetPlayerPos(0).z >= 19000.0f) {
		StartChange(SCENE_SELECT, 2);
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawGame()
{
	// Z�o�b�t�@����
	SetZBuffer(false);
	// �w�i
	DrawBg();
	// Z�o�b�t�@�L��
	SetZBuffer(true);
	// �t�B�[���h
	DrawField();
	// ���H
	DrawStreet();
	// ���H�q���g
	DrawHint();
	// �v���C���[
	DrawPlayer();
	// �G�l�~�[
	DrawDEnemy();
	DrawUEnemy();
	// �I�u�W�F�N�g
	DrawObject();
	// ��
	DrawCar();
	// �G���h���[��
	DrawTex();
	// ��
	DrawHole();
	// �A�C�e��
	DrawItem();
	// �`�F�b�N�|�C���g
	DrawCheckPoint();
	// �S�[��
	DrawGoal();
	// Effekseer�G�t�F�N�g
	DrawEFManeger();

	SetZWrite(false);	// �e�ݒ�ύX�e���Y���
	DrawShadow();
	SetZWrite(true);
	// Z�o�b�t�@�L��
	SetZBuffer(false);
	SetBlendState(BS_ALPHABLEND);
	if (GetSceneNo() != SCENE_ENDING) {
		// �����G�t�F�N�g
		DrawAcceleration();
		if (state == 1 || state != 2) {	// �|�[�Y��
			DrawCombo();
			DrawLife();
		}
		if (GetPlayerDashCount() <= 1.0f)	DrawGaugeX(XMFLOAT2(-75.0f, -200.0f), XMFLOAT2(150.0f, 15.0f), GetPlayerDashCount(), 0);
		if (GetPlayerJumpCount() <= 1.0f)	DrawGaugeY1(XMFLOAT2(-150.0f, -130.0f), XMFLOAT2(15.0f, 150.0f), GetPlayerJumpCount(), 1);
		if (GetPlayerSlide() <= 1.0f)	DrawGaugeY2(XMFLOAT2(150.0f, -130.0f), XMFLOAT2(15.0f, 150.0f), GetPlayerSlide(), 2);
	}
	DrawUI();
	if (GetSceneNo() != SCENE_ENDING) {
		if (state == 2) {	// tips��
			DrawCombo();
			DrawLife();
		}
		DrawScore();
		DrawPlayerIcon();
	}
	DrawTransition();
	SetBlendState(BS_NONE);
	// Z�o�b�t�@�L��
	SetZBuffer(true);
}

int GetState()
{
	return state;
}

void SetState(int no)
{
	state = no;
}