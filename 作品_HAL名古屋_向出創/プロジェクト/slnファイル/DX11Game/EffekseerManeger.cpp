//======================================================================================
// Effekseer�Ǘ��N���X
// ����F�����q��
//======================================================================================

//�C���N���[�h
#include "EffekseerManeger.h"
#include "Player.h"

EffekseerManeger::EffekseerManeger(ID3D11Device * _device, ID3D11DeviceContext *_deviceContext) 
{
	rendarer = EffekseerRendererDX11::Renderer::Create(_device, _deviceContext, 8000);
	manager = Effekseer::Manager::Create(8000);

	// �`�惂�W���[���̐ݒ�
	manager->SetSpriteRenderer(rendarer->CreateSpriteRenderer());
	manager->SetRibbonRenderer(rendarer->CreateRibbonRenderer());
	manager->SetRingRenderer(rendarer->CreateRingRenderer());
	manager->SetTrackRenderer(rendarer->CreateTrackRenderer());
	manager->SetModelRenderer(rendarer->CreateModelRenderer());

	// �e�N�X�`���A���f���A�J�[�u�A�}�e���A�����[�_�[�̐ݒ肷��B
	// ���[�U�[���Ǝ��Ŋg���ł���B���݂̓t�@�C������ǂݍ���ł���B
	manager->SetTextureLoader(rendarer->CreateTextureLoader());
	manager->SetModelLoader(rendarer->CreateModelLoader());
	manager->SetMaterialLoader(rendarer->CreateMaterialLoader());
	manager->SetCurveLoader(Effekseer::MakeRefPtr<Effekseer::CurveLoader>());

	//�G�t�F�N�g�̃��[�h
	effect[0] = Effekseer::Effect::Create(manager, u"data/effect/smoke1.efk");
	effect[1] = Effekseer::Effect::Create(manager, u"data/effect/smoke.efk");
	effect[2] = Effekseer::Effect::Create(manager, u"data/effect/smoke4.efk");
}


//
void EffekseerManeger::update()
{
	manager->Update();
	static int time = 0;
	rendarer->SetTime(time / 60.0f);
}


//
void EffekseerManeger::Draw()
{
	CCamera* camera = GetCamera();
	//Effekseer::Vector3D eye = Effekseer::Vector3D(camera->GetPos().x, camera->GetPos().y, camera->GetPos().z);
	//Effekseer::Vector3D look = Effekseer::Vector3D(camera->m_vTarget.x, camera->m_vTarget.y, camera->m_vTarget.z);

	Effekseer::Vector3D eye = Effekseer::Vector3D(GetPlayerPos(0).x, -70.0f, GetPlayerPos(0).z + 1000.0f);
	Effekseer::Vector3D look = Effekseer::Vector3D(GetPlayerPos(0).x, -70.0f, GetPlayerPos(0).z + 100.0f);
	Effekseer::Vector3D up = Effekseer::Vector3D(0, 100, 0);

	rendarer->SetProjectionMatrix(
		::Effekseer::Matrix44().PerspectiveFovLH(camera->m_fFovY, camera->m_fAspectRatio, camera->m_fFarZ, camera->m_fNearZ));

	rendarer->SetCameraMatrix(::Effekseer::Matrix44().LookAtLH(eye, look, up));

	rendarer->BeginRendering();
	manager->Draw();
	rendarer->EndRendering();

}

//
Effekseer::Handle EffekseerManeger::play(int _id, XMFLOAT3 _pos)
{
	return manager->Play(effect[_id], _pos.x, _pos.y, _pos.z);
}

void EffekseerManeger::setstop(Effekseer::Handle _handle)
{
	manager->SetPaused(_handle, false);
}


//
void EffekseerManeger::setposition(Effekseer::Handle _handle, XMFLOAT3 _pos)
{
	manager->SetLocation(_handle, _pos.x, _pos.y, _pos.z);
}


//
void EffekseerManeger::setangle(Effekseer::Handle _handle, XMFLOAT3 _angle)
{
	manager->SetRotation(_handle, XMConvertToRadians(_angle.x), XMConvertToRadians(_angle.y), XMConvertToRadians(_angle.z));
}

//
void EffekseerManeger::setScale(Effekseer::Handle _handle, XMFLOAT3 _Scale)
{
	manager->SetScale(_handle, _Scale.x, _Scale.y, _Scale.z);
}

//
void EffekseerManeger::setScale(Effekseer::Handle _handle, float _Scale)
{
	manager->SetScale(_handle, _Scale, _Scale, _Scale);
}

void EffekseerManeger::setdate(Effekseer::Handle _handle, XMFLOAT3 _pos, XMFLOAT3 _angle, XMFLOAT3 _scale)
{
	manager->SetLocation(_handle, _pos.x, _pos.y, _pos.z);
	manager->SetRotation(_handle, XMConvertToRadians(_angle.x), XMConvertToRadians(_angle.y), XMConvertToRadians(_angle.z));
	manager->SetScale(_handle, _scale.x, _scale.y, _scale.z);

}

bool EffekseerManeger::getinstance(Effekseer::Handle _handle)
{
	return manager->Exists(_handle);
}
