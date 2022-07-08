//======================================================================================
// �`�F�b�N�|�C���g����
// ����F���o�n
//======================================================================================
#include <stdlib.h>
#include "CheckPoint.h"
#include "Shader.h"
#include "Texture.h"
#include "mesh.h"
#include "Shadow.h"
#include "Player.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_CHECKPOINT	L"data/texture/UI/Check.png"

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define CHECKPOINT_RADIUS		(40.0F)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tCheckPoint{
	int			nState;		// ���
	XMFLOAT3	pos;		// ���W
	int			nShadowIdx;	// �e�ԍ�
	bool		CheckFlag;

}tCheckPoint;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexCheckPoint(ID3D11Device* pDevice);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH		g_mesh;		// ���b�V�����
static MATERIAL	g_material;	// �}�e���A�����

static tCheckPoint	g_checkpoint[MAX_CHECKPOINT];

HRESULT LoadCheckPoint(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr = S_OK;

	// �}�e���A���̏����ݒ�
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 50.0f;
	g_material.Emissive = M_EMISSIVE;
	g_mesh.pMaterial = &g_material;

	// �e�N�X�`���̓ǂݍ���
	hr = CreateTextureFromFile(pDevice, TEXTURE_CHECKPOINT, &g_mesh.pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	XMStoreFloat4x4(&g_mesh.mtxTexture, XMMatrixIdentity());
	XMStoreFloat4x4(&g_mesh.mtxWorld, XMMatrixIdentity());

	// ���_���̍쐬
	hr = MakeVertexCheckPoint(pDevice);

	return hr;
}
//=============================================================================
// ����������
//=============================================================================
void InitCheckPoint(void)
{
	// �ϐ��̏�����
	for (int i = 0; i < MAX_CHECKPOINT; i++) {
		g_checkpoint[i].nShadowIdx = -1;
		g_checkpoint[i].nState = 0;
		//g_checkpoint[i].CheckFlag = false;
	}
}

//=============================================================================
// �I������
//=============================================================================
void UninitCheckPoint(void)
{
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT;
		++i, ++pCheckPoint)
	{
		if (pCheckPoint->nState == 0) continue;
		pCheckPoint->nState = 0;
		// �e�Ƃ̊֘A��؂�
		ReleaseShadow(pCheckPoint->nShadowIdx);
		pCheckPoint->nShadowIdx = -1;
	}

	// ���b�V�����
	//for (int i = 0; i < 2; i++) {
	//	ReleaseMesh(&g_mesh[i]);
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateCheckPoint(void)
{
	// �X�V����
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT; i++, ++pCheckPoint)
	{
		if (pCheckPoint->nState == 0) continue;

		// �e�̈ړ�
		MoveShadow(pCheckPoint->nShadowIdx, pCheckPoint->pos);

		// ��ʂɋ߂Â��������
		if (pCheckPoint->pos.z < GetPlayerPos(0).z - 60.0f) {
			DestroyCheckPoint(i);
		}

		// �e������
		if (pCheckPoint->pos.y <= 0.0f) {
			ReleaseShadow(pCheckPoint->nShadowIdx);
			pCheckPoint->nShadowIdx = -1;
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawCheckPoint(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();
	// �����ݒ�
	SetBlendState(BS_ALPHABLEND);

	XMFLOAT4X4 mView = GetCamera()->GetViewMatrix();	// �r���[�}�g���b�N�X
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT; i++, pCheckPoint++) {
		// �o�ĂȂ��e�͏������Ȃ�
		if (pCheckPoint->nState == 0) {
			continue;
		}

		// �r���[�s��̉�]�����̓]�u�s���ݒ�
		g_mesh.mtxWorld._11 = mView._11;
		g_mesh.mtxWorld._12 = mView._21;
		g_mesh.mtxWorld._13 = mView._31;
		g_mesh.mtxWorld._21 = mView._12;
		g_mesh.mtxWorld._22 = mView._22;
		g_mesh.mtxWorld._23 = mView._32;
		g_mesh.mtxWorld._31 = mView._13;
		g_mesh.mtxWorld._32 = mView._23;
		g_mesh.mtxWorld._33 = mView._33;

		// �g��k��
		XMMATRIX mtxScl = XMMatrixScaling(CHECKPOINT_RADIUS, CHECKPOINT_RADIUS, CHECKPOINT_RADIUS);
		XMMATRIX mtxRot;
		mtxRot = XMLoadFloat4x4(&g_mesh.mtxWorld);
		mtxRot = XMMatrixMultiply(mtxRot, mtxScl);
		XMStoreFloat4x4(&g_mesh.mtxWorld, mtxRot);

		// �ʒu�𔽉f
		g_mesh.mtxWorld._41 = pCheckPoint->pos.x;
		g_mesh.mtxWorld._42 = pCheckPoint->pos.y;
		g_mesh.mtxWorld._43 = pCheckPoint->pos.z;

		DrawMesh(pDeviceContext, &g_mesh);
	}
	// ���Ƃɖ߂�
	SetBlendState(BS_NONE);
}

// �ݒu
int SetCheckPoint(XMFLOAT3 pos)
{
	tCheckPoint* pCheckPoint = g_checkpoint;
	for (int i = 0; i < MAX_CHECKPOINT;	++i, ++pCheckPoint)
	{	// �o�����Ă���e�̓X���[
		if (pCheckPoint->nState > 0) continue;

		pCheckPoint->pos = pos;
		pCheckPoint->nState = 1;	// �o��
		// �e�̍쐬
		pCheckPoint->nShadowIdx = CreateShadow(pCheckPoint->pos, 20.0f);

		return i;	// �ԍ���Ԃ�
	}

	return -1;	// ������Ȃ�����
}

XMFLOAT3 GetCheckPointPos(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return XMFLOAT3(0.0f,0.0f,0.0f);
	}

	return g_checkpoint[no].pos;
}

XMFLOAT3 GetCheckPointSize(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	return XMFLOAT3(CHECKPOINT_RADIUS / 2.2f, CHECKPOINT_RADIUS, CHECKPOINT_RADIUS / 2.0f);
}

bool IsCheckPoint(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return false;
	}
	return g_checkpoint[no].nState > 0 ? true : false;	// 0���ぁtrue 0�ȉ���false
}

