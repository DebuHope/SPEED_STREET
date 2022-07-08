//======================================================================================
// �G���h���[������
// ����F���o�n
//======================================================================================
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Endroll.h"
#include "main.h"
#include "Player.h"
#include "Shadow.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define CREDIT01	"data/model/text/CREATOR.fbx"
#define CREDIT02	"data/model/text/SO MUKAIDE.fbx"
#define CREDIT03	"data/model/text/DEVELOPMENT.fbx"
#define CREDIT04	"data/model/text/Visual studio 2017.fbx"
#define CREDIT05	"data/model/text/DirectX 11.fbx"
#define CREDIT06	"data/model/text/C++.fbx"
#define CREDIT07	"data/model/text/MATERIAL.fbx"
#define CREDIT08	"data/model/text/SOUND.fbx"
#define CREDIT09	"data/model/text/LABO.fbx"
#define CREDIT10	"data/model/text/MGURO.fbx"
#define CREDIT11	"data/model/text/3D MODEL.fbx"
#define CREDIT12	"data/model/text/Voxel Town Vol1.fbx"
#define CREDIT13	"data/model/text/Voxel Town Vol2.fbx"
#define CREDIT14	"data/model/text/low-poly-cars-3d-model.fbx"
#define CREDIT15	"data/model/text/ENEMY.fbx"
#define CREDIT16	"data/model/text/PLiCy.fbx"
#define CREDIT17	"data/model/text/SOFTWARE.fbx"
#define CREDIT18	"data/model/text/GIMP.fbx"
#define CREDIT19	"data/model/text/Photoshop.fbx"
#define CREDIT20	"data/model/text/Blender.fbx"
#define CREDIT21	"data/model/text/MAYA.fbx"
#define CREDIT22	"data/model/text/TEST PLAY.fbx"
#define CREDIT23	"data/model/text/MASAYA KATO.fbx"
#define CREDIT24	"data/model/text/SHOEI HIRAMATSU.fbx"
#define CREDIT25	"data/model/text/TOMOYA FUJIOKA.fbx"
#define CREDIT26	"data/model/text/YU OSHIMA.fbx"
#define CREDIT27	"data/model/text/THANK_YOU_FOR_PLAYING.fbx"

#define MAX_TEXT_MODEL		(27)

#define TEXT_SPEED		(1.0f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tText
{
	XMFLOAT4X4	mtxWorld;

	int	nType;	// ���
	XMFLOAT3 pos;	// ���W
	XMFLOAT3 rot;	// ��]
	XMFLOAT3 scl;	// �g�嗦
	XMFLOAT3 vel;	// ���x

	int nShadowIdx;

	bool		KillFlag;	// �L���t���O

	int		nState;	// �s��(0�ȉ�:���g�p 1�ȏ�:�ʏ�)
}tText;

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static CAssimpModel	g_model[MAX_TEXT_MODEL];	// ���f���f�[�^
static tText			g_text[MAX_TEXT];

