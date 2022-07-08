//======================================================================================
// �w�i
// ����F���o�n
//======================================================================================

// �w�b�_�t�@�C���̃C���N���[�h
#include"bg.h"
#include"Texture.h"
#include"polygon.h"
#include "Player.h"
#include "UI.h"

// �}�N����`
#define BG_POS_X	(0)
#define BG_POS_Y	(0)
#define BG_SIZE_X	(SCREEN_WIDTH)	// �E�B���h�E�̕��Ɠ����T�C�Y
#define BG_SIZE_Y	(SCREEN_HEIGHT)	// �E�B���h�E�̍����Ɠ����T�C�Y

#define MAX_TEXTURE (7)

#define BG_STAGE1		_T("data/texture/sky.png")
#define BG_STAGE2		_T("data/texture/yuyake.png")
#define BG_STAGE3		_T("data/texture/night.png")
#define BG_HOLE			_T("data/texture/hole2.png")
#define BG_IKEHOLE		_T("data/texture/ikeHole.png")
#define BG_HOLE3		_T("data/texture/hole5.png")
#define BG_TITLE		_T("data/texture/UI/TitleScreen.png")

// �O���[�o���ϐ��錾
static ID3D11ShaderResourceView* g_pTexture[MAX_TEXTURE];	// �e�N�X�`��	

static XMFLOAT3 g_Position;		// ���W
static XMFLOAT2 g_Size;			// �T�C�Y
static float	g_Angle;		// ��]�p�x
static float	g_Alpha;		// �����x

static int DrawBGNo;

static XMFLOAT2 g_TexCoord;		// �e�N�X�`�����W(�|���S���̍���)(TextureCoordinate)
static XMFLOAT2 g_TexFrameSize;	// �e�N�X�`����\��t����T�C�Y

static bool temp;

HRESULT LoadBg()
{
	HRESULT hr = S_OK;
	ID3D11Device*	pDevice = GetDevice();

	hr = CreateTextureFromFile(pDevice, BG_STAGE1, &g_pTexture[0]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, BG_STAGE2, &g_pTexture[1]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, BG_STAGE3, &g_pTexture[2]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, BG_HOLE, &g_pTexture[3]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, BG_TITLE, &g_pTexture[4]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, BG_IKEHOLE, &g_pTexture[5]);
	if (FAILED(hr)) return hr;
	hr = CreateTextureFromFile(pDevice, BG_HOLE3, &g_pTexture[6]);
	if (FAILED(hr)) return hr;

	return hr;
}

//======================================================================================
// ������
//======================================================================================
void InitBg()
{
	// �p�����[�^�̏�����
	g_Position		= XMFLOAT3(BG_POS_X, BG_POS_Y, 0.0f);
	g_Size			= XMFLOAT2(BG_SIZE_X, BG_SIZE_Y);
	g_Angle			= 0.0f;
	g_TexCoord		= XMFLOAT2(0.0f, 0.0f);
	g_TexFrameSize	= XMFLOAT2(1.0f, 1.0f);
	temp = false;

	DrawBGNo = 0;
}

//======================================================================================
// �I��
//======================================================================================
void UninitBg()
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
void UpdateBg()
{
	if (temp == false) {
		g_Alpha -= 0.05f;
		if (g_Alpha < 0.0f)	temp = true;
	}
	else if (temp == true) {
		g_Alpha += 0.1f;
		if (g_Alpha > 2.0f)	temp = false;
	}

	if (GetUIState() == 0) DrawBGNo = 0;
	else if (GetUIState() == 1) DrawBGNo = 1;
	else if (GetUIState() == 2) DrawBGNo = 2;
}

//======================================================================================
// �`��
//======================================================================================
void DrawBg()
{
	SetPolygonAngle(0.0f);				// ��]�p�x
	SetPolygonAlpha(1.0f);
	SetPolygonColor(1.0f, 1.0f, 1.0f);
	// �|���S���̏��ݒ�
	SetPolygonPos(BG_POS_X, BG_POS_Y);		// ���W
	SetPolygonSize(BG_SIZE_X, BG_SIZE_Y);	// �傫��
	SetPolygonAngle(g_Angle);				// ��]�p�x
	// degree(�f�O���[)�l(0~360��)
	// ����radian(���W�A��)�l(0~2��)

	SetPolygonUV(g_TexCoord.x, g_TexCoord.y);	// UV���W
	SetPolygonFrameSize(g_TexFrameSize.x, g_TexFrameSize.y);	// �����c��
	if (GetSceneNo() == SCENE_TITLE) {
		SetPolygonTexture(g_pTexture[4]);
	}
	else if (GetPlayerPhose(0) == FALL && GetPlayerCenter(0).y <= -80.0f) {

		if(GetSceneNo() == SCENE_SELECT && GetPlayerPhose(0) == FALL)	SetPolygonTexture(g_pTexture[3]);	// �e�N�X�`���w��

		switch (GetSceneNo())
		{
		case SCENE_STAGE1_1:
		case SCENE_STAGE1_2:
		case SCENE_STAGE1_3:
		case SCENE_STAGE1_4:
			SetPolygonTexture(g_pTexture[3]);	// �e�N�X�`���w��
			break;
		case SCENE_STAGE2_1:
		case SCENE_STAGE2_2:
		case SCENE_STAGE2_3:
		case SCENE_STAGE2_4:
			SetPolygonTexture(g_pTexture[5]);	// �e�N�X�`���w��
			break;
		case SCENE_STAGE3_1:
		case SCENE_STAGE3_2:
		case SCENE_STAGE3_3:
		case SCENE_STAGE3_4:
			SetPolygonTexture(g_pTexture[6]);	// �e�N�X�`���w��
			break;
		}
	}
	else if (GetSceneNo() == SCENE_ENDING) {
		SetPolygonTexture(g_pTexture[0]);	// �e�N�X�`���w��
	}
	else {
		SetPolygonTexture(g_pTexture[DrawBGNo]);
	}

	// �|���S���̕`�揈��
	ID3D11DeviceContext*	pDeviceContext = GetDeviceContext();
	DrawPolygon(pDeviceContext);
}