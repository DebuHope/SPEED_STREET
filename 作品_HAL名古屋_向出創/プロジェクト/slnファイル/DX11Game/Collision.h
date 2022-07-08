//=============================================================================
// 当たり判定まとめ
// 制作：向出創
//=============================================================================
#pragma once

#include "Main.h"

void Collision();	// 当たり判定まとめ

// バウンディングボックス(BB2D)
bool CollisionBB2D(
	XMFLOAT2* pCenter1, XMFLOAT2* pSize1,
	XMFLOAT2* pCenter2, XMFLOAT2* pSize2);

// バウンディングサークル(BC)
bool CollisionBC(
	XMFLOAT2* pCenter1, float fRadius1,
	XMFLOAT2* pCenter2, float fRadius2 );

// バウンティングボックス(BB3D)
bool CollisionBB3D(
	XMFLOAT3* pCenter1, XMFLOAT3* pSize1,
	XMFLOAT3* pCenter2, XMFLOAT3* pSize2);

// バウンティングスフィア(BS)
bool CollisionBS(
	XMFLOAT3* pCenter1, float fRadius1,
	XMFLOAT3* pCenter2, float fRadius2);

// バウンディングシリンダー(BCy)
bool CollisionBCy(
	XMFLOAT3* pCenter1, float height1, float fRadius1,
	XMFLOAT3* pCenter2, float height2, float fRadius2);