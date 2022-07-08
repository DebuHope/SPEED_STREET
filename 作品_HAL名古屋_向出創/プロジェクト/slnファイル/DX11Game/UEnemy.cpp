//======================================================================================
// �n��G����
// ����F���o�n
//======================================================================================
#include <stdlib.h>
#include "UEnemy.h"
#include "Shader.h"
#include "Texture.h"
#include "mesh.h"
#include "Shadow.h"
#include "Player.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define TEXTURE_WINGEYE	L"data/texture/wing.png"
#define TEXTURE_BAD		L"data/texture/Bad.png"
#define TEXTURE_GHOST	L"data/texture/ghost.png"
#define MAX_UENEMY_TEXTURE	(3)

#define M_DIFFUSE		XMFLOAT4(1.0f,1.0f,1.0f,1.0f)
#define M_SPECULAR		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)
#define M_AMBIENT		XMFLOAT4(0.0f,0.0f,0.0f,1.0f)
#define M_EMISSIVE		XMFLOAT4(0.0f,0.0f,0.0f,0.0f)

#define UENEMY_SPEED		(1.0F)	// �G�̑��x

#define GRAVITY			(-0.5f)

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
typedef struct _tUEnemy{
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
}tUEnemy;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT MakeVertexUEnemy(ID3D11Device* pDevice, int i);

void SetTextureUEnemy(const tUEnemy* pUEnemy);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static MESH		g_mesh[MAX_UENEMY_TEXTURE];		// ���b�V�����
static MATERIAL	g_material;	// �}�e���A�����

static tUEnemy	g_uenemy[MAX_UENEMY];

static float alpha;
static bool alphaFlag;

static float	red;

static int	DrawTexNo;	// �\������e�N�X�`��No

static ANIM_PAT g_animPat[1][7] = {	// �A�j���[�V�����f�[�^
	{{0,10},{1,10},{2,10},{3,10},{4,10},{5,10},{-1,-1}}
};

HRESULT LoadUEnemy(void)
{
	ID3D11Device* pDevice = GetDevice();
	HRESULT hr = S_OK;

	// �}�e���A���̏����ݒ�
	g_material.Diffuse = M_DIFFUSE;
	g_material.Ambient = M_AMBIENT;
	g_material.Specular = M_SPECULAR;
	g_material.Power = 50.0f;
	g_material.Emissive = M_EMISSIVE;

	for (int i = 0; i < MAX_UENEMY_TEXTURE; i++) {
		g_mesh[i].pMaterial = &g_material;
	}

	// �e�N�X�`���̓ǂݍ���
	hr = CreateTextureFromFile(pDevice, TEXTURE_WINGEYE, &g_mesh[0].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_BAD, &g_mesh[1].pTexture);
	if (FAILED(hr))	return hr;
	hr = CreateTextureFromFile(pDevice, TEXTURE_GHOST, &g_mesh[2].pTexture);
	if (FAILED(hr))	return hr;

	// ���[���h�}�g���N�X������
	for (int i = 0; i < MAX_UENEMY_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, XMMatrixIdentity());
		XMStoreFloat4x4(&g_mesh[i].mtxWorld, XMMatrixIdentity());
	}

	// ���_���̍쐬
	for (int i = 0; i < MAX_UENEMY_TEXTURE; i++) {
		hr = MakeVertexUEnemy(pDevice, i);
	}

	return hr;
}
//=============================================================================
// ����������
//=============================================================================
void InitUEnemy(void)
{
	// �ϐ��̏�����
	for (int i = 0; i < MAX_UENEMY; i++) {
		g_uenemy[i].nShadowIdx = -1;
		g_uenemy[i].nState = 0;
		g_uenemy[i].rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
		g_uenemy[i].scl = 60.0f;
		g_uenemy[i].nAnimNo = 0;
		g_uenemy[i].nCount = g_animPat[0][g_uenemy[i].nAnimNo].nCount;	// �ŏ��̃A�j���\������
		g_uenemy[i].nType = 0;
		g_uenemy[i].KillFlag = false;

		g_uenemy[i].tDivideX = 2;
		g_uenemy[i].tDivideY = 1;
	}
	alpha = 1.0f;
	alphaFlag = false;
	red = 1.0f;
}

