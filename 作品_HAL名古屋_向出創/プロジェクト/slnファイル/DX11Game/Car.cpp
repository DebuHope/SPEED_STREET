//======================================================================================
// �ԏ���
// ����F���o�n
//======================================================================================
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Car.h"
#include "Shadow.h"
#include "main.h"
#include "Player.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define MODEL_BASIC	"data/model/car/basic1.fbx"
#define MODEL_TAXI	"data/model/car/taxi1.fbx"
#define MODEL_TRACK	"data/model/car/track.fbx"
#define MODEL_RACE	"data/model/car/race1.fbx"
#define MODEL_COP	"data/model/car/cop1.fbx"

#define MAX_CAR_MODEL		(5)

#define CAR_SPEED		(1.0f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tCar
{
	XMFLOAT4X4	mtxWorld;

	int	nType;	// ���
	XMFLOAT3 pos;	// ���W
	XMFLOAT3 rot;	// ��]
	XMFLOAT3 scl;	// �g�嗦
	XMFLOAT3 vel;	// ���x

	int		nState;	// �s��(0�ȉ�:���g�p 1�ȏ�:�ʏ�)
	int		nShadowIdx;	// �e�̔ԍ�
}tCar;

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static CAssimpModel	g_model[MAX_CAR_MODEL];	// ���f���f�[�^
static tCar			g_car[MAX_CAR];

HRESULT LoadCar(void)
{
	HRESULT hr = S_OK;
	ID3D11Device* pDevice = GetDevice();
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// ���f���f�[�^�̓ǂݍ���
	hr = g_model[0].Load(pDevice, pDeviceContext,
		MODEL_BASIC);
	hr = g_model[1].Load(pDevice, pDeviceContext,
		MODEL_TAXI);
	hr = g_model[2].Load(pDevice, pDeviceContext,
		MODEL_TRACK);
	hr = g_model[3].Load(pDevice, pDeviceContext,
		MODEL_RACE);
	hr = g_model[4].Load(pDevice, pDeviceContext,
		MODEL_COP);

	return hr;
}

//=============================================================================
// ����������
//=============================================================================
void InitCar(void)
{
	// �ʒu�E��]�E�X�P�[���̏����ݒ�
	for (int i = 0; i < MAX_CAR; i++)
	{
		g_car[i].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
		g_car[i].rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_car[i].scl = XMFLOAT3(1.0f, 1.0f, 1.0f);
		g_car[i].vel = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_car[i].nState = 0;	// �����͑��݂��Ȃ�
	}

	// ���[���h�}�g���b�N�X�̏�����
	XMMATRIX mtxWorld;
	mtxWorld = XMMatrixIdentity();
	for (int i = 0; i < MAX_CAR; i++)
	{
		XMStoreFloat4x4(&g_car[i].mtxWorld, mtxWorld);
	}
}

