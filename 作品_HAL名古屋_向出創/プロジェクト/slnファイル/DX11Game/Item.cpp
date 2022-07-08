//======================================================================================
// �A�C�e������
// ����F���o�n
//======================================================================================
#include <stdlib.h>
#include "Item.h"
#include "Shader.h"
#include "Texture.h"
#include "mesh.h"
#include "Shadow.h"
#include "Player.h"
#include "Score.h"
#include "Polygon.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_ITEM	L"data/texture/icon_Lollipop2.png"

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tItem{
	int			nState;		// ���
	XMFLOAT3	pos;		// ���W
	XMFLOAT3	scl;
	XMFLOAT3	vel;
	int			nShadowIdx;	// �e�ԍ�

}tItem;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexItem(ID3D11Device* pDevice);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH		g_mesh;		// ���b�V�����
static MATERIAL	g_material;	// �}�e���A�����
static tItem	g_item[MAX_ITEM];	// �e�X�g�b�N

HRESULT LoadItem(void)
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
	hr = CreateTextureFromFile(pDevice, TEXTURE_ITEM, &g_mesh.pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	XMStoreFloat4x4(&g_mesh.mtxTexture, XMMatrixIdentity());
	XMStoreFloat4x4(&g_mesh.mtxWorld, XMMatrixIdentity());

	// ���_���̍쐬
	hr = MakeVertexItem(pDevice);

	return hr;
}
//=============================================================================
// ����������
//=============================================================================
void InitItem(void)
{
	// �ϐ��̏�����
	for (int i = 0; i < MAX_ITEM; i++) {
		g_item[i].nShadowIdx = -1;
		g_item[i].nState = 0;
		g_item[i].vel = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_item[i].scl = XMFLOAT3(17.0f, 17.0f, 17.0f);
	}
}

//=============================================================================
// �I������
//=============================================================================
void UninitItem(void)
{
	tItem* pItem = g_item;
	for (int i = 0; i < MAX_ITEM;
		++i, ++pItem)
	{
		if (pItem->nState == 0) continue;
		pItem->nState = 0;
		// �e�Ƃ̊֘A��؂�
		ReleaseShadow(pItem->nShadowIdx);
		pItem->nShadowIdx = -1;
	}

	// ���b�V�����
	//for (int i = 0; i < 2; i++) {
	//	ReleaseMesh(&g_mesh[i]);
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateItem(void)
{
	// �X�V����
	tItem* pItem = g_item;
	for (int i = 0; i < MAX_ITEM; i++, ++pItem)
	{
		if (pItem->nState == 0) continue;

		// �e�̈ړ�
		MoveShadow(pItem->nShadowIdx, pItem->pos);

		// �ʒu�̍X�V
		pItem->pos.x += pItem->vel.x;
		pItem->pos.y += pItem->vel.y;
		pItem->pos.z += pItem->vel.z;

		// ��ʂɋ߂Â��������
		if (pItem->pos.z < GetPlayerPos(0).z - 5000.0f || pItem->pos.y >= 90.0f) {
			pItem->nState = 0;
			DestroyItem(i);
		}

		if (pItem->pos.y >= 90.0f) {
			AddCountItem(1);
		}

		// �e������
		if (pItem->pos.y >= 90.0f) {
			ReleaseShadow(pItem->nShadowIdx);
			pItem->nShadowIdx = -1;
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawItem(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();
	// �����ݒ�
	SetBlendState(BS_ALPHABLEND);

	XMFLOAT4X4 mView = GetCamera()->GetViewMatrix();	// �r���[�}�g���b�N�X
	tItem* pItem = g_item;
	for (int i = 0; i < MAX_ITEM; i++, pItem++) {
		// �o�ĂȂ��e�͏������Ȃ�
		if (pItem->nState == 0 || pItem->pos.z < GetPlayerPos(0).z - 60.0f || pItem->pos.y >= 90.0f) {
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
		XMMATRIX mtxScl = XMMatrixScaling(pItem->scl.x, pItem->scl.y, pItem->scl.z);
		XMMATRIX mtxRot;
		mtxRot = XMLoadFloat4x4(&g_mesh.mtxWorld);
		mtxRot = XMMatrixMultiply(mtxRot, mtxScl);
		XMStoreFloat4x4(&g_mesh.mtxWorld, mtxRot);

		// �ʒu�𔽉f
		g_mesh.mtxWorld._41 = pItem->pos.x;
		g_mesh.mtxWorld._42 = pItem->pos.y;
		g_mesh.mtxWorld._43 = pItem->pos.z;

		DrawMesh(pDeviceContext, &g_mesh);
	}
	// ���Ƃɖ߂�
	SetBlendState(BS_NONE);
}

// �G�X�|�[��
int SetItem(XMFLOAT3 pos, int scl)
{
	tItem* pItem = g_item;
	for (int i = 0; i < MAX_ITEM;	++i, ++pItem)
	{
		if (pItem->nState > 0) continue;

		pItem->pos.x = pos.x;
		pItem->pos.y = pos.y + 20.0f;
		pItem->pos.z = pos.z;
		switch (scl)
		{
		case 0:
			SetPolygonColor(1.0f, 1.0f, 1.0f);
			pItem->scl = XMFLOAT3(17.0f, 17.0f, 17.0f);
			break;
		case 1:
			SetPolygonColor(0.0f, 0.0f, 1.0f);
			pItem->scl = XMFLOAT3(30.0f, 30.0f, 30.0f);
			break;
		}
		pItem->nState = 1;	// �o��
		// �e�̍쐬
		pItem->nShadowIdx = CreateShadow(pItem->pos, 20.0f);

		return i;	// �ԍ���Ԃ�
	}

	return -1;	// ������Ȃ�����
}

XMFLOAT3 GetItemPos(int no)
{
	if (no < 0 || no >= MAX_ITEM) {
		return XMFLOAT3(0.0f,0.0f,0.0f);
	}

	return g_item[no].pos;
}

XMFLOAT3 GetItemSize(int no)
{
	if (no < 0 || no >= MAX_ITEM) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	return XMFLOAT3(g_item[no].scl.x / 2.2f, g_item[no].scl.y, g_item[no].scl.z / 2.0f);
}

bool IsItem(int no)
{
	if (no < 0 || no >= MAX_ITEM || g_item[no].vel.y == 8.0f) {
		return false;
	}
	return g_item[no].nState > 0 ? true : false;	// 0���ぁtrue 0�ȉ���false
}

void DestroyItem(int no)
{
	if (no < 0 || no >= MAX_ITEM) {
		return;
	}
	g_item[no].vel = XMFLOAT3(-15.0f, 8.0f, 15.0f);
	ReleaseShadow(g_item[no].nShadowIdx);
	g_item[no].nShadowIdx = -1;
}

HRESULT MakeVertexItem(ID3D11Device* pDevice)
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