HRESULT LoadText(void)
{
	HRESULT hr = S_OK;
	ID3D11Device* pDevice = GetDevice();
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// ���f���f�[�^�̓ǂݍ���
	hr = g_model[0].Load(pDevice, pDeviceContext,
		CREDIT01);
	hr = g_model[1].Load(pDevice, pDeviceContext,
		CREDIT02);
	hr = g_model[2].Load(pDevice, pDeviceContext,
		CREDIT03);
	hr = g_model[3].Load(pDevice, pDeviceContext,
		CREDIT04);
	hr = g_model[4].Load(pDevice, pDeviceContext,
		CREDIT05);
	hr = g_model[5].Load(pDevice, pDeviceContext,
		CREDIT06);
	hr = g_model[6].Load(pDevice, pDeviceContext,
		CREDIT07);
	hr = g_model[7].Load(pDevice, pDeviceContext,
		CREDIT08);
	hr = g_model[8].Load(pDevice, pDeviceContext,
		CREDIT09);
	hr = g_model[9].Load(pDevice, pDeviceContext,
		CREDIT10);
	hr = g_model[10].Load(pDevice, pDeviceContext,
		CREDIT11);
	hr = g_model[11].Load(pDevice, pDeviceContext,
		CREDIT12);
	hr = g_model[12].Load(pDevice, pDeviceContext,
		CREDIT13);
	hr = g_model[13].Load(pDevice, pDeviceContext,
		CREDIT14);
	hr = g_model[14].Load(pDevice, pDeviceContext,
		CREDIT15);
	hr = g_model[15].Load(pDevice, pDeviceContext,
		CREDIT16);
	hr = g_model[16].Load(pDevice, pDeviceContext,
		CREDIT17);
	hr = g_model[17].Load(pDevice, pDeviceContext,
		CREDIT18);
	hr = g_model[18].Load(pDevice, pDeviceContext,
		CREDIT19);
	hr = g_model[19].Load(pDevice, pDeviceContext,
		CREDIT20);
	hr = g_model[20].Load(pDevice, pDeviceContext,
		CREDIT21);
	hr = g_model[21].Load(pDevice, pDeviceContext,
		CREDIT22);
	hr = g_model[22].Load(pDevice, pDeviceContext,
		CREDIT23);
	hr = g_model[23].Load(pDevice, pDeviceContext,
		CREDIT24);
	hr = g_model[24].Load(pDevice, pDeviceContext,
		CREDIT25);
	hr = g_model[25].Load(pDevice, pDeviceContext,
		CREDIT26);
	hr = g_model[26].Load(pDevice, pDeviceContext,
		CREDIT27);

	return hr;
}

//=============================================================================
// ����������
//=============================================================================
void InitText(void)
{
	// �ʒu�E��]�E�X�P�[���̏����ݒ�
	for (int i = 0; i < MAX_TEXT; i++)
	{
		g_text[i].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
		g_text[i].rot = XMFLOAT3(0.0f, 180.0f, 0.0f);
		g_text[i].scl = XMFLOAT3(1.5f, 1.5f, 5.0f);
		g_text[i].vel = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_text[i].nState = 0;	// �����͑��݂��Ȃ�
		g_text[i].KillFlag = false;
	}

	// ���[���h�}�g���b�N�X�̏�����
	XMMATRIX mtxWorld;
	mtxWorld = XMMatrixIdentity();
	for (int i = 0; i < MAX_TEXT; i++)
	{
		XMStoreFloat4x4(&g_text[i].mtxWorld, mtxWorld);
	}
}