//=============================================================================
// �I������
//=============================================================================
void UninitCar(void)
{
	// �e�̉��
	for (int i = 0; i < MAX_CAR; i++) {
		ReleaseShadow(g_car[i].nShadowIdx);
	}
	// ���f���̉��
	//for (int i = 0; i < MAX_CAR_MODEL; i++) {
	//	g_model[i].Release();
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateCar(void)
{
	for (int i = 0; i < MAX_CAR; i++)
	{
		if (g_car[i].nState == 0)	continue;

		// ���f���̓������L�q����Ȃ炱��========================================

		if (g_car[i].pos.z < GetPlayerPos(0).z + 3200.0f) {

			// �ʒu�̍X�V
			g_car[i].pos.x += g_car[i].vel.x;
			g_car[i].pos.y += g_car[i].vel.y;
			g_car[i].pos.z += g_car[i].vel.z;
		}

		// ��ʂɋ߂Â��������
		if (g_car[i].pos.z < GetPlayerPos(0).z - 5000.0f) {
			DestroyCar(i);
		}

		if (g_car[i].pos.z < GetPlayerPos(0).z - 500.0f) {
			g_car[i].rot.y = 180.0f;
		}
		// ===================================================================

		// ���[���h�}�g���b�N�X�̏�����
		XMMATRIX mtxWorld, mtxRot, mtxScl, mtxTranslate;
		mtxWorld = XMMatrixIdentity();

		// �X�P�[���𔽉f
		mtxScl = XMMatrixScaling(
			g_car[i].scl.x,
			g_car[i].scl.y,
			g_car[i].scl.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxScl);

		// ��]�𔽉f
		mtxRot = XMMatrixRotationRollPitchYaw(
			XMConvertToRadians(g_car[i].rot.x),
			XMConvertToRadians(g_car[i].rot.y),
			XMConvertToRadians(g_car[i].rot.z)
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxRot);

		// �ړ��𔽉f
		mtxTranslate = XMMatrixTranslation(
			g_car[i].pos.x,
			g_car[i].pos.y,
			g_car[i].pos.z
		);
		mtxWorld = XMMatrixMultiply(mtxWorld, mtxTranslate);

		// ���[���h�}�g���b�N�X�ݒ�
		XMStoreFloat4x4(&g_car[i].mtxWorld, mtxWorld);

		// �e�̈ړ�
		MoveShadow(g_car[i].nShadowIdx, g_car[i].pos);
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawCar(void)
{
	for (int i = 0; i < MAX_CAR; i++)
	{
		if (g_car[i].pos.z > GetPlayerPos(0).z - 200.0f) {
			ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

			// ���f���\��
			if (g_car[i].nState == 0)	continue;
			g_model[g_car[i].nType].Draw(pDeviceContext, g_car[i].mtxWorld);
		}
	}
}

// �ԃX�|�[��
int SetCar(XMFLOAT3 pos, XMFLOAT3 dir, int type)
{
	_tCar* pCar = g_car;
	for (int i = 0; i < MAX_CAR; ++i, ++pCar)
	{	// �o�����Ă���ꍇ�X���[
		if (pCar->nState != 0) continue;

		pCar->pos = pos;
		pCar->vel.x = dir.x * CAR_SPEED;
		pCar->vel.y = dir.y * CAR_SPEED;
		pCar->vel.z = dir.z * CAR_SPEED;
		pCar->nState = 1;	// �o��
		pCar->nType = type;

		// �e�̍쐬
		pCar->nShadowIdx = CreateShadow(pCar->pos, 90.0f);

		return i;	// �ԍ���Ԃ�
	}
	return -1;	// ������Ȃ�����
}

XMFLOAT4X4 GetCarWorld(int no)
{
	return g_car[no].mtxWorld;
}

// ���S���W����
XMFLOAT3 GetCarCenter(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	XMFLOAT3 pos = g_model[g_car[no].nType].GetCenter();
	pos.x += g_car[no].pos.x;
	pos.y += g_car[no].pos.y;
	pos.z += g_car[no].pos.z;
	return pos;
}

// ���f���T�C�Y����
XMFLOAT3 GetCarBBox(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	// ���f������T�C�Y����������
	XMFLOAT3 size = g_model[g_car[no].nType].GetBBox();
	return XMFLOAT3(
		size.x * g_car[no].scl.x,
		size.y * (g_car[no].scl.y / 3.0f),
		size.z * g_car[no].scl.z);
}

// ���W����
XMFLOAT3 GetCarPos(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_car[no].pos;
}

// �T�C�Y����
XMFLOAT3 GetCarSize(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_car[no].scl;
}

// �������Ă��邩
bool IsCar(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return false;
	}
	return true;
}

// �\�����Ȃ�
void DestroyCar(int no)
{
	if (no < 0 || no >= MAX_CAR) {
		return;
	}
	g_car[no].nState = 0;
	ReleaseShadow(g_car[no].nShadowIdx);
	g_car[no].nShadowIdx = -1;
	g_car[no].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
}