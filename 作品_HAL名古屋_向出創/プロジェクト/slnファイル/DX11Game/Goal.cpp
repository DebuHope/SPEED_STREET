//======================================================================================
// �S�[���|�C���g����
// ����F���o�n
//======================================================================================
#include <stdlib.h>
#include "Goal.h"
#include "Shader.h"
#include "Texture.h"
#include "mesh.h"
#include "Shadow.h"
#include "Player.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_GOAL	L"data/texture/UI/Goal.png"

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define GOAL_RADIUS		(40.0F)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tGoal{
	int			nState;		// ���
	XMFLOAT3	pos;		// ���W
	int			nShadowIdx;	// �e�ԍ�
	bool		CheckFlag;

}tGoal;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexGoal(ID3D11Device* pDevice);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH		g_mesh;		// ���b�V�����
static MATERIAL	g_material;	// �}�e���A�����

static tGoal	g_goal[MAX_GOAL];

HRESULT LoadGoal(void)
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
	hr = CreateTextureFromFile(pDevice, TEXTURE_GOAL, &g_mesh.pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	XMStoreFloat4x4(&g_mesh.mtxTexture, XMMatrixIdentity());
	XMStoreFloat4x4(&g_mesh.mtxWorld, XMMatrixIdentity());

	// ���_���̍쐬
	hr = MakeVertexGoal(pDevice);

	return hr;
}
//=============================================================================
// ����������
//=============================================================================
void InitGoal(void)
{
	// �ϐ��̏�����
	for (int i = 0; i < MAX_GOAL; i++) {
		g_goal[i].nShadowIdx = -1;
		g_goal[i].nState = 0;
	}
}

//=============================================================================
// �I������
//=============================================================================
void UninitGoal(void)
{
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL;
		++i, ++pGoal)
	{
		if (pGoal->nState == 0) continue;
		pGoal->nState = 0;
		// �e�Ƃ̊֘A��؂�
		ReleaseShadow(pGoal->nShadowIdx);
		pGoal->nShadowIdx = -1;
	}

	// ���b�V�����
	//for (int i = 0; i < 2; i++) {
	//	ReleaseMesh(&g_mesh[i]);
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateGoal(void)
{
	// �X�V����
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL; i++, ++pGoal)
	{
		if (pGoal->nState == 0) continue;

		// �e�̈ړ�
		MoveShadow(pGoal->nShadowIdx, pGoal->pos);

		// ��ʂɋ߂Â��������
		if (pGoal->pos.z < GetPlayerPos(0).z - 60.0f) {
			DestroyGoal(i);
		}

		// �e������
		if (pGoal->pos.y <= 0.0f) {
			ReleaseShadow(pGoal->nShadowIdx);
			pGoal->nShadowIdx = -1;
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawGoal(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();
	// �����ݒ�
	SetBlendState(BS_ALPHABLEND);

	XMFLOAT4X4 mView = GetCamera()->GetViewMatrix();	// �r���[�}�g���b�N�X
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL; i++, pGoal++) {
		// �o�ĂȂ��e�͏������Ȃ�
		if (pGoal->nState == 0) {
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
		XMMATRIX mtxScl = XMMatrixScaling(GOAL_RADIUS, GOAL_RADIUS, GOAL_RADIUS);
		XMMATRIX mtxRot;
		mtxRot = XMLoadFloat4x4(&g_mesh.mtxWorld);
		mtxRot = XMMatrixMultiply(mtxRot, mtxScl);
		XMStoreFloat4x4(&g_mesh.mtxWorld, mtxRot);

		// �ʒu�𔽉f
		g_mesh.mtxWorld._41 = pGoal->pos.x;
		g_mesh.mtxWorld._42 = pGoal->pos.y;
		g_mesh.mtxWorld._43 = pGoal->pos.z;

		DrawMesh(pDeviceContext, &g_mesh);
	}
	// ���Ƃɖ߂�
	SetBlendState(BS_NONE);
}

// �ݒu
int SetGoal(XMFLOAT3 pos)
{
	tGoal* pGoal = g_goal;
	for (int i = 0; i < MAX_GOAL;	++i, ++pGoal)
	{	// �o�����Ă���e�̓X���[
		if (pGoal->nState > 0) continue;

		pGoal->pos = pos;
		pGoal->nState = 1;	// �o��
		// �e�̍쐬
		pGoal->nShadowIdx = CreateShadow(pGoal->pos, 20.0f);

		return i;	// �ԍ���Ԃ�
	}

	return -1;	// ������Ȃ�����
}

XMFLOAT3 GetGoalPos(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return XMFLOAT3(0.0f,0.0f,0.0f);
	}

	return g_goal[no].pos;
}

XMFLOAT3 GetGoalSize(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	return XMFLOAT3(GOAL_RADIUS / 2.2f, GOAL_RADIUS, GOAL_RADIUS / 2.0f);
}

bool IsGoal(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return false;
	}
	return g_goal[no].nState > 0 ? true : false;	// 0���ぁtrue 0�ȉ���false
}

void DestroyGoal(int no)
{
	if (no < 0 || no >= MAX_GOAL) {
		return;
	}
	g_goal[no].nState = 0;
	ReleaseShadow(g_goal[no].nShadowIdx);
	g_goal[no].nShadowIdx = -1;
}

HRESULT MakeVertexGoal(ID3D11Device* pDevice)
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