//=============================================================================
// �I������
//=============================================================================
void UninitText(void)
{
	// �e�̉��
	for (int i = 0; i < MAX_TEXT; i++) {
		ReleaseShadow(g_text[i].nShadowIdx);
	}
	// ���f���̉��
	//for (int i = 0; i < MAX_TEXT_MODEL; i++) {
	//	g_model[i].Release();
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateText(void)
{
	for (int i = 0; i < MAX_TEXT; i++)
	{
		if (g_text[i].nState == 0)	continue;

		// ���f���̓������L�q����Ȃ炱��========================================

		// �L���t���O���������ꍇ
		if (g_text[i].KillFlag == true) {
			// �d�͂����W�ɉ��Z
			g_text[i].vel.y -= 0.5f;
		}

		if (g_text[i].pos.z < GetPlayerPos(0).z + 3200.0f) {

			// �ʒu�̍X�V
			g_text[i].pos.x += g_text[i].vel.x;
			g_text[i].pos.y += g_text[i].vel.y;
			g_text[i].pos.z += g_text[i].vel.z;
		}

		// ��ʂɋ߂Â��������
		if (g_text[i].pos.z < GetPlayerPos(0).z - 5000.0f) {
			DestroyText(i);
		}

		// �e������
		if (g_text[i].pos.y <= 0.0f) {
			ReleaseShadow(g_text[i].nShadowIdx);
			g_text[i].nShadowIdx = -1;
		}
		// ===================================================================

		// ���[���h�}�g���b�N�X�̏�����
		XMMATRIX mtxWorld, mtxRot, mtxScl, mtxTranslate;
		mtxWorld = XMMatrixIdentity();

		// �X�P�[���𔽉f
		mtxScl = XMMatrixScaling(
			g_text[i].scl.x,
			g_text[i].scl.y,
			g_text[i].scl.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxScl);

		// ��]�𔽉f
		mtxRot = XMMatrixRotationRollPitchYaw(
			XMConvertToRadians(g_text[i].rot.x),
			XMConvertToRadians(g_text[i].rot.y),
			XMConvertToRadians(g_text[i].rot.z)
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxRot);

		// �ړ��𔽉f
		mtxTranslate = XMMatrixTranslation(
			g_text[i].pos.x,
			g_text[i].pos.y,
			g_text[i].pos.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxTranslate);

		// ���[���h�}�g���b�N�X�ݒ�
		XMStoreFloat4x4(&g_text[i].mtxWorld, mtxWorld);

		// �e�̈ړ�
		MoveShadow(g_text[i].nShadowIdx, g_text[i].pos);
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawTex(void)
{
	for (int i = 0; i < MAX_TEXT; i++)
	{
		if (g_text[i].pos.z > GetPlayerPos(0).z - 5000.0f) {
			ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

			// ���f���\��
			if (g_text[i].nState == 0)	continue;
			g_model[g_text[i].nType].Draw(pDeviceContext, g_text[i].mtxWorld);
		}
	}
}

// �ݒu
int SetText(XMFLOAT3 pos, XMFLOAT3 scl, XMFLOAT3 dir, int type)
{
	_tText* pText = g_text;
	for (int i = 0; i < MAX_TEXT; ++i, ++pText)
	{	// �o�����Ă���ꍇ�X���[
		if (pText->nState != 0) continue;

		pText->pos = pos;
		pText->scl = scl;
		pText->scl.z = scl.z = 8.0f;
		pText->vel.x = dir.x * TEXT_SPEED;
		pText->vel.y = dir.y * TEXT_SPEED;
		pText->vel.z = dir.z * TEXT_SPEED;
		pText->nState = 1;	// �o��
		pText->nType = type;

		// �e�̍쐬
		pText->nShadowIdx = CreateShadow(pText->pos, 20.0f);

		return i;	// �ԍ���Ԃ�
	}
	return -1;	// ������Ȃ�����
}

XMFLOAT4X4 GetTextWorld(int no)
{
	return g_text[no].mtxWorld;
}

// ���S���W����
XMFLOAT3 GetTextCenter(int no)
{
	if (no < 0 || no >= MAX_TEXT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	XMFLOAT3 pos = g_model[g_text[no].nType].GetCenter();
	pos.x += g_text[no].pos.x;
	pos.y += g_text[no].pos.y;
	pos.z += g_text[no].pos.z;
	return pos;
}

// ���f���T�C�Y����
XMFLOAT3 GetTextBBox(int no)
{
	if (no < 0 || no >= MAX_TEXT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	// ���f������T�C�Y����������
	XMFLOAT3 size = g_model[g_text[no].nType].GetBBox();
	return XMFLOAT3(
		size.x * g_text[no].scl.x,
		size.y * (g_text[no].scl.y),
		size.z * g_text[no].scl.z);
}

// ���W����
XMFLOAT3 GetTextPos(int no)
{
	if (no < 0 || no >= MAX_TEXT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_text[no].pos;
}

// �T�C�Y����
XMFLOAT3 GetTextSize(int no)
{
	if (no < 0 || no >= MAX_TEXT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return XMFLOAT3(g_text[no].scl.x * 2.0f, g_text[no].scl.y, g_text[no].scl.z);
}

// �������Ă��邩
bool IsText(int no)
{
	if (no < 0 || no >= MAX_TEXT || g_text[no].KillFlag == true) {
		return false;
	}
	return true;
}

// �\�����Ȃ�
void DestroyText(int no)
{
	if (no < 0 || no >= MAX_TEXT) {
		return;
	}
	g_text[no].nState = 0;
	ReleaseShadow(g_text[no].nShadowIdx);
	g_text[no].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
}

void KillText(int no)
{
	if (no < 0 || no >= MAX_TEXT) {
		return;
	}

	if (rand() % 2 == 0) {
		g_text[no].vel = XMFLOAT3((float)((rand() % 5) + 2), (float)((rand() % 10) + 7), (float)((rand() % 5) + 6));
	}
	else {
		g_text[no].vel = XMFLOAT3((float)((-rand() % 5) - 2), (float)((rand() % 10) + 7), (float)((rand() % 5) + 6));
	}

	g_text[no].KillFlag = true;
}
