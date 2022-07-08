//======================================================================================
// ���Ƃ�������
// ����F���o�n
//======================================================================================
#include "AssimpModel.h"
#include "Debugproc.h"
#include "Hole.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_HOLE	L"data/texture/hole3.png"
#define TEXTURE_IKE		L"data/texture/ike.png"
#define TEXTURE_HOLE3	L"data/texture/hole4.png"
#define MAX_HOLE_TEXTURE	(3)

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define SIZE_X			(50.0f)
#define SIZE_Y			(0.0f)
#define SIZE_Z			(70.0f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tHole {
	XMFLOAT3 pos;	// �ʒu
	XMFLOAT3 rot;	// ��]
	XMFLOAT3 scl;	// �g��

	int nState;		// ���(0�ȉ�:���g�p 1�ȏ�:�ʏ�)
}tHole;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexHole(ID3D11Device* pDevice, int i);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH			g_mesh[MAX_HOLE_TEXTURE];		// ���b�V�����i�I�u�W�F�N�g�̕\�ʁj
static MATERIAL		g_material;	// �}�e���A�����

static tHole g_hole[MAX_HOLE];	// �t�B�[���h��

int		DrawTexNo;

HRESULT LoadHole(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr;

	// �}�e���A���̏����ݒ�
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 1.0f;
	g_material.Emissive = M_EMISSIVE;

	for (int i = 0; i < MAX_HOLE_TEXTURE; i++) {
		g_mesh[i].pMaterial = &g_material;
	}

	// �e�N�X�`���̓ǂݍ���
	hr = CreateTextureFromFile(pDevice,TEXTURE_HOLE,&g_mesh[0].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_IKE, &g_mesh[1].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_HOLE3, &g_mesh[2].pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	for (int i = 0; i < MAX_HOLE_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, XMMatrixIdentity());
		XMStoreFloat4x4(&g_mesh[i].mtxWorld, XMMatrixIdentity());
	}

	// ���_���̍쐬
	for (int i = 0; i < MAX_HOLE_TEXTURE; i++) {
		hr = MakeVertexHole(pDevice, i);
	}

	return hr;
}

//=============================================================================
// ����������
//=============================================================================
void InitHole(void)
{
	// �ϐ��̏�����
	for (int i = 0; i < MAX_HOLE; i++) {
		g_hole[i].nState = 0;
		g_hole[i].pos = XMFLOAT3(0.0f, -1000.0f, 0.0f);
		g_hole[i].rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_hole[i].scl = XMFLOAT3(1.0f, 1.0f, 1.0f);
	}
	DrawTexNo = 0;
}

//=============================================================================
// �I������
//=============================================================================
void UninitHole(void)
{
	// ���b�V�����
	//ReleaseMesh(&g_mesh);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateHole(void)
{
	for (int i = 0; i < MAX_HOLE; i++) {
		if (g_hole[i].nState == 0)	continue;
		// �ړ��ȂǍX�V���������̉��ɋL�q
		// ====================================================================
		// ====================================================================
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawHole(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();

	// ����������������
	SetBlendState(BS_ALPHABLEND);

	for (int i = 0; i < MAX_HOLE; i++) {
		if (g_hole[i].nState == 0) continue;

		for (int j = 0; j < MAX_HOLE_TEXTURE; j++) {
			g_mesh[j].scl = g_hole[i].scl;
			g_mesh[j].pos = g_hole[i].pos;
			g_mesh[j].rot = g_hole[i].rot;


			// ���b�V���X�V
			UpdateMesh(&g_mesh[j]);
		}
		// ���b�V���̕`��
		switch (GetSceneNo())
		{
		case SCENE_STAGE1_1:
		case SCENE_STAGE1_2:
		case SCENE_STAGE1_3:
		case SCENE_STAGE1_4:
			DrawTexNo = 0;
			break;
		case SCENE_STAGE2_1:
		case SCENE_STAGE2_2:
		case SCENE_STAGE2_3:
		case SCENE_STAGE2_4:
			DrawTexNo = 1;
			break;
		case SCENE_STAGE3_1:
		case SCENE_STAGE3_2:
		case SCENE_STAGE3_3:
		case SCENE_STAGE3_4:
			DrawTexNo = 2;
			break;
		}
		DrawMesh(pDeviceContext, &g_mesh[DrawTexNo]);
	}
	// ����������߂�
	SetBlendState(BS_NONE);
}

HRESULT MakeVertexHole(ID3D11Device* pDevice, int i)
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

// ���o��
int SetHole(XMFLOAT3 pos, XMFLOAT3 scl)
{
	for (int i = 0; i < MAX_HOLE; i++)
	{	// �o�����Ă���e�̓X���[
		if (g_hole[i].nState > 0) continue;

		g_hole[i].pos = pos;
		g_hole[i].scl = scl;
		g_hole[i].nState = 1;	// �o��
		
		return i;	// �ԍ���Ԃ�
	}

	return -1;	// ������Ȃ�����
}

// ���W����
XMFLOAT3 GetHolePos(int no)
{
	if (no < 0 || no >= MAX_HOLE) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return g_hole[no].pos;
}

// �T�C�Y����
XMFLOAT3 GetHoleSize(int no)
{
	if (no < 0 || no >= MAX_HOLE) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}
	return XMFLOAT3(SIZE_X / 1.5f, SIZE_Y, SIZE_Z / 1.6f);
}

// �n�ʂ����邩
bool IsHole(int no)
{
	if (no < 0 || no >= MAX_HOLE) {
		return false;
	}
	return true;
}