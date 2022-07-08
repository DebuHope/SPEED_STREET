//=============================================================================
// ���C���܂Ƃ�
// ����F���o�n
//=============================================================================
#pragma once

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#define NOMINMAX
#include <windows.h>
#include <tchar.h>
#include <mmsystem.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include "Resource.h"

// �{���̓w�b�_�ɏ����Ȃ������ǂ�
using namespace DirectX;

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x) {if(x){(x)->Release();x=nullptr;}}
#endif
#ifndef SAFE_DELETE
#define SAFE_DELETE(x) {if(x){delete(x);x=nullptr;}}
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x) {if(x){delete[](x);x=nullptr;}}
#endif

#define SCREEN_WIDTH	(1400)				// �E�C���h�E�̕�
#define SCREEN_HEIGHT	(750)				// �E�C���h�E�̍���
#define SCREEN_CENTER_X	(SCREEN_WIDTH/2)	// �E�C���h�E�̒��S�w���W
#define SCREEN_CENTER_Y	(SCREEN_HEIGHT/2)	// �E�C���h�E�̒��S�x���W
#define	NUM_VERTEX		(4)					// ���_��
#define	NUM_POLYGON		(2)					// �|���S����

#define SinDeg(degree)	(sinf(XMConvertToRadians(degree)))
#define CosDeg(degree)	(cosf(XMConvertToRadians(degree)))

//*****************************************************************************
// �񋓌^��`
//*****************************************************************************
// �����̎��
enum EBlendState {
	BS_NONE = 0,							// ��������������
	BS_ALPHABLEND,							// ����������
	BS_ADDITIVE,							// ���Z����
	BS_SUBTRACTION,							// ���Z����

	MAX_BLENDSTATE
};

// �J�����O���
enum ECullMode {
	CULLMODE_NONE = 0,						// �J�����O���Ȃ�
	CULLMODE_CW,							// �O�ʃJ�����O
	CULLMODE_CCW,							// �w�ʃJ�����O

	MAX_CULLMODE
};

//�V�[���̎��
enum ETypeScene {
	SCENE_TITLE,
	SCENE_SELECT,
	SCENE_STAGE1_1,
	SCENE_STAGE1_2,
	SCENE_STAGE1_3,
	SCENE_STAGE1_4,
	SCENE_STAGE2_1,
	SCENE_STAGE2_2,
	SCENE_STAGE2_3,
	SCENE_STAGE2_4,
	SCENE_STAGE3_1,
	SCENE_STAGE3_2,
	SCENE_STAGE3_3,
	SCENE_STAGE3_4,
	SCENE_ENDING,

	MAX_SCENE
};

//*****************************************************************************
// �\���̒�`
//*****************************************************************************
// ���_�t�H�[�}�b�g( ���_���W[2D] / ���ˌ� / �e�N�X�`�����W )
typedef struct {
	XMFLOAT3 vtx;		// ���_���W
	XMFLOAT4 diffuse;	// �g�U���ˌ�
	XMFLOAT2 tex;		// �e�N�X�`�����W
} VERTEX_2D;

// ���_�t�H�[�}�b�g( ���_���W[3D] / �@���x�N�g�� / ���ˌ� / �e�N�X�`�����W )
typedef struct {
	XMFLOAT3 vtx;		// ���_���W
	XMFLOAT3 nor;		// �@���x�N�g��
	XMFLOAT4 diffuse;	// �g�U���ˌ�
	XMFLOAT2 tex;		// �e�N�X�`�����W
} VERTEX_3D;

// 2D�A�j���[�V�����\����
typedef struct {
	int nPatNo;	// �\���p�^�[���ԍ�
	int nCount;	// �\���t���[����
}ANIM_PAT;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HWND GetMainWnd();
HINSTANCE GetInstance();
ID3D11Device* GetDevice();
ID3D11DeviceContext* GetDeviceContext();
void SetZBuffer(bool bEnable);
void SetZWrite(bool bEnable);
void SetBlendState(int nBlendState);
void SetCullMode(int nCullMode);

void StartSceneChange(ETypeScene NextScene);	// �V�[���J�ڊJ�n
ETypeScene GetSceneNo();		// ���݂̃V�[���ԍ�����

void ReleaseGame();