//======================================================================================
// �n��G����
// ����F���o�n
//======================================================================================
#include <stdlib.h>
#include "DEnemy.h"
#include "Shader.h"
#include "Texture.h"
#include "mesh.h"
#include "Shadow.h"
#include "Player.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_SLIME	L"data/texture/slime.png"	// �e�N�X�`��
#define TEXTURE_SHEEP	L"data/texture/Sheep.png"	// �e�N�X�`��
#define TEXTURE_SLIME2	L"data/texture/slime2.png"	// �e�N�X�`��
#define MAX_DENEMY_TEXTURE	(3)

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define DENEMY_SPEED		(1.0F)	// �G�̑��x

#define GRAVITY			(-0.5f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tDEnemy{
	int			nState;		// ���
	int			nType;		// ���
	XMFLOAT3	pos;		// ���W
	XMFLOAT3	rot;		// ��]
	float		scl;		// �傫��
	XMFLOAT3	vel;		// ���x
	int			nShadowIdx;	// �e�ԍ�

	int			tDivideX;	// �e�N�X�`��������
	int			tDivideY;

	int			nAnimNo;	// �\�����No
	int			nCount;		// �c��t���[����

	bool		KillFlag;	// �L���t���O
}tDEnemy;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexDEnemy(ID3D11Device* pDevice, int i);

void SetTextureDEnemy(const tDEnemy* pDEnemy);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH		g_mesh[MAX_DENEMY_TEXTURE];		// ���b�V�����
static MATERIAL	g_material;	// �}�e���A�����

static tDEnemy	g_denemy[MAX_DENEMY];

static int		DrawTexNo;		// �\������e�N�X�`��No

static float	red;

static ANIM_PAT g_animPat[1][7] = {	// �A�j���[�V�����f�[�^
	{{0,10},{1,10},{2,10},{3,10},{4,10},{5,10},{-1,-1}}
};

HRESULT LoadDEnemy(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr = S_OK;

	// �}�e���A���̏����ݒ�
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 50.0f;
	g_material.Emissive = M_EMISSIVE;

	for (int i = 0; i < MAX_DENEMY_TEXTURE; i++) {
		g_mesh[i].pMaterial = &g_material;
	}

	// �e�N�X�`���̓ǂݍ���
	hr = CreateTextureFromFile(pDevice, TEXTURE_SLIME, &g_mesh[0].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_SHEEP, &g_mesh[1].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_SLIME2, &g_mesh[2].pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	for (int i = 0; i < MAX_DENEMY_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, XMMatrixIdentity());
		XMStoreFloat4x4(&g_mesh[i].mtxWorld, XMMatrixIdentity());
	}

	// ���_���̍쐬
	for (int i = 0; i < MAX_DENEMY_TEXTURE; i++) {
		hr = MakeVertexDEnemy(pDevice, i);
	}

	return hr;
}
//=============================================================================
// ����������
//=============================================================================
void InitDEnemy(void)
{
	// �ϐ��̏�����
	for (int i = 0; i < MAX_DENEMY; i++) {
		g_denemy[i].nShadowIdx = -1;
		g_denemy[i].nState = 0;
		g_denemy[i].rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_denemy[i].scl = 30.0f;
		g_denemy[i].nAnimNo = 0;
		g_denemy[i].nCount = g_animPat[0][g_denemy[i].nAnimNo].nCount;	// �ŏ��̃A�j���\������
		g_denemy[i].nType = 0;
		g_denemy[i].KillFlag = false;

		g_denemy[i].tDivideX = 2;
		g_denemy[i].tDivideY = 1;
	}
	red = 1.0f;
}

