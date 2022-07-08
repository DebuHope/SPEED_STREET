//======================================================================================
// �G�t�F�N�g�Ǘ�
// ����F���o�n
//======================================================================================
#include "EF_Maneger.h"
#include "EffekseerManeger.h"
#include "Player.h"
#include "Game.h"

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
EffekseerManeger*	g_effekt;
Effekseer::Handle	g_Handle;

//*****************************************************************************
// ������
//*****************************************************************************
void InitEFManeger()
{
	// Effekseer�G�t�F�N�g
	g_effekt = new EffekseerManeger(GetDevice(), GetDeviceContext());
}

//*****************************************************************************
// �X�V�i�Ǘ������j
//*****************************************************************************
void UpdateEFManeger()
{
	if (GetSceneNo() != SCENE_SELECT && GetSceneNo() != SCENE_ENDING) {
		// �v���C���[�_�b�V��
		if (GetPlayerPhose(0) == DASH) {

			g_effekt->setScale(g_Handle, XMFLOAT3(1.0f, 1.0f, 1.0f));
			g_Handle = g_effekt->play(0, XMFLOAT3(GetPlayerPos(0).x, 0.0f, GetPlayerPos(0).z - 300.0f));
		}
		//�@�v���C���[�u���[�L
		else if (GetPlayerPhose(0) == BREAK) {

			g_effekt->setScale(g_Handle, XMFLOAT3(1.0f, 1.0f, 1.0f));
			g_Handle = g_effekt->play(1, XMFLOAT3(GetPlayerPos(0).x, -10.0f, GetPlayerPos(0).z));
		}
		// �v���C���[�X���C�h
		else if (GetPlayerPhose(0) == SLIDE) {

			g_effekt->setScale(g_Handle, XMFLOAT3(1.0f, 1.0f, 1.0f));
			g_Handle = g_effekt->play(2, XMFLOAT3(GetPlayerPos(0).x, 0.0f, GetPlayerPos(0).z));
		}

		if (GetState() == 0) {
			g_effekt->update();
		}
	}
}

//*****************************************************************************
// �`��
//*****************************************************************************
void DrawEFManeger()
{
	g_effekt->Draw();
}