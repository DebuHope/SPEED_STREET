//=============================================================================
// �v���C���[����
// ����F���o�n
//=============================================================================
#include <math.h>
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Player.h"
#include "Shadow.h"
#include "main.h"
#include "Camera.h"
#include "input.h"
#include "UI.h"
#include "Transition.h"
#include "Life.h"
#include "CheckPoint.h"
#include "Sound.h"
#include "Score.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MODEL_RUN		"data/model/player/running.fbx"
#define MODEL_FASTRUN	"data/model/player/fastrun.fbx"
#define MODEL_BREAK		"data/model/player/break.fbx"
#define MODEL_JUMP		"data/model/player/jump.fbx"
#define MODEL_SLIDE		"data/model/player/slide.fbx"
#define MODEL_WDOWN		"data/model/player/fall.fbx"
#define MODEL_SDOWN		"data/model/player/stunned.fbx"
#define MODEL_FALL		"data/model/player/falling.fbx"
#define MODEL_SITTING	"data/model/player/sitting.fbx"

#define MAX_PLAYER_MODEL	(11)

#define ROT_Y			(180.0f)
#define VALUE_MOVE		(4.0f)
#define VALUE_ROTATE	(5.0f)
#define GRAVITY			(-0.50f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tPlayer
{
	XMFLOAT4X4	mtxWorld;

	XMFLOAT3 pos;	// ���W
	XMFLOAT3 rot;	// ��]
	XMFLOAT3 scl;	// �g�嗦
	XMFLOAT3 vel;	// ���x
	XMFLOAT2 velXZ;	// �O�ړ��p���x

	int		nPhase;	// �s���p�^�[���̒i�K
	int		nState;	// �s��(0�ȉ�:���g�p 1�ȏ�:�ʏ�)
	int		nShadowIdx;	// �e�̔ԍ�
}tPlayer;

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static CAssimpModel	g_model[MAX_PLAYER_MODEL];	// ���f���f�[�^
static tPlayer		g_player[MAX_PLAYER];	// �v���C���[��
static PlayerPhose DrawModelNo;	// �\�����郂�f��
static int AnimCount;
static int DashCount;
static int SlideCount;
static int JumpCount;
static int JoyZCount;
static int InvincibleCount;
static int StartInvincibleCount;
static bool DownFlag;
static bool JoyTriggerFalg;

HRESULT LoadPlayer(void)
{
	HRESULT hr = S_OK;
	ID3D11Device* pDevice = GetDevice();
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// ���f���f�[�^�̓ǂݍ���
	hr = g_model[RUN].Load(pDevice, pDeviceContext,
		MODEL_RUN);
	hr = g_model[DASH].Load(pDevice, pDeviceContext,
		MODEL_FASTRUN);
	hr = g_model[BREAK].Load(pDevice, pDeviceContext,
		MODEL_BREAK);
	hr = g_model[JUMP].Load(pDevice, pDeviceContext,
		MODEL_JUMP);
	hr = g_model[SLIDE].Load(pDevice, pDeviceContext,
		MODEL_SLIDE);
	hr = g_model[WDOWN].Load(pDevice, pDeviceContext,
		MODEL_WDOWN);
	hr = g_model[SDOWN].Load(pDevice, pDeviceContext,
		MODEL_SDOWN);
	hr = g_model[FALL].Load(pDevice, pDeviceContext,
		MODEL_FALL);
	hr = g_model[SITTING].Load(pDevice, pDeviceContext,
		MODEL_SITTING);

	return hr;
}

