//======================================================================================
// �V�[���J�ڏ���
// ����F���o�n
//======================================================================================

// �w�b�_�t�@�C���̃C���N���[�h
#include <stdlib.h>
#include"transition.h"
#include"Texture.h"
#include"polygon.h"
#include "Player.h"
#include "Debugproc.h"
#include "Player.h"
#include "PlayerIcon.h"
#include "Life.h"
#include "Game.h"
#include "Score.h"

// �}�N����`
#define TRANSITION_POS_X	(1400)
#define TRANSITION_POS_Y	(0)
#define TRANSITION_SIZE_X	(SCREEN_WIDTH)
#define TRANSITION_SIZE_Y	(SCREEN_HEIGHT)

#define MAX_TEXTURE (4)

#define TRANSITION1		_T("data/texture/UI/Transition1.png")
#define TRANSITION2		_T("data/texture/UI/Transition2.png")
#define TRANSITION3		_T("data/texture/UI/GameOver.png")
#define TRANSITION4		_T("data/texture/UI/GameClear.png")

// �O���[�o���ϐ��錾
static ID3D11ShaderResourceView* g_pTexture[MAX_TEXTURE];	// �e�N�X�`��	

static XMFLOAT3 g_Position;		// ���W
static float	g_Vel;			// ���x
static XMFLOAT2 g_Size;			// �T�C�Y
static float	g_Angle;		// ��]�p�x
static XMFLOAT2 g_TexCoord;		// �e�N�X�`�����W(�|���S���̍���)(TextureCoordinate)
static XMFLOAT2 g_TexFrameSize;	// �e�N�X�`����\��t����T�C�Y
static int		DrawTexNo;
static int		Count;

static bool		StartFlag;
static ETypeScene NextScene;

// static = �ϐ���������Ă��Ă������̃w�b�_�t�@�C���݂̂̕ϐ��ɂȂ�

HRESULT LoadTransition()
{
	HRESULT hr = S_OK;
	ID3D11Device*	pDevice = GetDevice();

	hr = CreateTextureFromFile(pDevice, TRANSITION1, &g_pTexture[0]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, TRANSITION2, &g_pTexture[1]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, TRANSITION3, &g_pTexture[2]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, TRANSITION4, &g_pTexture[3]);
	if (FAILED(hr)) return hr;

	return hr;
}

//======================================================================================
// ������
//======================================================================================
void InitTransition()
{
	// �p�����[�^�̏�����
	g_Position		= XMFLOAT3(TRANSITION_POS_X, TRANSITION_POS_Y, 0.0f);
	g_Vel = 0.0f;
	g_Size			= XMFLOAT2(TRANSITION_SIZE_X, TRANSITION_SIZE_Y);
	g_Angle			= 0.0f;
	g_TexCoord		= XMFLOAT2(0.0f, 0.0f);
	g_TexFrameSize	= XMFLOAT2(1.0f, 1.0f);
	DrawTexNo = 0;
	Count = 0;
	StartFlag = false;
}

//======================================================================================
// �I��
//======================================================================================
void UninitTransition()
{
	//// �e�N�X�`����Еt��
	//for (int i = 0; i < MAX_TEXTURE; i++)
	//{
	//	SAFE_RELEASE(g_pTexture[i]);
	//}
}

//======================================================================================
// �X�V
//======================================================================================
void UpdateTransition()
{
	if (StartFlag == true) {
		g_Position.x += g_Vel -= 4.0f;

		if (g_Position.x <= 0 && Count < 120) {
			
			g_Position.x = 0.0f;
			g_Position.x += g_Vel = 0.0f;
			StartSceneChange(SCENE_TITLE);
			SetState(0);
			AddCountCombo(-999);
		}
		if (Count == 120) StartSceneChange(NextScene);
		if (g_Position.x <= -1400.0f) StartFlag = false;
		Count++;
	}
}

//======================================================================================
// �`��
//======================================================================================
void DrawTransition()
{
	SetPolygonAngle(0.0f);
	SetPolygonAlpha(1.0f);
	SetPolygonColor(1.0f, 1.0f, 1.0f);
	// �|���S���̏��ݒ�
	SetPolygonPos(g_Position.x, g_Position.y);		// ���W
	SetPolygonSize(TRANSITION_SIZE_X, TRANSITION_SIZE_Y);	// �傫��
	SetPolygonAngle(g_Angle);	// ��]�p�x

	SetPolygonUV(g_TexCoord.x, g_TexCoord.y);	// UV���W
	SetPolygonFrameSize(g_TexFrameSize.x, g_TexFrameSize.y);	// �����c��
	SetPolygonTexture(g_pTexture[DrawTexNo]);

	// �|���S���̕`�揈��
	ID3D11DeviceContext*	pDeviceContext = GetDeviceContext();
	DrawPolygon(pDeviceContext);
}

//======================================================================================
// �V�[���J��
//======================================================================================
void StartChange(ETypeScene nextscene, int no)
{
	if (StartFlag != true) {
		StartFlag = true;
		NextScene = nextscene;
		g_Position = XMFLOAT3(TRANSITION_POS_X, TRANSITION_POS_Y, 0.0f);
		g_Vel = 0.0f;
		Count = 0;

		switch (no)
		{
		case 0:
			DrawTexNo = rand() % 2;
			break;
		case 1:
			DrawTexNo = 2;
			break;
		case 2:
			DrawTexNo = 3;
			Count = -180;
			break;
		}
	}
}
