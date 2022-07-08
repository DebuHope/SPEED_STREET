//======================================================================================
// �}�b�v�i�s�x����
// ����F���o�n
//======================================================================================

// �w�b�_�t�@�C���̃C���N���[�h
#include"PlayerIcon.h"
#include"Texture.h"
#include"polygon.h"
#include "Player.h"
#include "Debugproc.h"
#include "Transition.h"
#include "CheckPoint.h"
#include "Game.h"

// �}�N����`
#define COMBO_POS_X	(305)
#define COMBO_POS_Y	(320)
#define COMBO_SIZE_X	(25)
#define COMBO_SIZE_Y	(25)

#define COMBO_TEXTURE		_T("data/texture/UI/PlayerIcon.png")

// �O���[�o���ϐ��錾
static ID3D11ShaderResourceView* g_pTexture;

static XMFLOAT3 g_Position;		// ���W
static XMFLOAT2 g_Size;			// �T�C�Y
static float	g_Angle;		// ��]�p�x
static XMFLOAT2 g_TexCoord;		// �e�N�X�`�����W(�|���S���̍���)(TextureCoordinate)
static XMFLOAT2 g_TexFrameSize;	// �e�N�X�`����\��t����T�C�Y

static int		StageProgress;	// �X�e�[�W�i��

// static = �ϐ���������Ă��Ă������̃w�b�_�t�@�C���݂̂̕ϐ��ɂȂ�

HRESULT LoadPlayerIcon()
{
	HRESULT hr = S_OK;
	ID3D11Device*	pDevice = GetDevice();

	hr = CreateTextureFromFile(pDevice, COMBO_TEXTURE, &g_pTexture);
	if (FAILED(hr)) return hr;

	StageProgress = 0;

	// �t�@�C���ǂݍ���
	FILE* fp;
	if ((fp = fopen("D_StageProgress.dat", "r")) != NULL) {
		// �I�[�v������
		fread(&StageProgress, sizeof(int), 1, fp);
		fclose(fp);
	}

	return hr;
}

//======================================================================================
// ������
//======================================================================================
void InitPlayerIcon()
{
	// �p�����[�^�̏�����
	g_Position		= XMFLOAT3(COMBO_POS_X, COMBO_POS_Y, 0.0f);
	g_Size			= XMFLOAT2(COMBO_SIZE_X, COMBO_SIZE_Y);
	g_Angle			= 0.0f;
	g_TexCoord		= XMFLOAT2(0.0f, 0.0f);
	g_TexFrameSize	= XMFLOAT2(1.0f, 1.0f);

	if (GetCheckFlag(0)) {
		g_Position.x = 447.5;
	}

	
}

//======================================================================================
// �I��
//======================================================================================
void UninitPlayerIcon()
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
void UpdatePlayerIcon()
{
	g_Position.x += GetPlayerVel(0).z / 150;

	if (g_Position.x >= 590)
	{
		switch (GetSceneNo())
		{
		case SCENE_STAGE1_1:
			if(StageProgress <= 1)	StageProgress = 1;
			break;
		case SCENE_STAGE1_2:
			if (StageProgress <= 2)	StageProgress = 2;
			break;
		case SCENE_STAGE1_3:
			if (StageProgress <= 3)	StageProgress = 3;
			break;
		case SCENE_STAGE1_4:
			if (StageProgress <= 3)	StageProgress = 3;
			break;
		case SCENE_STAGE2_1:
			if (StageProgress <= 4)	StageProgress = 4;
			break;
		case SCENE_STAGE2_2:
			if (StageProgress <= 5)	StageProgress = 5;
			break;
		case SCENE_STAGE2_3:
			if (StageProgress <= 6)	StageProgress = 6;
			break;
		case SCENE_STAGE2_4:
			if (StageProgress <= 6)	StageProgress = 6;
			break;
		case SCENE_STAGE3_1:
			if (StageProgress <= 7)	StageProgress = 7;
			break;
		case SCENE_STAGE3_2:
			if (StageProgress <= 8)	StageProgress = 8;
			break;
		case SCENE_STAGE3_3:
			if (StageProgress <= 9)	StageProgress = 9;
			break;
		case SCENE_STAGE3_4:
			if (StageProgress <= 9)	StageProgress = 9;
			break;
		}
		// �t�@�C���ɏ�������
		FILE* fp;
		if ((fp = fopen("D_StageProgress.dat", "w")) != NULL) {
			// �I�[�v������
			fwrite(&StageProgress, sizeof(int), 1, fp);
			fclose(fp);
		}
		if (GetSceneNo() != SCENE_STAGE3_3) {
		StartChange(SCENE_SELECT, 2);
		}
		else {
			StartChange(SCENE_ENDING, 2);
		}
	}
}

//======================================================================================
// �`��
//======================================================================================
void DrawPlayerIcon()
{
	SetPolygonAngle(0.0f);				// ��]�p�x
	SetPolygonAlpha(1.0f);
	if (GetState() != 0 && GetState() != 2) {
		SetPolygonColor(0.3f, 0.3f, 0.3f);
	}
	else {
		SetPolygonColor(1.0f, 1.0f, 1.0f);
	}
	// �|���S���̏��ݒ�
	SetPolygonPos(g_Position.x, g_Position.y);		// ���W
	SetPolygonSize(COMBO_SIZE_X, COMBO_SIZE_Y);	// �傫��
	SetPolygonAngle(g_Angle);				// ��]�p�x

	SetPolygonUV(g_TexCoord.x, g_TexCoord.y);	// UV���W
	SetPolygonFrameSize(g_TexFrameSize.x, g_TexFrameSize.y);	// �����c��
	SetPolygonTexture(g_pTexture);

	// �|���S���̕`�揈��
	ID3D11DeviceContext*	pDeviceContext = GetDeviceContext();
	DrawPolygon(pDeviceContext);
}

XMFLOAT3 GetPlayerIconPos()
{
	return g_Position;
}

int GetStageProgress()
{
	return StageProgress;
}