//======================================================================================
// �R���{����
// ����F���o�n
//======================================================================================

// �w�b�_�t�@�C���̃C���N���[�h
#include"Combo.h"
#include"Texture.h"
#include"polygon.h"
#include "Player.h"
#include "Debugproc.h"
#include "Transition.h"
#include "CheckPoint.h"
#include "Game.h"
#include "Score.h"

// �}�N����`
#define COMBO_POS_X	(0)
#define COMBO_POS_Y	(0)
#define COMBO_SIZE_X	(SCREEN_WIDTH)
#define COMBO_SIZE_Y	(SCREEN_HEIGHT)

#define COMBO_TEXTURE		_T("data/texture/UI/Combo.png")

// �O���[�o���ϐ��錾
static ID3D11ShaderResourceView* g_pTexture;	// �e�N�X�`��	

static XMFLOAT3 g_Position;		// ���W
static XMFLOAT2 g_Size;			// �T�C�Y
static float	g_Angle;		// ��]�p�x
static XMFLOAT2 g_TexCoord;		// �e�N�X�`�����W(�|���S���̍���)(TextureCoordinate)
static XMFLOAT2 g_TexFrameSize;	// �e�N�X�`����\��t����T�C�Y

HRESULT LoadCombo()
{
	HRESULT hr = S_OK;
	ID3D11Device*	pDevice = GetDevice();

	hr = CreateTextureFromFile(pDevice, COMBO_TEXTURE, &g_pTexture);
	if (FAILED(hr)) return hr;

	return hr;
}

//======================================================================================
// ������
//======================================================================================
void InitCombo()
{
	// �p�����[�^�̏�����
	g_Position		= XMFLOAT3(COMBO_POS_X, COMBO_POS_Y, 0.0f);
	g_Size			= XMFLOAT2(COMBO_SIZE_X, COMBO_SIZE_Y);
	g_Angle			= 0.0f;
	g_TexCoord		= XMFLOAT2(0.0f, 0.0f);
	g_TexFrameSize	= XMFLOAT2(1.0f, 1.0f);
}

//======================================================================================
// �I��
//======================================================================================
void UninitCombo()
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
void UpdateCombo()
{
	//if (GetComboCount() == 10) {
	//	g_Position.y += 50.0f;
	//	SetComboCount();
	//}

	//if (g_Position.y > COMBO_POS_Y) {
	//	g_Position.y -= 5.0f;
	//}
}

//======================================================================================
// �`��
//======================================================================================
void DrawCombo()
{
	SetPolygonAngle(0.0f);
	SetPolygonAlpha(1.0f);

	if (GetScore(2) == 0 && GetScore(2) < 20) {
		SetPolygonColor(1.0f, 1.0f, 1.0f);
	}
	else if (GetScore(2) >= 20 && GetScore(2) < 50) {
		SetPolygonColor(0.0f, 0.5f, 1.0f);
	}
	else if (GetScore(2) >= 50 && GetScore(2) < 80) {
		SetPolygonColor(0.0f, 1.0f, 0.0f);
	}
	else if (GetScore(2) >= 80 && GetScore(2) < 100) {
		SetPolygonColor(1.0f, 1.0f, 0.0f);
	}
	else if (GetScore(2) >= 100) {
		SetPolygonColor(1.0f, 0.0f, 0.0f);
	}
	// �|���S���̏��ݒ�
	SetPolygonPos(g_Position.x, g_Position.y);		// ���W
	SetPolygonSize(COMBO_SIZE_X, COMBO_SIZE_Y);	// �傫��
	SetPolygonAngle(g_Angle);				// ��]�p�x
	// degree(�f�O���[)�l(0~360��)
	// ����radian(���W�A��)�l(0~2��)

	SetPolygonUV(g_TexCoord.x, g_TexCoord.y);	// UV���W
	SetPolygonFrameSize(g_TexFrameSize.x, g_TexFrameSize.y);	// �����c��
	SetPolygonTexture(g_pTexture);

	// �|���S���̕`�揈��
	ID3D11DeviceContext*	pDeviceContext = GetDeviceContext();
	DrawPolygon(pDeviceContext);
}

XMFLOAT3 GetComboPos()
{
	return g_Position;
}