//=============================================================================
// ����������
//=============================================================================
void InitPlayer(void)
{
	// �ʒu�E��]�E�X�P�[���̏����ݒ�
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		g_player[i].pos = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_player[i].rot = XMFLOAT3(0.0f, ROT_Y, 0.0f);
		g_player[i].scl = XMFLOAT3(4.0f, 4.0f, 4.0f);
		g_player[i].vel = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_player[i].velXZ = XMFLOAT2(0.0f, 0.0f);
		g_player[i].nPhase = 0;
		g_player[i].nState = 1;	// �v���C���[�����͐���

		if (GetCheckFlag(0))				g_player[i].pos = GetCheckPointPos(0);

		if(GetSceneNo() == SCENE_ENDING)	g_player[i].pos = XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	DrawModelNo = RUN;
	AnimCount = 0;
	DashCount = 120;
	SlideCount = 40;
	JumpCount = 40;
	JoyZCount = 0;
	InvincibleCount = 0;
	StartInvincibleCount = 0;
	DownFlag = false;
	JoyTriggerFalg = false;

	// ���[���h�}�g���b�N�X�̏�����
	XMMATRIX mtxWorld;
	mtxWorld = XMMatrixIdentity();
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		XMStoreFloat4x4(&g_player[i].mtxWorld, mtxWorld);
	}

	// �e�̍쐬
	for (int i = 0; i < MAX_PLAYER; i++) {
		g_player[i].nShadowIdx = CreateShadow(g_player[i].pos, 20.0f);
	}


	if (GetSceneNo() != SCENE_TITLE && DrawModelNo == RUN) {
		PlaySound(SOUND_LABEL_SE_RUN);
	}
}


