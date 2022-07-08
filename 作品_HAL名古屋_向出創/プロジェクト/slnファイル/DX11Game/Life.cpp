//======================================================================================
// ���C�t����
// ����F���o�n
//======================================================================================

// �w�b�_�t�@�C���̃C���N���[�h
#include"Life.h"
#include"input.h"
#include"texture.h"
#include"polygon.h"
#include "Transition.h"
#include "Game.h"

// �}�N����`
#define LIFE_SIZE_X (40)	// ��
#define LIFE_SIZE_Y (38)	// �c
#define LIFE_POS_X	 (-SCREEN_WIDTH / 2 + 111)	// x���W
#define LIFE_POS_Y	 (SCREEN_HEIGHT / 2 - 48)	// y���W
#define LIFE_FRAME_X (1)	// �摜��������
#define LIFE_FRAME_Y (2)	// �摜�c������

#define LIFE_TEXTURENAME	_T("data/texture/UI/Life2.png")

// �O���[�o���ϐ��錾
static ID3D11ShaderResourceView* g_pTexture;	// �e�N�X�`��

static XMFLOAT3	g_Position;	// ���W
static XMFLOAT2	g_Size;		// �T�C�Y
static XMFLOAT2	g_Scale;	// �g��k��
static float	g_Angle;	// ��]�p�x
static int		g_nMaxLife;

static XMFLOAT2		g_TexCoord;		// �e�N�X�`�����W(�|���S���̍���)(TextureCoordinate)
static XMFLOAT2		g_TexFrameSize;	// �e�N�X�`����\��t����T�C�Y

HRESULT LoadLife()
{
	HRESULT hr = S_OK;

	// �e�N�X�`���ǂݍ���
	ID3D11Device*	pDevice = GetDevice();
	hr = CreateTextureFromFile(pDevice, LIFE_TEXTURENAME, &g_pTexture);

	g_TexCoord = XMFLOAT2(0.0f, 0.0f);
	g_TexFrameSize = XMFLOAT2(1.0f, 1.0f);

	return hr;
}

//======================================================================================
// ������
//======================================================================================
void InitLife(void)
{
	// �p�����[�^�̏�����
	g_Position = XMFLOAT3(LIFE_POS_X, LIFE_POS_Y, 0.0f);
	g_Size = XMFLOAT2(LIFE_SIZE_X, LIFE_SIZE_Y);
	g_Angle = 0.0f;
	g_Scale = XMFLOAT2(1.0f, 1.0f);
	g_nMaxLife = 3;
}

//======================================================================================
// �I��
//======================================================================================
void UninitLife(void)
{
	//// �e�N�X�`����Еt��
	//SAFE_RELEASE(g_pTexture);
}

//======================================================================================
// �X�V
//======================================================================================
void UpdateLife()
{

}

//======================================================================================
// �`��
//======================================================================================
void DrawLife()
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// ��		���l�`��
	SetPolygonColor(1.0f, 1.0f, 1.0f);
	SetPolygonAngle(180.0f);
	SetPolygonAlpha(1.0f);
	SetPolygonSize(LIFE_SIZE_X, LIFE_SIZE_Y);
	SetPolygonFrameSize(1.0f / LIFE_FRAME_X, 1.0f / -LIFE_FRAME_Y);

	SetPolygonUV(g_TexCoord.x, g_TexCoord.y);
	SetPolygonTexture(g_pTexture);
	// �\������ʒu�����߂�

	float fX = g_Position.x + LIFE_SIZE_X * (5 - 0.5f);
	float fY = g_Position.y - LIFE_SIZE_Y * 0.5f + 2.0f;

	for (int i = 0; i < 3; ++i)
	{
		SetPolygonPos(fX, fY);
		DrawPolygon(pDeviceContext);
		fX += LIFE_SIZE_X + 10;
	}

	// ��		���l�`��
	SetPolygonColor(1.0f, 1.0f, 1.0f);
	SetPolygonAngle(0.0f);
	SetPolygonAlpha(1.0f);
	SetPolygonSize(LIFE_SIZE_X, LIFE_SIZE_Y);
	SetPolygonFrameSize(1.0f / LIFE_FRAME_X, 1.0f / LIFE_FRAME_Y);

	SetPolygonUV(g_TexCoord.x, g_TexCoord.y);
	SetPolygonTexture(g_pTexture);
	// �\������ʒu�����߂�

	fX = g_Position.x + LIFE_SIZE_X * (5 - 0.5f);
	fY = g_Position.y - LIFE_SIZE_Y * 0.5f;

	for (int i = 0; i < g_nMaxLife; ++i)
	{
		SetPolygonPos(fX, fY);
		DrawPolygon(pDeviceContext);
		fX += LIFE_SIZE_X + 10;
	}
}

// ���C�t����
int RemainingLife(int num)
{
	g_nMaxLife -= num;
	if (g_nMaxLife < 0)	g_nMaxLife = 0;

	return g_nMaxLife;
}

// ���C�t��
int RecoveryLife(int num)
{
	g_nMaxLife += num;
	if (g_nMaxLife > 3)	g_nMaxLife = 3;

	return g_nMaxLife;
}
