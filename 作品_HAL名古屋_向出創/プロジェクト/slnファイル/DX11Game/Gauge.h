//======================================================================================
// �Q�[�W�����܂Ƃ�
// ����F���o�n
//======================================================================================
#pragma once

#include "main.h"

// �}�N����`
#define GAUGE_MAX	(100)

// �v���g�^�C�v�錾
HRESULT LoadGauge();	//������
void UninitGauge(void);
// ���W�͍��[���w��
void DrawGaugeX(XMFLOAT2 pos, XMFLOAT2 size, float percent, int no);
void DrawGaugeY1(XMFLOAT2 pos, XMFLOAT2 size, float percent, int no);
void DrawGaugeY2(XMFLOAT2 pos, XMFLOAT2 size, float percent, int no);