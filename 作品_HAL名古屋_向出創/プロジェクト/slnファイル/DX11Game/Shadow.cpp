//=============================================================================
// �e����
// ����F���o�n
//=============================================================================
#include "Shadow.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_SHADOW	L"data/texture/shadow000.jpg"	// �e�N�X�`��

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define MAX_SHADOW		(200)			// �e�̐�

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tShadow
{
	int			nState;		// ���
	XMFLOAT3	pos;		// ���W
	float		fRadius;	// ���a
}tShadow;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexShadow(ID3D11Device* pDevice);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH		g_mesh;		// ���b�V�����i�I�u�W�F�N�g�̕\�ʁj
static MATERIAL	g_material;	// �}�e���A�����

static tShadow g_shadow[MAX_SHADOW];	// �e�X�g�b�N

HRESULT LoadShadow(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr;

	// �ʒu��]�g�嗦�̏�����
	g_mesh.scl = XMFLOAT3(1.0f, 1.0f, 1.0f);
	g_mesh.pos = XMFLOAT3(0.0f, 0.0f, 0.0f);
	g_mesh.rot = XMFLOAT3(0.0f, 0.0f, 0.0f);	//X���@�E�{�@Y���@��{�@Z���@���{

	// �}�e���A���̏����ݒ�
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 1.0f;
	g_material.Emissive = M_EMISSIVE;
	g_mesh.pMaterial = &g_material;

	// �e�N�X�`���̓ǂݍ���
	hr = CreateTextureFromFile(pDevice, TEXTURE_SHADOW, &g_mesh.pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	XMStoreFloat4x4(&g_mesh.mtxTexture, XMMatrixIdentity());
	XMStoreFloat4x4(&g_mesh.mtxWorld, XMMatrixIdentity());

	// ���_���̍쐬
	hr = MakeVertexShadow(pDevice);

	return hr;
}

//=============================================================================
// ����������
//=============================================================================
void InitShadow(void)
{
	// �\���̕ϐ�������
	for (int i = 0; i < MAX_SHADOW; i++) {
		g_shadow[i].nState = 0;
	}
}

//=============================================================================
// �I������
//=============================================================================
void UninitShadow(void)
{
	// ���b�V�����
	//ReleaseMesh(&g_mesh);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateShadow(void)
{
	// ���b�V���X�V
	UpdateMesh(&g_mesh);
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawShadow(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// ���Z�����ݒ�
	SetBlendState(BS_SUBTRACTION);

	// ���b�V���̕`��
	tShadow* pShadow = g_shadow;
	for (int i = 0; i < MAX_SHADOW; i++, pShadow++) {
		// �o�ĂȂ��e�͕`�悵�Ȃ�
		if (pShadow->nState == 0) {
			continue;
		}

		// �{��
		float ratio = pShadow->pos.y / 320.0f;
		if (ratio < 0.0f)	ratio = 0.0f;
		if (ratio > 1.0f)	ratio = 1.0f;

		// �s�����x
		g_material.Diffuse.w = 0.8f - ratio;
		if (g_material.Diffuse.w < 0.0f)	g_material.Diffuse.w = 0.0f;

		// �T�C�Y
		g_mesh.mtxWorld._11 = g_mesh.mtxWorld._33 = pShadow->fRadius * (1.0f - ratio);

		// �ʒu
		g_mesh.mtxWorld._41 = pShadow->pos.x;
		g_mesh.mtxWorld._42 = 1.0f;
		g_mesh.mtxWorld._43 = pShadow->pos.z;

		DrawMesh(pDeviceContext, &g_mesh);
	}

	// ���ɖ߂�
	SetBlendState(BS_NONE);
}

HRESULT MakeVertexShadow(ID3D11Device* pDevice)
{
	VERTEX_3D vertexWk[NUM_VERTEX]; //��Ɨp���_���
	int		  indexWk[NUM_VERTEX];	//��Ɨp�C���f�b�N�X

	// ���_���W�̐ݒ�
	g_mesh.nNumVertex = NUM_VERTEX;
	vertexWk[0].vtx	= XMFLOAT3(-0.5f, 0.0f,  0.5f);
	vertexWk[1].vtx	= XMFLOAT3( 0.5f, 0.0f,  0.5f);
	vertexWk[2].vtx	= XMFLOAT3(-0.5f, 0.0f, -0.5f);
	vertexWk[3].vtx	= XMFLOAT3( 0.5f, 0.0f, -0.5f);
	
	// �f�B�t���[�Y�̐ݒ�								alpha�l				
	vertexWk[0].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 0.5f);
	vertexWk[1].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 0.5f);
	vertexWk[2].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 0.5f);
	vertexWk[3].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 0.5f);

	// �@���x�N�g���̐ݒ�
	vertexWk[0].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertexWk[1].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertexWk[2].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);
	vertexWk[3].nor = XMFLOAT3(0.0f, 1.0f, 0.0f);

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

// �e�̍쐬
int CreateShadow(XMFLOAT3 pos, float radius)
{
	tShadow* pShadow = g_shadow;
	for (int i = 0; i < MAX_SHADOW; i++, pShadow++) {
		// �o�����Ă���e�̓X���[
		if (pShadow->nState > 0)continue;

		pShadow->pos = pos;
		pShadow->fRadius = radius;
		pShadow->nState = 1;	// �o��
		return i;	// �ԍ���Ԃ�
	}
	return -1;	// ������Ȃ�����
}

// �e�̈ړ�
void MoveShadow(int nShadow, XMFLOAT3 pos)
{
	// ��O����
	if (nShadow < 0 || nShadow >= MAX_SHADOW)	return;

	g_shadow[nShadow].pos = pos;
}

// �e�̉��
void ReleaseShadow(int nShadow)
{
	// ��O����
	if (nShadow < 0 || nShadow >= MAX_SHADOW)	return;

	g_shadow[nShadow].nState = 0;	// ���g�p
}