//=============================================================================
// �I������
//=============================================================================
void UninitUEnemy(void)
{
	tUEnemy* pUEnemy = g_uenemy;
	for (int i = 0; i < MAX_UENEMY;
		++i, ++pUEnemy)
	{
		if (pUEnemy->nState == 0) continue;
		pUEnemy->nState = 0;
		// �e�Ƃ̊֘A��؂�
		ReleaseShadow(pUEnemy->nShadowIdx);
		pUEnemy->nShadowIdx = -1;
	}

	// ���b�V�����
	//for (int i = 0; i < 2; i++) {
	//	ReleaseMesh(&g_mesh[i]);
	//}
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateUEnemy(void)
{
	// �X�V����
	tUEnemy* pUEnemy = g_uenemy;
	for (int i = 0; i < MAX_UENEMY; i++, ++pUEnemy)
	{
		if (pUEnemy->nState == 0) continue;

		// �L���t���O���������ꍇ
		if (pUEnemy->KillFlag == true) {
			// �d�͂����W�ɉ��Z
			pUEnemy->vel.y += GRAVITY;
		}

		// �e�̈ړ�
		MoveShadow(pUEnemy->nShadowIdx, pUEnemy->pos);

		// ��ʂɋ߂Â��������
		if (pUEnemy->pos.z < GetPlayerPos(0).z - 5000.0f || pUEnemy->pos.y < -20.0f) {
			DestroyUEnemy(i);
		}

		// �����X�V
		if (pUEnemy->pos.z < GetPlayerPos(0).z + 3200.0f) {

			// ���E�ړ�
			if (pUEnemy->nType == 1) {
				if (pUEnemy->pos.x < -80.0f) {
					pUEnemy->vel.x += 1.0f;
				}
				if (pUEnemy->pos.x > 80.0f) {
					pUEnemy->vel.x -= 1.0f;
				}
			}

			// �㉺�ړ�
			if (pUEnemy->nType == 2) {
				if (pUEnemy->pos.y < 40.0f) {
					pUEnemy->vel.y += 1.0f;
				}
				if (pUEnemy->pos.y > 100.0f) {
					pUEnemy->vel.y -= 1.0f;
				}
			}

			// �r���^��
			if (pUEnemy->nType == 3) {
				pUEnemy->pos.y = 200.0f;
			}
			if (pUEnemy->nType == 4) {
				float tempLength;
				float vecX, vecZ;
				vecX = GetPlayerPos(0).x - pUEnemy->pos.x;
				vecZ = GetPlayerPos(0).z - pUEnemy->pos.z;
				tempLength = sqrtf(vecX*vecX + vecZ * vecZ);
				if (tempLength >= 100.0f)
				{
					pUEnemy->pos.x += vecX / tempLength * 15.0f;
				}
				pUEnemy->pos.y = 200.0f;
			}

			// ���ɍs��
			if (pUEnemy->nType == 6) {
				if (pUEnemy->pos.z < GetPlayerPos(0).z + 300.0f && GetPlayerPhose(0) == SLIDE) {
					pUEnemy->vel.y += 0.3f;
					pUEnemy->pos.y += pUEnemy->vel.y;
				}
			}

			// �Ǐ]���ɍs��
			if (pUEnemy->nType == 7) {
				float tempLength;
				float vecX, vecZ;
				vecX = GetPlayerPos(0).x - pUEnemy->pos.x;
				vecZ = GetPlayerPos(0).z - pUEnemy->pos.z;
				tempLength = sqrtf(vecX*vecX + vecZ * vecZ);
				if (tempLength >= 300.0f)
				{
					pUEnemy->pos.x += vecX / tempLength * 30.0f;
				}
				if (pUEnemy->pos.z < GetPlayerPos(0).z + 300.0f && GetPlayerPhose(0) == SLIDE) {
					pUEnemy->vel.y += 0.3f;
					pUEnemy->pos.y += pUEnemy->vel.y;
				}
			}

			// �ʒu�̍X�V
				pUEnemy->pos.x += pUEnemy->vel.x;
				if (pUEnemy->nType != 6 && pUEnemy->nType != 7)	pUEnemy->pos.y += pUEnemy->vel.y;
				pUEnemy->pos.z += pUEnemy->vel.z;
		}

		// �e������
		if (pUEnemy->pos.y <= 0.0f) {
			ReleaseShadow(pUEnemy->nShadowIdx);
			pUEnemy->nShadowIdx = -1;
		}

		// �o������G�ɂ���ăe�N�X�`��
		switch (GetSceneNo())
		{
		case SCENE_STAGE1_1:
		case SCENE_STAGE1_2:
		case SCENE_STAGE1_3:
		case SCENE_STAGE1_4:
			pUEnemy->tDivideX = 2;
			pUEnemy->tDivideY = 1;
			pUEnemy->scl = 60.0f;
			pUEnemy->rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
			DrawTexNo = 0;
			break;
		case SCENE_STAGE2_1:
		case SCENE_STAGE2_2:
		case SCENE_STAGE2_3:
		case SCENE_STAGE2_4:
			pUEnemy->tDivideX = 2;
			pUEnemy->tDivideY = 1;
			pUEnemy->scl = 40.0f;
			if (pUEnemy->nType == 3 || pUEnemy->nType == 4)	pUEnemy->scl = 70.0f;

			if (pUEnemy->pos.x > GetPlayerPos(0).x)	pUEnemy->rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
			if (pUEnemy->pos.x < GetPlayerPos(0).x)	pUEnemy->rot = XMFLOAT3(0.0f, 180.0f, 0.0f);
			DrawTexNo = 1;
			break;
		case SCENE_STAGE3_1:
		case SCENE_STAGE3_2:
		case SCENE_STAGE3_3:
		case SCENE_STAGE3_4:
			pUEnemy->tDivideX = 5;
			pUEnemy->tDivideY = 1;
			pUEnemy->scl = 40.0f;
			if (pUEnemy->nType == 3 || pUEnemy->nType == 4)	pUEnemy->scl = 70.0f;

			if (pUEnemy->pos.x > GetPlayerPos(0).x)	pUEnemy->rot = XMFLOAT3(0.0f, 0.0f, 0.0f);
			if (pUEnemy->pos.x < GetPlayerPos(0).x)	pUEnemy->rot = XMFLOAT3(0.0f, 180.0f, 0.0f);

			DrawTexNo = 2;
			ReleaseShadow(pUEnemy->nShadowIdx);
			pUEnemy->nShadowIdx = -1;

			// �������p�����x
			if(GetSceneNo() == SCENE_STAGE3_3)
			if (alphaFlag == false) {
				alpha -= 0.001f;
				if (alpha < -2.0f)	alphaFlag = true;
			}
			else if (alphaFlag == true) {
				alpha += 0.001f;
				if (alpha > 6.0f)	alphaFlag = false;
			}
			break;
		}

		// �A�j���[�V�������̍X�V
		pUEnemy->nCount--;	// �c��J�E���g�������炷
		if (pUEnemy->nCount <= 0) {
			pUEnemy->nAnimNo++;	// ���̊G�ɐi�߂�
			if (g_animPat[0][pUEnemy->nAnimNo].nPatNo < 0) {
				// �ԕ����Q�Ƃ�����
				pUEnemy->nAnimNo = 0;	// ����
			}
			// �J�E���g�����̕\���t���[�����ɐݒ�
			pUEnemy->nCount = g_animPat[0][pUEnemy->nAnimNo].nCount;
		}
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawUEnemy(void)
{
	ID3D11DeviceContext* pDeviceContext = GetDeviceContext();
	// �����ݒ�
	// Z�o�b�t�@����
	if(alpha < 0)	SetZBuffer(false);
	SetBlendState(BS_ALPHABLEND);
	XMFLOAT4X4 mView = GetCamera()->GetViewMatrix();	// �r���[�}�g���b�N�X
	tUEnemy* pUEnemy = g_uenemy;
	for (int i = 0; i < MAX_UENEMY; i++, pUEnemy++) {
		// �o�ĂȂ��e�͏������Ȃ�
		if (pUEnemy->nState == 0 || pUEnemy->pos.z < GetPlayerPos(0).z - 60.0f || pUEnemy->pos.y < -20.0f) {
			continue;
		}

		if (DrawTexNo == 3) {
			if (pUEnemy->pos.x > GetPlayerPos(0).x)	SetCullMode(CULLMODE_CCW);
			if (pUEnemy->pos.x < GetPlayerPos(0).x)	SetCullMode(CULLMODE_CW);
		}
		
		// �r���[�s��̉�]�����̓]�u�s���ݒ�
		for (int i = 0; i < MAX_UENEMY_TEXTURE; i++) {
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
			XMMATRIX mtxScl = XMMatrixScaling(pUEnemy->scl, pUEnemy->scl, pUEnemy->scl);
			XMMATRIX mtxRot;
			mtxRot = XMLoadFloat4x4(&g_mesh[i].mtxWorld);
			mtxRot = XMMatrixRotationRollPitchYaw(
				XMConvertToRadians(pUEnemy->rot.x),
				XMConvertToRadians(pUEnemy->rot.y),
				XMConvertToRadians(pUEnemy->rot.z));
			mtxRot = XMMatrixMultiply(mtxRot, mtxScl);
			XMStoreFloat4x4(&g_mesh[i].mtxWorld, mtxRot);

			// �ʒu�𔽉f
			g_mesh[i].mtxWorld._41 = pUEnemy->pos.x;
			g_mesh[i].mtxWorld._42 = pUEnemy->pos.y;
			g_mesh[i].mtxWorld._43 = pUEnemy->pos.z;

			if (pUEnemy->nType != 6 && pUEnemy->nType != 7)	red = 1.0f;
			if (pUEnemy->nType == 6 || pUEnemy->nType == 7)	red = 0.0f;
			g_material.Diffuse = XMFLOAT4(red, 1.0f, 1.0f, alpha);

			// �`��
			SetTextureUEnemy(pUEnemy);
			DrawMesh(pDeviceContext, &g_mesh[DrawTexNo]);
		}
	}
	// ���Ƃɖ߂�
	SetBlendState(BS_NONE);
	SetCullMode(CULLMODE_NONE);
	// Z�o�b�t�@����
	SetZBuffer(true);
}

// �G�X�|�[��
int SetUEnemy(XMFLOAT3 pos, XMFLOAT3 dir, int type)
{
	tUEnemy* pUEnemy = g_uenemy;
	for (int i = 0; i < MAX_UENEMY;	++i, ++pUEnemy)
	{
		if (pUEnemy->nState > 0) continue;

		pUEnemy->pos.x = pos.x;
		pUEnemy->pos.y = pos.y + 60.0f;
		pUEnemy->pos.z = pos.z;
		pUEnemy->vel.x = dir.x * UENEMY_SPEED;
		pUEnemy->vel.y = dir.y * UENEMY_SPEED;
		if(type == 6 || type == 7)	pUEnemy->vel.y = -5.0f;
		pUEnemy->vel.z = dir.z * UENEMY_SPEED;
		pUEnemy->nState = 1;	// �o��
		pUEnemy->nType = type;
		pUEnemy->nAnimNo = 0;
		pUEnemy->nCount = g_animPat[0][pUEnemy->nAnimNo].nCount;	// �ŏ��̃A�j���\������

		// �e�̍쐬
		pUEnemy->nShadowIdx = CreateShadow(pUEnemy->pos, 40.0f);

		return i;	// �ԍ���Ԃ�
	}

	return -1;	// ������Ȃ�����
}

XMFLOAT3 GetUEnemyPos(int no)
{
	if (no < 0 || no >= MAX_UENEMY) {
		return XMFLOAT3(0.0f,0.0f,0.0f);
	}

	return g_uenemy[no].pos;
}

XMFLOAT3 GetUEnemySize(int no)
{
	if (no < 0 || no >= MAX_UENEMY) {
		return XMFLOAT3(0.0f, 0.0f, 0.0f);
	}

	return XMFLOAT3(g_uenemy[no].scl / 3.0f, g_uenemy[no].scl, g_uenemy[no].scl / 2.0f);
}

bool IsUEnemy(int no)
{
	if (no < 0 || no >= MAX_UENEMY || g_uenemy[no].KillFlag == true) {
		return false;
	}
	return g_uenemy[no].nState > 0 ? true : false;	// 0���ぁtrue 0�ȉ���false
}

void DestroyUEnemy(int no)
{
	if (no < 0 || no >= MAX_UENEMY) {
		return;
	}
	g_uenemy[no].nState = 0;
	ReleaseShadow(g_uenemy[no].nShadowIdx);
	g_uenemy[no].nShadowIdx = -1;
}

void KillUEnemy(int no)
{
	if (no < 0 || no >= MAX_UENEMY) {
		return;
	}

	if (rand() % 2 == 0) {
		g_uenemy[no].vel = XMFLOAT3((float)((rand() % 10) + 2), (float)((rand() % 10) + 5), (float)((rand() % 10) + 6));
	}
	else {
		g_uenemy[no].vel = XMFLOAT3((float)((-rand() % 10) - 2), (float)((rand() % 10) + 5), (float)((rand() % 10) + 6));
	}
 
	g_uenemy[no].KillFlag = true;
}

int GetUEnemy(int no)
{
	return g_uenemy[no].nType;
}

HRESULT MakeVertexUEnemy(ID3D11Device* pDevice, int i)
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

void SetTextureUEnemy(const tUEnemy * pUEnemy)
{
	if (pUEnemy == NULL) {
		return;
	}

	int nPattern = pUEnemy->nAnimNo;
	XMMATRIX mtxTexture, mtxScl, mtxTranslate;

	// �e�N�X�`���}�g���N�X�̏�����
	mtxTexture = XMMatrixIdentity();

	// �X�P�[���𔽉f
	mtxScl = XMMatrixScaling(1.0f / pUEnemy->tDivideX, 1.0f / pUEnemy->tDivideY, 1.0f);
	mtxTexture = XMMatrixMultiply(mtxTexture, mtxScl);

	// �ړ��𔽉f
	mtxTranslate = XMMatrixTranslation(
		1.0f / pUEnemy->tDivideX * (nPattern % pUEnemy->tDivideX),
		1.0f / pUEnemy->tDivideY * (nPattern / pUEnemy->tDivideY), 0.0f
	);
	mtxTexture = XMMatrixMultiply(mtxTexture, mtxTranslate);

	for (int i = 0; i < MAX_UENEMY_TEXTURE; i++) {
		XMStoreFloat4x4(&g_mesh[i].mtxTexture, mtxTexture);
	}
}