//=============================================================================
// �I������
//=============================================================================
void UninitPlayer(void)
{
	// �e�̉��
	for (int i = 0; i < MAX_PLAYER; i++) {
		ReleaseShadow(g_player[i].nShadowIdx);
	}
	// ���f���̉��
	//for (int i = 0; i < MAX_PLAYER_MODEL; i++) {
	//	g_model[i].Release();
	//}
	StopSound(SOUND_LABEL_SE_RUN);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdatePlayer(void)
{
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		if (g_player[i].nState == 0)	continue;

		// ���f���̓������L�q����Ȃ炱��====================================================

		if (GetDrawTexNo() == UI_MANUAL || GetSceneNo() == SCENE_STAGE1_1 || GetSceneNo() == SCENE_STAGE1_2
			|| GetSceneNo() == SCENE_STAGE1_3 || GetSceneNo() == SCENE_STAGE1_4 || GetSceneNo() == SCENE_STAGE2_1
			|| GetSceneNo() == SCENE_STAGE2_2 || GetSceneNo() == SCENE_STAGE2_3 || GetSceneNo() == SCENE_STAGE2_4
			|| GetSceneNo() == SCENE_STAGE3_1 || GetSceneNo() == SCENE_STAGE3_2 || GetSceneNo() == SCENE_STAGE3_3
			|| GetSceneNo() == SCENE_STAGE3_4 || GetSceneNo() == SCENE_ENDING) {
			// �����Ă�������Ɉړ�
			if (GetSceneNo() != SCENE_ENDING) {
				if (GetKeyPress(VK_A) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 22500 && GetJoyPOV(0) <= 31500) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) < -30000) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// �u���[�L��
						g_player[i].vel.x = -VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// �_�b�V����
						g_player[i].vel.x = -VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = -VALUE_MOVE;
					}
					// ���炩�ɕ����]��
					if (g_player[i].rot.y > ROT_Y - 20.0f) {
						g_player[i].rot.y -= 5.0f;
					}
				}
				else if (GetKeyPress(VK_D) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 4500 && GetJoyPOV(0) <= 13500) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) > 30000) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// �X���C�f�B���O��
						g_player[i].vel.x = VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// �_�b�V����
						g_player[i].vel.x = VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = VALUE_MOVE;
					}
					// ���炩�ɕ����]��
					if (g_player[i].rot.y < ROT_Y + 20.0f) {
						g_player[i].rot.y += 5.0f;
					}
				}
				else {
					// ��ɑO����������
					if (g_player[i].rot.y < ROT_Y) {
						// ���炩�ɕ����]��
						g_player[i].rot.y += 5.0f;
					}
					else if (g_player[i].rot.y > ROT_Y) {
						g_player[i].rot.y -= 5.0f;
					}
				}
			}
			//�@�G���f�B���O
			else{
				if (GetKeyPress(VK_D) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 22500 && GetJoyPOV(0) <= 31500) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) < -30000) && g_player[i].pos.x >= -92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// �u���[�L��
						g_player[i].vel.x = -VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// �_�b�V����
						g_player[i].vel.x = -VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = -VALUE_MOVE;
					}
					// ���炩�ɕ����]��
					if (g_player[i].rot.y > ROT_Y - 20.0f) {
						g_player[i].rot.y -= 5.0f;
					}
				}
				else if (GetKeyPress(VK_A) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyPOV(0) >= 4500 && GetJoyPOV(0) <= 13500) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL ||
					GetJoyCountSimple() == 1 && (GetJoyX(0) > 30000) && g_player[i].pos.x <= 92.0f &&
					DrawModelNo != SDOWN && DrawModelNo != WDOWN && DrawModelNo != FALL) {
					if (DrawModelNo == BREAK) {	// �X���C�f�B���O��
						g_player[i].vel.x = VALUE_MOVE / 2.5f;
					}
					else if (DrawModelNo == DASH) {	// �_�b�V����
						g_player[i].vel.x = VALUE_MOVE / 1.5f;
					}
					else {
						g_player[i].vel.x = VALUE_MOVE;
					}
					// ���炩�ɕ����]��
					if (g_player[i].rot.y < ROT_Y + 20.0f) {
						g_player[i].rot.y += 5.0f;
					}
				}
				else {
					// ��ɑO����������
					if (g_player[i].rot.y < ROT_Y) {
						// ���炩�ɕ����]��
						g_player[i].rot.y += 5.0f;
					}
					else if (g_player[i].rot.y > ROT_Y) {
						g_player[i].rot.y -= 5.0f;
					}
				}
			}

			// �_�b�V��
			if (GetKeyTrigger(VK_W) && DrawModelNo == RUN && DashCount > 120 && GetSceneNo() != SCENE_STAGE1_4||
				JoyZCount >= 1 && JoyZCount <= 110 && DrawModelNo == RUN && DashCount > 120 && GetSceneNo() != SCENE_STAGE1_4) {
				AnimCount = 0;
				DashCount = 0;
				DrawModelNo = DASH;
				g_player[i].rot.x = -20.0f;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_DASH);
			}
			// �u���[�L
			if (GetKeyTrigger(VK_S) && DrawModelNo == RUN && GetSceneNo() != SCENE_STAGE1_4||
				JoyZCount <= -1 && JoyZCount >= -30 && DrawModelNo == RUN && GetSceneNo() != SCENE_STAGE1_4) {
				AnimCount = 0;
				DrawModelNo = BREAK;
				g_player[i].vel.z = 8.0f;
				g_player[i].rot.x = 0.0f;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_SLIDE);
			}
			// �W�����v
			if (GetKeyTrigger(VK_K) && DrawModelNo == RUN && DrawModelNo != FALL && JumpCount > 40 ||
				GetKeyTrigger(VK_K) && DrawModelNo == DASH && DrawModelNo != FALL && JumpCount > 40 ||
				GetKeyTrigger(VK_K) && DrawModelNo == SLIDE && DrawModelNo != FALL && JumpCount > 40 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON1) && DrawModelNo == RUN && DrawModelNo != FALL && JumpCount > 40 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON1) && DrawModelNo == DASH && DrawModelNo != FALL && JumpCount > 40 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON1) && DrawModelNo == SLIDE && DrawModelNo != FALL && JumpCount > 40)
			{
				DrawModelNo = JUMP;
				g_player[i].vel.y += 8.0f;
				g_player[i].rot.x = 0.0f;
				JumpCount = 0;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_JUMP);
			}
			// �X���C�f�B���O
			if (GetKeyTrigger(VK_L) && DrawModelNo == RUN && SlideCount > 50 ||
				GetKeyTrigger(VK_L) && DrawModelNo == DASH && SlideCount > 50 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON2) && DrawModelNo == RUN && SlideCount > 50 ||
				GetJoyCountSimple() == 1 && GetJoyTrigger(0, JOYBUTTON2) && DrawModelNo == DASH && SlideCount > 50)
			{
				AnimCount = 0;
				SlideCount = 0;
				DrawModelNo = SLIDE;
				g_player[i].rot.x = 15.0f;
				StopSound(SOUND_LABEL_SE_RUN);
				PlaySound(SOUND_LABEL_SE_SLIDE);
			}
		}// �^�C�g����
		else if (GetSceneNo() == SCENE_TITLE) {
			g_player[i].pos = XMFLOAT3(-66.0f, 0.0f, 300.0f);
			//g_player[i].pos = XMFLOAT3(0.0f, 0.0f, 300.0f);
			g_player[i].rot.y = 0.0f;
		}
		// ��ɑO�ړ�
		if (DrawModelNo == RUN) {	// �ʏ펞
			g_player[i].vel.z = 8.0f;
			if (GetSceneNo() == SCENE_STAGE1_4) {
				g_player[i].vel.z = 25.0f;
			}
			if (GetSceneNo() == SCENE_ENDING) {
				g_player[i].vel.z = 5.0f;
			}
		}
		else if (DrawModelNo == DASH) {	// �_�b�V����
			g_player[i].vel.z = 22.0f;
		}
		else if (DrawModelNo == BREAK) {	// �u���[�L��
			g_player[i].vel.z -= 0.25f;	// ���񂾂񌸑�
			if (g_player[i].vel.z <= 0) {	// �X�s�[�h���O�ɂȂ�����RUN�ɖ߂�
				DrawModelNo = RUN;
				PlaySound(SOUND_LABEL_SE_RUN);
			}
		}
		else if (DrawModelNo == SDOWN) {	// �_�E����
			g_player[i].vel.z += 0.2f;
			if (g_player[i].vel.z >= 0) {	// �X�s�[�h���O�ɂȂ�����O�̂܂�
				g_player[i].vel.z = 0.0f;
			}
		}
		else if (DrawModelNo == WDOWN) {	// �_�E����
			g_player[i].vel.z -= 0.2f;
			if (g_player[i].vel.z <= 0) {	// �X�s�[�h���O�ɂȂ�����O�̂܂�
				g_player[i].vel.z = 0.0f;
			}
		}

		// �d�͂����W�ɉ��Z
		g_player[i].vel.y += GRAVITY;

		// ���x�����W�ɉ��Z
		g_player[i].pos.x += g_player[i].vel.x;
		g_player[i].pos.y += g_player[i].vel.y;
		g_player[i].pos.z += g_player[i].vel.z;

		// ������(�L�[�������Ă��Ȃ���)
		g_player[i].vel.x = 0.0f;

		// ���n����
		if (DrawModelNo != FALL && g_player[i].pos.y <= 0.0f)
		{
			if (DrawModelNo == JUMP) {
				PlaySound(SOUND_LABEL_SE_RUN);
				DrawModelNo = RUN;
			}
			g_player[i].vel.y = 0.0f;
			g_player[i].pos.y = 0.0f;
		}

		//================================================================
		XMMATRIX mtxWorld, mtxRot, mtxScl, mtxTranslate;

		// ���[���h�}�g���b�N�X�̏�����
		mtxWorld = XMMatrixIdentity();

		// �X�P�[���𔽉f
		mtxScl = XMMatrixScaling(
			g_player[i].scl.x,
			g_player[i].scl.y,
			g_player[i].scl.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxScl);

		// ��]�𔽉f
		mtxRot = XMMatrixRotationRollPitchYaw(
			XMConvertToRadians(g_player[i].rot.x),
			XMConvertToRadians(g_player[i].rot.y),
			XMConvertToRadians(g_player[i].rot.z)
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxRot);

		// �ړ��𔽉f
		mtxTranslate = XMMatrixTranslation(
			g_player[i].pos.x,
			g_player[i].pos.y,
			g_player[i].pos.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxTranslate);

		// ���[���h�}�g���b�N�X�ݒ�
		XMStoreFloat4x4(&g_player[i].mtxWorld, mtxWorld);

		// �e�̈ړ�
		MoveShadow(g_player[i].nShadowIdx, g_player[i].pos);

		// �J�����ݒ�
		if (GetSceneNo() != SCENE_SELECT && GetSceneNo() != SCENE_TITLE && GetSceneNo() != SCENE_ENDING) {

			if (DrawModelNo != FALL) {	// �ʏ펞
				// �J�����^�[�Q�b�g�ݒ�
				GetCamera()->SetTarget(
					g_player[0].pos.x,
					g_player[0].pos.y + 15.0f,
					g_player[0].pos.z + 50.0f);
				// �J�������W�ݒ�
				GetCamera()->SetPos(
					g_player[0].pos.x,
					65.0f + g_player[0].pos.y / 10.0f,
					g_player[0].pos.z - 130.0f);
			}
			else if (DrawModelNo == FALL) {	// ������
				// �J�����^�[�Q�b�g�ݒ�
				GetCamera()->SetTarget(
					g_player[0].pos.x,
					g_player[0].pos.y + 15.0f,
					g_player[0].pos.z + 50.0f);
				// �J�������W�ݒ�
				GetCamera()->SetPos(
					g_player[0].pos.x,
					65.0f + g_player[0].pos.y / 1.5f,
					g_player[0].pos.z - 130.0f);
			}
		}
		// �G���f�B���O
		else if (GetSceneNo() == SCENE_ENDING) {
			// �J�����^�[�Q�b�g�ݒ�
			GetCamera()->SetTarget(
				0.0f,
				30.0f,
				g_player[0].pos.z + 50.0f);
			// �J�������W�ݒ�
			GetCamera()->SetPos(
				0.0f,
				70.0f,
				g_player[0].pos.z + 450.0f);
		}
		else {
			// �J�����^�[�Q�b�g�ݒ�
			GetCamera()->SetTarget(
				-50.0f,
				g_player[0].pos.y + 15.0f,
				g_player[0].pos.z + 50.0f);
			// �J�������W�ݒ�
			GetCamera()->SetPos(
				10.0f,
				65.0f + g_player[0].pos.y / 10.0f,
				g_player[0].pos.z - 130.0f);
		}


		// �Q�[���I�[�o�[
		if (RemainingLife(0) <= 0 && AnimCount >= 50) {
			StartChange(GetSceneNo(), 1);
		}
		if (g_player[i].pos.y < -1500.0f && DrawModelNo == FALL) {
			StartChange(GetSceneNo(), 1);
		}
	}

	// ��莞�Ԍo�߂Ń��f����߂�
	if (DrawModelNo == SLIDE && AnimCount > 33) {	// �X���C�h��
		DrawModelNo = RUN;
		g_player[0].rot.x = 0.0f;
		PlaySound(SOUND_LABEL_SE_RUN);
	}
	else if (DrawModelNo == DASH && AnimCount > 60) {	// �_�b�V����
		DrawModelNo = RUN;
		g_player[0].rot.x = 0.0f;
		PlaySound(SOUND_LABEL_SE_RUN);
	}
	else if (DrawModelNo == WDOWN && AnimCount > 70 ||
			 DrawModelNo == SDOWN && AnimCount > 70) {	// �_�E����
		DrawModelNo = RUN;
		g_player[0].rot.x = 0.0f;
		PlaySound(SOUND_LABEL_SE_RUN);
	}

	AnimCount++;
	DashCount++;
	SlideCount++;
	JumpCount++;
	StartInvincibleCount++;

	// �p�b�hZ���t���O
	if (GetJoyCountSimple() == 1 && (GetJoyZ(0) < -20000)) {
		JoyZCount++;
	}
	else if (GetJoyCountSimple() == 1 && (GetJoyZ(0) > 20000)) {
		JoyZCount--;
	}
	else {
		JoyZCount = 0;
	}

	if(DownFlag) InvincibleCount++;
	if (InvincibleCount > 150) DownFlag = false;

	////  �X�g���[�g
	//if (GetUIState() == 0) {
	//	g_player[0].scl = XMFLOAT3(4.0f, 4.0f, 4.0f);
	//	DrawModelNo = RUN;
	//}
	////  �t�H���X�g
	//if (GetUIState() == 1) {
	//	g_player[0].scl = XMFLOAT3(0.3f, 0.3f, 0.3f);
	//	DrawModelNo = RUN2;
	//}
	////  �i�C�g�X�g���[�g
	//if (GetUIState() == 2) {
	//	g_player[0].scl = XMFLOAT3(0.3f, 0.3f, 0.3f);
	//	DrawModelNo = RUN3;
	//}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawPlayer(void)
{
	for (int i = 0; i < MAX_PLAYER; i++)
	{
		ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

		if (InvincibleCount < 70 || InvincibleCount > 150 || GetSceneNo() == SCENE_TITLE) {

			g_model[DrawModelNo].Draw(pDeviceContext, g_player[i].mtxWorld);
		}
		else if (DownFlag && InvincibleCount > 70 && (DashCount % 5) == 1) {
			// ���f���\��
			g_model[DrawModelNo].Draw(pDeviceContext, g_player[i].mtxWorld);
		}
	}
}

