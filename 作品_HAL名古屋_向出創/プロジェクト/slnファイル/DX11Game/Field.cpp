//======================================================================================
// �n�ʏ���
// ����F���o�n
//======================================================================================
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Field.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include "UI.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_FIELD1	L"data/texture/asphalt01.png"	// �e�N�X�`��
#define TEXTURE_FIELD2	L"data/texture/grass02.png"	// �e�N�X�`��
#define TEXTURE_FIELD3	L"data/texture/asphalt02.png"	// �e�N�X�`��

#define MAX_FIELD_TEXTURE	(3)

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define SIZE_X			(2000.0f)		// �n�ʂ̃T�C�Y
#define SIZE_Y			(0.0f)
#define SIZE_Z			(1000.0f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tField {
	XMFLOAT3 pos;	// �ʒu
	XMFLOAT3 rot;	// ��]
	XMFLOAT3 scl;	// �g��

	int nState;		// ���(0�ȉ�:���g�p 1�ȏ�:�ʏ�)
}tField;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexField(ID3D11Device* pDevice, int i);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH			g_mesh[MAX_FIELD_TEXTURE];		// ���b�V�����i�I�u�W�F�N�g�̕\�ʁj
static MATERIAL		g_material;	// �}�e���A�����

static tField g_field[MAX_FIELD];	// �t�B�[���h��
static int DrawStreetNo;

HRESULT LoadField(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr = S_OK;

	// �}�e���A���̏����ݒ�
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 1.0f;
	g_material.Emissive = M_EMISSIVE;

	for (int i = 0; i < MAX_FIELD_TEXTURE; i++) {
		g_mesh[i].pMaterial = &g_material;
	}

	// �e�N�X�`���̓ǂݍ���
	hr = CreateTextureFromFile(pDevice, TEXTURE_FIELD1, &g_mesh[0].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_FIELD2, &g_mesh[1].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_FIELD3, &g_mesh[2].pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	for (int i = 0; i < MAX_FIELD_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, XMMatrixIdentity());
		XMStoreFloat4x4(&g_mesh[i].mtxWorld, XMMatrixIdentity());
	}

	// ���_���̍쐬
	for (int i = 0; i < MAX_FIELD_TEXTURE; i++) {
		hr = MakeVertexField(pDevice, i);
	}

	return hr;
}

//=============================================================================
// ����������
//=============================================================================
void InitField(void)
{
	// �ϐ��̏�����
	for (int i = 0; i < MAX_FIELD; i++) {
		g_field[i].nState = 1;
		g_field[i].pos = XMFLOAT3(0.0f, -0.1f, 0.0f);
		g_field[i].rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_field[i].scl = XMFLOAT3(1.0f, 1.0f, 1.0f);
	}
	DrawStreetNo = 0;
}

//=============================================================================
// �I������
//=============================================================================
void UninitField(void)
{
	// ���b�V�����
	//ReleaseMesh(&g_mesh);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateField(void)
{
	for (int i = 0; i < MAX_FIELD; i++) {
		if (g_field[i].nState == 0) {
			continue;
		}
		// �ړ��ȂǍX�V���������̉��ɋL�q
		// ====================================================================
		for (int i = 0; i < MAX_FIELD; i++) {	// 10 = 485
			g_field[i].pos.z = 2000.0f * i;
		}

		if (GetUIState() == 0) DrawStreetNo = 0;
		else if (GetUIState() == 1) DrawStreetNo = 1;
		else if (GetUIState() == 2) DrawStreetNo = 2;
		// ====================================================================
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawField(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// ����������������
	SetBlendState(BS_ALPHABLEND);

	for (int i = 0; i < MAX_FIELD; i++) {
		if (g_field[i].nState == 0) {
			continue;
		}

		for (int j = 0; j < MAX_FIELD_TEXTURE; j++) {
			g_mesh[j].scl = g_field[i].scl;
			g_mesh[j].pos = g_field[i].pos;
			g_mesh[j].rot = g_field[i].rot;

			// ���b�V���X�V
			UpdateMesh(&g_mesh[j]);
		}
		// ���b�V���̕`��
		DrawMesh(pDeviceContext, &g_mesh[DrawStreetNo]);
	}
	// ����������߂�
	SetBlendState(BS_NONE);
}

HRESULT MakeVertexField(ID3D11Device* pDevice, int i)
{
	VERTEX_3D vertexWk[NUM_VERTEX]; //��Ɨp���_���
	int		  indexWk[NUM_VERTEX];	//��Ɨp�C���f�b�N�X

	// ���_���W�̐ݒ�
	g_mesh[i].nNumVertex = NUM_VERTEX;
	vertexWk[0].vtx	= XMFLOAT3(-SIZE_X, 0.0f,  SIZE_Z);
	vertexWk[1].vtx	= XMFLOAT3( SIZE_X, 0.0f,  SIZE_Z);
	vertexWk[2].vtx	= XMFLOAT3(-SIZE_X, 0.0f, -SIZE_Z);
	vertexWk[3].vtx	= XMFLOAT3( SIZE_X, 0.0f, -SIZE_Z);
	
	// �f�B�t���[�Y�̐ݒ�								alpha�l
	vertexWk[0].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[1].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[2].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertexWk[3].diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

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
	g_mesh[i].nNumIndex = NUM_VERTEX;
	indexWk[0] = 0;
	indexWk[1] = 1;
	indexWk[2] = 2;
	indexWk[3] = 3;

	return MakeMeshVertex(pDevice, &g_mesh[i], vertexWk, indexWk);
}

// ���W����
XMFLOAT3 GetFieldPos(int no)
{
	if (no < 0 || no >= MAX_FIELD) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_field[no].pos;
}

// �T�C�Y����
XMFLOAT3 GetFieldSize(int no)
{
	if (no < 0 || no >= MAX_FIELD) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return XMFLOAT3(SIZE_X, SIZE_Y, SIZE_Z);
}

// �n�ʂ����邩
bool IsField(int no)
{
	if (no < 0 || no >= MAX_FIELD) {
		return false;
	}
	return true;
}