void DestroyCheckPoint(int no)
{
	if (no < 0 || no >= MAX_CHECKPOINT) {
		return;
	}
	g_checkpoint[no].nState = 0;
	ReleaseShadow(g_checkpoint[no].nShadowIdx);
	g_checkpoint[no].nShadowIdx = -1;
}

bool GetCheckFlag(int no)
{
	return g_checkpoint[no].CheckFlag;
}

void SetCheckFlag(int no, bool flag)
{
	g_checkpoint[no].CheckFlag = flag;
}

HRESULT MakeVertexCheckPoint(ID3D11Device* pDevice)
{
	VERTEX_3D vertexWk[NUM_VERTEX]; //��Ɨp���_���
	int		  indexWk[NUM_VERTEX];	//��Ɨp�C���f�b�N�X

	// ���_���W�̐ݒ�
	g_mesh.nNumVertex = NUM_VERTEX;
	vertexWk[0].vtx = XMFLOAT3(-0.5f, 0.5f, 0.0f);
	vertexWk[1].vtx = XMFLOAT3(0.5f, 0.5f, 0.0f);
	vertexWk[2].vtx = XMFLOAT3(-0.5f, -0.5f, 0.0f);
	vertexWk[3].vtx = XMFLOAT3(0.5f, -0.5f, 0.0f);

	// �f�B�t���[�Y�̐ݒ�
	vertexWk[0].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[1].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[2].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[3].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	// �@���x�N�g���̐ݒ�
	vertexWk[0].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);
	vertexWk[1].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);
	vertexWk[2].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);
	vertexWk[3].nor = XMFLOAT3(0.0f, 0.0f, -1.0f);

	// �e�N�X�`�����W�̐ݒ�
	vertexWk[0].tex = XMFLOAT2(0.0f, 0.0f);
	vertexWk[1].tex = XMFLOAT2(1.0f, 0.0f);
	vertexWk[2].tex = XMFLOAT2(0.0f, 1.0f);
	vertexWk[3].tex = XMFLOAT2(1.0f, 1.0f);

	// �C���f�b�N�X�z��̐ݒ�
	g_mesh.nNumIndex = NUM_VERTEX;
	indexWk[0] = 0;
	indexWk[1] = 1;
	indexWk[2] = 2;
	indexWk[3] = 3;

	return MakeMeshVertex(pDevice, &g_mesh, vertexWk, indexWk);
}