XMFLOAT4X4 GetPlayerWorld(int no)
{
	return g_player[no].mtxWorld;
}

// ���S���W����
XMFLOAT3 GetPlayerCenter(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	XMFLOAT3 pos = g_model[DrawModelNo].GetCenter();
	pos.x += g_player[no].pos.x;
	pos.y += g_player[no].pos.y;
	pos.z += g_player[no].pos.z;
	return pos;
}

// ���f���T�C�Y����
XMFLOAT3 GetPlayerBBox(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	// ���f������T�C�Y����������
	XMFLOAT3 size = g_model[DrawModelNo].GetBBox();
	return XMFLOAT3(
		size.x * g_player[no].scl.x,
		size.y * g_player[no].scl.y,
		size.z * g_player[no].scl.z);
}

// ���W����
XMFLOAT3 GetPlayerPos(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_player[no].pos;
}

// �T�C�Y����
XMFLOAT3 GetPlayerSize(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_player[no].scl;
}

// �������Ă��邩
bool IsPlayer(int no)
{
	if (no < 0 || no >= MAX_PLAYER || DrawModelNo != SDOWN && DownFlag || StartInvincibleCount <= 50) {
		return false;
	}
	return true;
}

// �\�����Ȃ�
void DestroyPlayer(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return;
	}
	g_player[no].nState = 0;
	ReleaseShadow(g_player[no].nShadowIdx);
	g_player[no].nShadowIdx = -1;
}