//=============================================================================
// �I������
//=============================================================================
void UninitDEnemy(void)
{
	tDEnemy* pDEnemy = g_denemy;
	for (int i = 0; i < MAX_DENEMY;
		++i, ++pDEnemy)
	{
		if (pDEnemy->nState == 0) continue;
		pDEnemy->nState = 0;
		// �e�Ƃ̊֘A��؂�
		ReleaseShadow(pDEnemy->nShadowIdx);
		pDEnemy->nShadowIdx = -1;
	}

	// ���b�V�����
	//for (int i = 0; i < 2; i++) {
	//	ReleaseMesh(&g_mesh[i]);
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateDEnemy(void)
{
	// �X�V����
	tDEnemy* pDEnemy = g_denemy;
	for (int i = 0; i < MAX_DENEMY; i++, ++pDEnemy)
	{
		if (pDEnemy->nState == 0) continue;

		// �L���t���O���������ꍇ
		if (pDEnemy->KillFlag == true) {
			// �d�͂����W�ɉ��Z
			pDEnemy->vel.y += GRAVITY;
		}

		// �e�̈ړ�
		MoveShadow(pDEnemy->nShadowIdx, pDEnemy->pos);

		// ��ʂɋ߂Â��������
		if (pDEnemy->pos.z < GetPlayerPos(0).z - 5000.0f || pDEnemy->pos.y < -20.0f) {
			DestroyDEnemy(i);
		}

		// �����X�V
		if (pDEnemy->pos.z < GetPlayerPos(0).z + 3200.0f) {

			// �Ǐ]
			if (pDEnemy->nType == 1) {
				float tempLength;
				float vecX, vecZ;
				vecX = GetPlayerPos(0).x - pDEnemy->pos.x;
				vecZ = GetPlayerPos(0).z - pDEnemy->pos.z;
				tempLength = sqrtf(vecX*vecX + vecZ * vecZ);
				if (tempLength >= 100.0f)
				{
					pDEnemy->pos.x += vecX / tempLength * 12.0f;
				}
			}

			// �W�����v
			if (pDEnemy->nType == 2) {
				pDEnemy->vel.y += GRAVITY;
				if (pDEnemy->pos.y < 20.0f) {
					pDEnemy->vel.y = 8.0f;
				}
			}

			// ����
			if (pDEnemy->nType == 3 && pDEnemy->pos.z < GetPlayerPos(0).z + 300.0f) {
				pDEnemy->vel.y -= 0.18f;
			}

			// �Ǐ]����
			if (pDEnemy->nType == 4) {
				float tempLength;
				float vecX, vecZ;
				vecX = GetPlayerPos(0).x - pDEnemy->pos.x;
				vecZ = GetPlayerPos(0).z - pDEnemy->pos.z;
				tempLength = sqrtf(vecX*vecX + vecZ * vecZ);
				if (tempLength >= 100.0f)
				{
					pDEnemy->pos.x += vecX / tempLength * 15.0f;
				}

				if (pDEnemy->pos.z < GetPlayerPos(0).z + 300.0f) {
					pDEnemy->vel.y -= 0.18f;
				}
			}

			// �ǂ�����
			if (pDEnemy->nType == 5) {
				float tempLength;
				float vecX, vecZ;
				vecX = GetPlayerPos(0).x - pDEnemy->pos.x;
				vecZ = GetPlayerPos(0).z - pDEnemy->pos.z;
				tempLength = sqrtf(vecX*vecX + vecZ * vecZ);
				if (tempLength >= 200.0f)
				{
					if (!(pDEnemy->pos.z < GetPlayerPos(0).z))	pDEnemy->pos.x += vecX / tempLength * 15.0f;
				}

				if ((pDEnemy->pos.z < GetPlayerPos(0).z - 100.0f)) {
					pDEnemy->vel.z = 20.0f;
					if(pDEnemy->pos.x < 0)	pDEnemy->pos.x = -150.0f;
					if (pDEnemy->pos.x > 0)	pDEnemy->pos.x = 150.0f;
				}

				if (pDEnemy->pos.z > GetPlayerPos(0).z + 800.0f)	pDEnemy->vel.z = 4.5f;
			}

			// �ꏏ�ɃW�����v
			if (pDEnemy->nType == 6) {
				if (pDEnemy->pos.z < GetPlayerPos(0).z + 300.0f && GetPlayerPhose(0) == JUMP) {
					pDEnemy->vel.y -= 0.3f;
					pDEnemy->pos.y += pDEnemy->vel.y;
				}
			}

			// �Ǐ]�ꏏ�ɃW�����v
			if (pDEnemy->nType == 7) {
				float tempLength;
				float vecX, vecZ;
				vecX = GetPlayerPos(0).x - pDEnemy->pos.x;
				vecZ = GetPlayerPos(0).z - pDEnemy->pos.z;
				tempLength = sqrtf(vecX*vecX + vecZ * vecZ);
				if (tempLength >= 300.0f)
				{
					pDEnemy->pos.x += vecX / tempLength * 30.0f;
				}
				if (pDEnemy->pos.z < GetPlayerPos(0).z + 300.0f && GetPlayerPhose(0) == JUMP) {
					pDEnemy->vel.y -= 0.3f;
					pDEnemy->pos.y += pDEnemy->vel.y;
				}
			}

			// �ʒu�̍X�V
			pDEnemy->pos.x += pDEnemy->vel.x;
			if (pDEnemy->nType != 6 && pDEnemy->nType != 7)	pDEnemy->pos.y += pDEnemy->vel.y;
			pDEnemy->pos.z += pDEnemy->vel.z;

		}

		// �e������
		if (pDEnemy->pos.y <= 0.0f) {
			ReleaseShadow(pDEnemy->nShadowIdx);
			pDEnemy->nShadowIdx = -1;
		}

		switch (GetSceneNo())
		{
		case SCENE_STAGE1_1:
		case SCENE_STAGE1_2:
		case SCENE_STAGE1_3:
		case SCENE_STAGE1_4:
			pDEnemy->tDivideX = 2;
			pDEnemy->tDivideY = 1;
			pDEnemy->scl = 30.0f;
			pDEnemy->rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
			DrawTexNo = 0;
			break;
		case SCENE_STAGE2_1:
		case SCENE_STAGE2_2:
		case SCENE_STAGE2_3:
		case SCENE_STAGE2_4:
			pDEnemy->tDivideX = 6;
			pDEnemy->tDivideY = 1;
			pDEnemy->scl = 40.0f;
			if (pDEnemy->nType == 3 || pDEnemy->nType == 4 || pDEnemy->nType == 5)	pDEnemy->scl = 70.0f;
			if (pDEnemy->pos.x > GetPlayerPos(0).x)	pDEnemy->rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
			if (pDEnemy->pos.x < GetPlayerPos(0).x)	pDEnemy->rot = XMFLOAT3(0.0f, 180.0f, 0.0f);
			DrawTexNo = 1;
			break;
		case SCENE_STAGE3_1:
		case SCENE_STAGE3_2:
		case SCENE_STAGE3_3:
		case SCENE_STAGE3_4:
			pDEnemy->tDivideX = 2;
			pDEnemy->tDivideY = 1;
			pDEnemy->scl = 30.0f;
			pDEnemy->rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
			DrawTexNo = 2;
			break;
		}

		// �A�j���[�V�������̍X�V
		pDEnemy->nCount--;	// �c��J�E���g�������炷
		if (pDEnemy->nCount <= 0) {
			pDEnemy->nAnimNo++;	// ���̊G�ɐi�߂�
			if (g_animPat[0][pDEnemy->nAnimNo].nPatNo < 0) {
				// �ԕ����Q�Ƃ�����
				pDEnemy->nAnimNo = 0;	// ����
			}
			// �J�E���g�����̕\���t���[�����ɐݒ�
			pDEnemy->nCount = g_animPat[0][pDEnemy->nAnimNo].nCount;
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawDEnemy(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();
	// �����ݒ�
	SetBlendState(BS_ALPHABLEND);
	
	XMFLOAT4X4 mView = GetCamera()->GetViewMatrix();	// �r���[�}�g���b�N�X
	tDEnemy* pDEnemy = g_denemy;
	for (int i = 0; i < MAX_DENEMY; i++, pDEnemy++) {
		if (pDEnemy->nState == 0 || pDEnemy->pos.z < GetPlayerPos(0).z - 50.0f || pDEnemy->pos.y < -20.0f) {
			continue;
		}

		if (DrawTexNo == 1) {
			if (pDEnemy->pos.x > GetPlayerPos(0).x)	SetCullMode(CULLMODE_CCW);
			if (pDEnemy->pos.x < GetPlayerPos(0).x)	SetCullMode(CULLMODE_CW);
		}

		// �r���[�s��̉�]�����̓]�u�s���ݒ�
		for (int i = 0; i < MAX_DENEMY_TEXTURE; i++) {
			g_mesh[i].mtxWorld._11 = mView._11;
			g_mesh[i].mtxWorld._12 = mView._21;
			g_mesh[i].mtxWorld._13 = mView._31;
			g_mesh[i].mtxWorld._21 = mView._12;
			g_mesh[i].mtxWorld._22 = mView._22;
			g_mesh[i].mtxWorld._23 = mView._32;
			g_mesh[i].mtxWorld._31 = mView._13;
			g_mesh[i].mtxWorld._32 = mView._23;
			g_mesh[i].mtxWorld._33 = mView._33;

			// �g��k��
			XMMATRIX mtxScl = XMMatrixScaling(pDEnemy->scl , pDEnemy->scl, pDEnemy->scl);
			XMMATRIX mtxRot;

			// �����ɉ�]
			mtxRot = XMLoadFloat4x4(&g_mesh[i].mtxWorld);
			mtxRot = XMMatrixRotationRollPitchYaw(
				XMConvertToRadians(pDEnemy->rot.x),
				XMConvertToRadians(pDEnemy->rot.y),
				XMConvertToRadians(pDEnemy->rot.z));
			mtxRot = XMMatrixMultiply(mtxRot, mtxScl);
			XMStoreFloat4x4(&g_mesh[i].mtxWorld, mtxRot);

			// �ʒu�𔽉f
			g_mesh[i].mtxWorld._41 = pDEnemy->pos.x;
			g_mesh[i].mtxWorld._42 = pDEnemy->pos.y;
			g_mesh[i].mtxWorld._43 = pDEnemy->pos.z;

			if (pDEnemy->nType != 5 && pDEnemy->nType != 6 && pDEnemy->nType != 7)	red = 1.0f;
			if (pDEnemy->nType == 5 || pDEnemy->nType == 6 || pDEnemy->nType == 7)	red = 3.0f;
			g_material.Diffuse = XMFLOAT4(red, red, 1.0f, 1.0f);

			// �`��
			SetTextureDEnemy(pDEnemy);
			DrawMesh(pDeviceContext, &g_mesh[DrawTexNo]);
		}
	}
	// ���Ƃɖ߂�
	SetBlendState(BS_NONE);	
	SetCullMode(CULLMODE_NONE);
}

// �G�X�|�[��
int SetDEnemy(XMFLOAT3 pos, XMFLOAT3 dir, int type)
{
	tDEnemy* pDEnemy = g_denemy;
	for (int i = 0; i < MAX_DENEMY;	++i, ++pDEnemy)
	{
		if (pDEnemy->nState > 0) continue;

		pDEnemy->pos.x = pos.x;
		pDEnemy->pos.y = pos.y + 19.0f;
		if (type == 3 || type == 4)	pDEnemy->pos.y = pos.y + 150.0f;
		if (type == 5)	pDEnemy->pos.y = pos.y + 35.0f;
		pDEnemy->pos.z = pos.z;
		pDEnemy->vel.x = dir.x * DENEMY_SPEED;
		pDEnemy->vel.y = dir.y * DENEMY_SPEED;
		if (type == 6 || type == 7)	pDEnemy->vel.y = 5.0f;
		pDEnemy->vel.z = dir.z * DENEMY_SPEED;
		pDEnemy->nState = 1;	// �o��
		pDEnemy->nType = type;
		pDEnemy->nAnimNo = 0;
		pDEnemy->nCount = g_animPat[0][g_denemy[i].nAnimNo].nCount;	// �ŏ��̃A�j���\������

		// �e�̍쐬
		pDEnemy->nShadowIdx = CreateShadow(pDEnemy->pos, 40.0f);

		return i;	// �ԍ���Ԃ�
	}
	return -1;	// ������Ȃ�����
}

XMFLOAT3 GetDEnemyPos(int no)
{
	if (no < 0 || no >= MAX_DENEMY) {
		return XMFLOAT3(0.0f,0.0f,0.0f);
	}

	return g_denemy[no].pos;
}

XMFLOAT3 GetDEnemySize(int no)
{
	if (no < 0 || no >= MAX_DENEMY) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	return XMFLOAT3(g_denemy[no].scl / 2.5f, g_denemy[no].scl / 5.0f, g_denemy[no].scl / 4.0f);
}

bool IsDEnemy(int no)
{
	if (no < 0 || no >= MAX_DENEMY || g_denemy[no].KillFlag == true) {
		return false;
	}
	return g_denemy[no].nState > 0 ? true : false;	// 0���ぁtrue 0�ȉ���false
}

void DestroyDEnemy(int no)
{
	if (no < 0 || no >= MAX_DENEMY) {
		return;
	}
	g_denemy[no].nState = 0;
	ReleaseShadow(g_denemy[no].nShadowIdx);
	g_denemy[no].nShadowIdx = -1;
}

void KillDEnemy(int no)
{
	if (no < 0 || no >= MAX_DENEMY) {
		return;
	}

	if (rand() % 2 == 0) {
		g_denemy[no].vel = XMFLOAT3((float)((rand() % 10) + 2), (float)((rand() % 10) + 5), (float)((rand() % 10) + 6));
	}
	else {
		g_denemy[no].vel = XMFLOAT3((float)((-rand() % 10) - 2), (float)((rand() % 10) + 5), (float)((rand() % 10) + 6));
	}

	g_denemy[no].KillFlag = true;
}

int GetDEnemy(int no)
{
	return g_denemy[no].nType;
}

HRESULT MakeVertexDEnemy(ID3D11Device* pDevice, int i)
{
	VERTEX_3D vertexWk[NUM_VERTEX]; //��Ɨp���_���
	int		  indexWk[NUM_VERTEX];	//��Ɨp�C���f�b�N�X

	// ���_���W�̐ݒ�
	g_mesh[i].nNumVertex = NUM_VERTEX;
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
	g_mesh[i].nNumIndex = NUM_VERTEX;
	indexWk[0] = 0;
	indexWk[1] = 1;
	indexWk[2] = 2;
	indexWk[3] = 3;

	return MakeMeshVertex(pDevice, &g_mesh[i], vertexWk, indexWk);
}

void SetTextureDEnemy(const tDEnemy * pDEnemy)
{
	if (pDEnemy == NULL) {
		return;
	}

	int nPattern = pDEnemy->nAnimNo;
	XMMATRIX mtxTexture, mtxScl, mtxTranslate;

	// �e�N�X�`���}�g���N�X�̏�����
	mtxTexture = XMMatrixIdentity();

	// �X�P�[���𔽉f
	mtxScl = XMMatrixScaling(1.0f / pDEnemy->tDivideX, 1.0f / pDEnemy->tDivideY, 1.0f);
	mtxTexture = XMMatrixMultiply(mtxTexture, mtxScl);

	// �ړ��𔽉f
	mtxTranslate = XMMatrixTranslation(
		1.0f / pDEnemy->tDivideX * (nPattern % pDEnemy->tDivideX),
		1.0f / pDEnemy->tDivideY * (nPattern / pDEnemy->tDivideY), 0.0f
	);
	mtxTexture = XMMatrixMultiply(mtxTexture, mtxTranslate);

	for (int i = 0; i < MAX_DENEMY_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, mtxTexture);
	}
}