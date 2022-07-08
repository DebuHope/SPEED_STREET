//=============================================================================
// プレイヤーまとめ
// 制作：向出創
//=============================================================================
#pragma once

#include "Main.h"

#define MAX_PLAYER		(1)

enum PlayerPhose {
	RUN,
	DASH,
	BREAK,
	JUMP,
	SLIDE,
	WDOWN,	// 前にこける
	SDOWN,	// 後にノックバック
	FALL,
	SITTING,
	RUN2,
	RUN3,

	MAX_PLAYER_PHOSE
};

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT LoadPlayer();
void InitPlayer();
void UninitPlayer();
void UpdatePlayer();
void DrawPlayer();

XMFLOAT4X4 GetPlayerWorld(int no);
XMFLOAT3 GetPlayerCenter(int no);
XMFLOAT3 GetPlayerBBox(int no);

XMFLOAT3 GetPlayerPos(int no);
XMFLOAT3 GetPlayerSize(int no);
bool IsPlayer(int no);
void DestroyPlayer(int no);

PlayerPhose GetPlayerPhose(int no);
void PlayerPhoseChange(int no, PlayerPhose phose);

XMFLOAT3 GetPlayerVel(int no);

float GetPlayerDashCount();
float GetPlayerJumpCount();
float GetPlayerSlide();
