#include "Load.h"
#include "Bg.h"
#include "Car.h"
#include "DEnemy.h"
#include "EF_Acceleration.h"
#include "Field.h"
#include "Hole.h"
#include "Object.h"
#include "Player.h"
#include "Shadow.h"
#include "Street.h"
#include "Hint.h"
#include "UEnemy.h"
#include "UI.h"
#include "Transition.h"
#include "Life.h"
#include "Item.h"
#include "PlayerIcon.h"
#include "CheckPoint.h"
#include "Goal.h"
#include "Combo.h"
#include "Gauge.h"
#include "Endroll.h"

HRESULT LoadModelTex()
{
	HRESULT hr = S_OK;
	HWND hWnd = GetMainWnd();

	hr = LoadUI();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("UI�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadPlayer();
	if (FAILED(hr)){
	MessageBox(hWnd, _T("�v���C���[�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
	return hr;
	}

	hr = LoadCar();
	if (FAILED(hr)){
	MessageBox(hWnd, _T("�ԏ������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
	return hr;
	}

	hr = LoadObject();
	if (FAILED(hr)){
		MessageBox(hWnd, _T("�I�u�W�F�N�g�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadDEnemy();
	if (FAILED(hr)){
		MessageBox(hWnd, _T("�n��G�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadUEnemy();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�󒆓G�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadBg();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�w�i�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadShadow();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�����������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadAcceleration();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�����G�t�F�N�g�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadStreet();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("���������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadHole();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("���Ƃ����������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadField();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("���Ƃ����������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadHint();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("���H�q���g�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadTransition();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�g�����W�V�����������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadLife();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�n�[�g�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadItem();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�A�C�e���������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadPlayerIcon();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�A�C�e���������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadCheckPoint();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�`�F�b�N�|�C���g�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadGoal();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�S�[���������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadCombo();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�R���{�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadGauge();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�Q�[�W�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	hr = LoadText();
	if (FAILED(hr)) {
		MessageBox(hWnd, _T("�e�L�X�g�������G���["), _T("�������G���["), MB_OK | MB_ICONSTOP);
		return hr;
	}

	InitHole();
	InitCar();
	InitLife();

	return hr;
}