// ���f����񏊓�
PlayerPhose GetPlayerPhose(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return RUN;
	}

	return DrawModelNo;
}

// �_�E�����f���ύX
void PlayerPhoseChange(int no, PlayerPhose phose)
{
	if (no < 0 || no >= MAX_PLAYER) return;

	if (DrawModelNo != SDOWN && DrawModelNo != WDOWN && phose != FALL &&
		g_player[no].pos.y <= 0.0f) {
		g_player[no].vel.y += 7.0f;
	}
	// ���f���ɂ���Ĉړ��ʂ�ς���
	if (phose == SDOWN) {
		g_player[no].vel.z = -10.0f;
	}
	else if (phose == WDOWN) {
		g_player[no].vel.z = 8.0f;
	}
	g_player[no].rot.x = 0.0f;
	AnimCount = 0;
	InvincibleCount = 0;
	DrawModelNo = phose;
	
	DownFlag = true;
}

// ���x����
XMFLOAT3 GetPlayerVel(int no)
{
	if (no < 0 || no >= MAX_PLAYER) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_player[no].vel;
}

float GetPlayerDashCount()
{
	return (float)DashCount / 120.0f;
}

float GetPlayerJumpCount()
{
	return (float)JumpCount / 40.0f;
}

float GetPlayerSlide()
{
	return (float)SlideCount / 50.0f;
}
