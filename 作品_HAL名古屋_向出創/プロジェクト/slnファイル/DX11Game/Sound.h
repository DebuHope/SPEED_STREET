//======================================================================================
// �T�E���h�������܂Ƃ�
// ����F���o�n
//======================================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

#include <xaudio2.h>
// Windows7�̏ꍇ�͏�L���폜���Ĉȉ��ɒu������.
//#include <C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\xaudio2.h>

//*****************************************************************************
// �T�E���h�t�@�C��
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_BGM01 = 0,	
	SOUND_LABEL_SE_RUN,		
	SOUND_LABEL_SE_DASH,	
	SOUND_LABEL_SE_JUMP,	
	SOUND_LABEL_SE_SLIDE,
	SOUND_LABEL_SE_HIT,		
	SOUND_LABEL_SE_CANDY,
	SOUND_LABEL_SE_FALL,
	SOUND_LABEL_SE_CHECKPOINT,

	SOUND_LABEL_MAX

} SOUND_LABEL;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);

HRESULT PlaySound(SOUND_LABEL label);	// �Đ�

void StopSound(SOUND_LABEL label);		// 1��~
void StopSound(void);					// �S����~
void PauseSound( void );				// �ꎞ��~
void ResumeSound( void );				// �ĊJ

void SetVolume(float fVol);				// ���ʒ���
void SetVolume(float fVol, SOUND_LABEL label);

#endif
