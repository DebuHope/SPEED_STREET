//======================================================================================
// �����G�t�F�N�g
// ����F���o�n
//======================================================================================

// �w�b�_�t�@�C���̃C���N���[�h
#include"EF_Acceleration.h"
#include"texture.h"
#include"polygon.h"
#include "Player.h"

// �}�N����`
#define ACCELERATION_POS_X	 (0)
#define ACCELERATION_POS_Y	 (0)
#define ACCELERATION_SIZE_X (2000)
#define ACCELERATION_SIZE_Y (750)
#define ACCELERATION_FRAME_X (5)	// �摜��������
#define ACCELERATION_FRAME_Y (1)	// �摜�c������

#define ACCELERATION_TEXTURENAME	_T("data/texture/kasoku3.png")

#define FLUCTUATION_ALPHA	(0.15f)	// Alpha�ϓ��l

// �O���[�o���ϐ��錾
static ID3D11ShaderResourceView* g_pTexture;	// �e�N�X�`��

static XMFLOAT3 g_Position;		// ���W
static XMFLOAT2 g_Size;			// �T�C�Y
static float	g_Angle;		// ��]�p�x
static float	g_Alpha;		// �����x
static XMFLOAT2 g_TexCoord;		// �e�N�X�`�����W(�|���S���̍���)(TextureCoordinate)
static XMFLOAT2 g_TexFrameSize;	// �e�N�X�`����\��t����T�C�Y
static int		g_AnimNo;
static int		g_AnimCnt;

static ANIM_PAT g_animPat[1][6] = {	// �����A�j���[�V�������[�\���p�^�[���ԍ�][�\���t���[����]
	{{0,2},{1,2},{2,2},{3,2},{4,2},{-1,-1}},
};

HRESULT LoadAcceleration()
{
	HRESULT hr = S_OK;
	ID3D11Device*	pDevice = GetDevice();

	hr = CreateTextureFromFile(pDevice, ACCELERATION_TEXTURENAME, &g_pTexture);
	if (FAILED(hr)) return hr;

	return hr;
}

//======================================================================================
// ������
//======================================================================================
void InitAcceleration(void)
{
	// �p�����[�^�̏�����
	g_Position = XMFLOAT3(ACCELERATION_POS_X, ACCELERATION_POS_Y, 0.0f);
	g_Size = XMFLOAT2(ACCELERATION_SIZE_X, ACCELERATION_SIZE_Y);
	g_Angle = 0.0f;
	g_Alpha = 0.0f;
	g_TexCoord = XMFLOAT2(0.0f, 0.0f);
	g_TexFrameSize = XMFLOAT2(1.0f, 1.0f);
	g_AnimNo = 0;
	g_AnimCnt = g_animPat[0][g_AnimNo].nCount; // �ŏ��̃A�j���\������
}

//======================================================================================
// �I��
//======================================================================================
void UninitAcceleration(void)
{
	// �e�N�X�`����Еt��
	//SAFE_RELEASE(g_pTexture);
}

//======================================================================================
// �X�V
//======================================================================================
void UpdateAcceleration()
{
	if (GetPlayerVel(0).z >= 15.0f && GetPlayerPhose(0) != FALL) {
		g_Alpha += FLUCTUATION_ALPHA;
	}
	else {
		g_Alpha -= FLUCTUATION_ALPHA;
	}

	if (g_Alpha > 1.0f) {
		g_Alpha = 1.0f;
	}
	else if (g_Alpha < 0.0f) {
		g_Alpha = 0.0f;
	}

	// �A�j���[�V�������̍X�V
	g_AnimCnt--;	// �c��J�E���g�������炷
	if (g_AnimCnt <= 0)
	{
		g_AnimNo++;	// ���̊G�ɐi�߂�

		if (g_animPat[0][g_AnimNo].nPatNo < 0)
		{
			// �ԕ����Q�Ƃ�����
			g_AnimNo = 0;	// �߂�
		}
		// �J�E���^�����̊G�̕\���t���[�����ɐݒ�
		g_AnimCnt = g_animPat[0][g_AnimNo].nCount;
	}
}

//======================================================================================
// �`��
//======================================================================================
void DrawAcceleration()
{
	// �|���S���̏��ݒ�
	SetPolygonPos(ACCELERATION_POS_X, ACCELERATION_POS_Y);	// ���W
	SetPolygonSize(ACCELERATION_SIZE_X, ACCELERATION_SIZE_Y);	// �T�C�Y
	SetPolygonAngle(g_Angle);	// �p�x	

	SetPolygonFrameSize(1.0f / ACCELERATION_FRAME_X, 1.0f / ACCELERATION_FRAME_Y);	// �e�N�X�`���̉����A�c��
	int u = g_animPat[0][g_AnimNo].nPatNo % ACCELERATION_FRAME_X;	// �����Ă������
	int v = g_animPat[0][g_AnimNo].nPatNo / ACCELERATION_FRAME_X;
	SetPolygonUV(u / (float)ACCELERATION_FRAME_X, v / (float)ACCELERATION_FRAME_Y);	// 0��(���㒸�_)�̃e�N�X�`�����W�w��
	SetPolygonAlpha(g_Alpha);
	SetPolygonColor(1.0f, 1.0f, 1.0f);

	SetPolygonTexture(g_pTexture);	// �e�N�X�`���w��

	// �|���S���̕`�揈��
	ID3D11DeviceContext*	pDeviceContext = GetDeviceContext();
	DrawPolygon(pDeviceContext);
}