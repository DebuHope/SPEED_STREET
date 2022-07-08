//=============================================================================
// 当たり判定処理
// 制作：向出創
//=============================================================================
#include "Debugproc.h"
#include "Collision.h"
#include "Player.h"
#include "DEnemy.h"
#include "UEnemy.h"
#include "Car.h"
#include "Hole.h"
#include "Item.h"
#include "Score.h"
#include "Life.h"
#include "CheckPoint.h"
#include "Goal.h"
#include "Sound.h"
#include "Transition.h"
#include "Endroll.h"

// 当たり判定まとめ
void Collision()
{
	int nCnt1, nCnt2;	// ループ用変数

	// プレイヤーと地上敵
	for (nCnt1 = 0; nCnt1 < MAX_DENEMY; nCnt1++) {
		if (!IsDEnemy(nCnt1))	continue;

		for (nCnt2 = 0; nCnt2 < MAX_PLAYER; nCnt2++) {
			if (!IsPlayer(nCnt2))	continue;

			if (CollisionBCy(
				(&GetDEnemyPos(nCnt1)),
				GetDEnemySize(nCnt1).y,
				GetDEnemySize(nCnt1).x,
				&GetPlayerCenter(nCnt2),
				GetPlayerBBox(nCnt2).y,
				GetPlayerBBox(nCnt2).x))
			{	// 当たった時の処理
				if (GetPlayerPhose(nCnt2) != SDOWN && GetPlayerPhose(nCnt2) != WDOWN &&
					GetPlayerPhose(nCnt2) != FALL && GetPlayerPhose(nCnt2) != SLIDE) {
					PlayerPhoseChange(nCnt2, WDOWN);
					RemainingLife(1);
					AddCountCombo(-999);
					PlaySound(SOUND_LABEL_SE_HIT);

					break;
				}

				if (GetDEnemy(nCnt1) == 5 || GetDEnemy(nCnt1) == 7) {
					PlayerPhoseChange(nCnt2, WDOWN);
					RemainingLife(1);
					AddCountCombo(-999);
					PlaySound(SOUND_LABEL_SE_HIT);

					break;
				}

				if (GetPlayerPhose(nCnt2) == SLIDE && GetDEnemy(nCnt1) != 5) {
					KillDEnemy(nCnt1);
					AddCountCombo(1);
					AddCountKill(1);
					PlaySound(SOUND_LABEL_SE_HIT);

					break;
				}
			}
		}
	}

	// プレイヤーと空中敵
	for (nCnt1 = 0; nCnt1 < MAX_UENEMY; nCnt1++) {
		if (!IsUEnemy(nCnt1))	continue;

		for (nCnt2 = 0; nCnt2 < MAX_PLAYER; nCnt2++) {
			if (!IsPlayer(nCnt2))	continue;

			if (CollisionBCy(
				&GetUEnemyPos(nCnt1),
				GetUEnemySize(nCnt1).y,
				GetUEnemySize(nCnt1).x,
				&GetPlayerCenter(nCnt2),
				GetPlayerBBox(nCnt2).y,
				GetPlayerBBox(nCnt2).x))
			{	// 当たった時の処理
				if (GetPlayerPhose(nCnt2) != SDOWN && GetPlayerPhose(nCnt2) != WDOWN && 
					GetPlayerPhose(nCnt2) != FALL && GetPlayerPhose(nCnt2) != SLIDE && GetPlayerPhose(nCnt2) != JUMP) {
					PlayerPhoseChange(nCnt2, SDOWN);
					RemainingLife(1);
					AddCountCombo(-999);
					PlaySound(SOUND_LABEL_SE_HIT);

					break;
				}

				if (GetUEnemy(nCnt1) == 7) {
					PlayerPhoseChange(nCnt2, SDOWN);
					RemainingLife(1);
					AddCountCombo(-999);
					PlaySound(SOUND_LABEL_SE_HIT);
					break;
				}

				if (GetPlayerPhose(nCnt2) == JUMP) {
					KillUEnemy(nCnt1);
					AddCountCombo(1);
					AddCountKill(1);
					PlaySound(SOUND_LABEL_SE_HIT);

					break;
				}
			}
		}
	}

	// プレイヤーと車
	for (nCnt1 = 0; nCnt1 < MAX_CAR; nCnt1++) {
		if (!IsCar(nCnt1))	continue;

		for (nCnt2 = 0; nCnt2 < MAX_PLAYER; nCnt2++) {
			if (!IsPlayer(nCnt2))	continue;

			if (CollisionBCy(
				&GetCarCenter(nCnt1),
				GetCarBBox(nCnt1).y,
				GetCarBBox(nCnt1).x,
				&GetPlayerCenter(nCnt2),
				GetPlayerBBox(nCnt2).y,
				GetPlayerBBox(nCnt2).x))
			{	// 当たった時の処理
				if (GetPlayerPhose(nCnt2) != SDOWN && GetPlayerPhose(nCnt2) != WDOWN &&
					GetPlayerPhose(nCnt2) != FALL) {
				PlayerPhoseChange(nCnt2, SDOWN);
				RemainingLife(1);
				AddCountCombo(-999);
				PlaySound(SOUND_LABEL_SE_HIT);
				break;
				}
			}
		}
	}

	// プレイヤーと穴
	for (nCnt1 = 0; nCnt1 < MAX_HOLE; nCnt1++) {
		if (!IsHole(nCnt1))	continue;

		for (nCnt2 = 0; nCnt2 < MAX_PLAYER; nCnt2++) {
			//if (!IsPlayer(nCnt2))	continue;

			if (CollisionBB3D(
				&GetHolePos(nCnt1),
				&GetHoleSize(nCnt1),
				&GetPlayerCenter(nCnt2),
				&GetPlayerBBox(nCnt2)))
			{	// 当たった時の処理
				if (GetPlayerPhose(0) != JUMP) {
					PlayerPhoseChange(nCnt2, FALL);
					PlaySound(SOUND_LABEL_SE_FALL);
				}
				break;
			}
		}
	}

	// プレイヤーとキャンディ
	for (nCnt1 = 0; nCnt1 < MAX_ITEM; nCnt1++) {
		if (!IsItem(nCnt1))	continue;

		for (nCnt2 = 0; nCnt2 < MAX_PLAYER; nCnt2++) {
			//if (!IsPlayer(nCnt2))	continue;

			if (CollisionBCy(
				&GetItemPos(nCnt1),
				GetItemSize(nCnt1).y,
				GetItemSize(nCnt1).x,
				&GetPlayerCenter(nCnt2),
				GetPlayerBBox(nCnt2).y,
				GetPlayerBBox(nCnt2).x))
			{	// 当たった時の処理
				DestroyItem(nCnt1);
				AddCountCombo(1);
				PlaySound(SOUND_LABEL_SE_CANDY);
				break;
			}
		}
	}

	// プレイヤーとチェックポイント
	for (nCnt1 = 0; nCnt1 < MAX_CHECKPOINT; nCnt1++) {
		if (!IsCheckPoint(nCnt1))	continue;

		for (nCnt2 = 0; nCnt2 < MAX_PLAYER; nCnt2++) {
			//if (!IsPlayer(nCnt2))	continue;

			if (CollisionBCy(
				&GetCheckPointPos(nCnt1),
				GetCheckPointSize(nCnt1).y,
				GetCheckPointSize(nCnt1).x,
				&GetPlayerCenter(nCnt2),
				GetPlayerBBox(nCnt2).y,
				GetPlayerBBox(nCnt2).x))
			{	// 当たった時の処理
				DestroyCheckPoint(nCnt1);
				SetCheckFlag(0, true);
				SetBeforeScore();
				PlaySound(SOUND_LABEL_SE_CHECKPOINT);
				break;
			}
		}
	}

	// プレイヤーとエンドロール
	for (nCnt1 = 0; nCnt1 < MAX_TEXT; nCnt1++) {
		if (!IsText(nCnt1))	continue;

		for (nCnt2 = 0; nCnt2 < MAX_PLAYER; nCnt2++) {
			if (!IsPlayer(nCnt2))	continue;

			if (CollisionBCy(
				&GetTextPos(nCnt1),
				GetTextSize(nCnt1).y,
				GetTextSize(nCnt1).x * 20.0f,
				&GetPlayerCenter(nCnt2),
				GetPlayerBBox(nCnt2).y,
				GetPlayerBBox(nCnt2).x))
			{	// 当たった時の処理
				if (GetPlayerPhose(nCnt2) == JUMP) {
					KillText(nCnt1);
					PlaySound(SOUND_LABEL_SE_HIT);
					break;
				}
			}
		}
	}
}

// バウンディングボックス
// 矩形同士の当たり判定
bool CollisionBB2D( XMFLOAT2 * pCenter1, XMFLOAT2 * pSize1, XMFLOAT2 * pCenter2, XMFLOAT2 * pSize2 )
{
	if( pCenter1->x + pSize1->x >= 
		pCenter2->x - pSize2->x && 
		pCenter1->x - pSize1->x <=
		pCenter2->x + pSize2->x )
	{	// X方向が当たっている
		if( pCenter1->y + pSize1->y >=
			pCenter2->y - pSize2->y &&
			pCenter1->y - pSize1->y <=
			pCenter2->y + pSize2->y )
		{	// Y方向も当たっている
			return true;
		}
	}
	// 当たらなかった
	return false;
}

// バウンディングサークル
// 円同士の当たり判定
bool CollisionBC( XMFLOAT2 * pCenter1, float fRadius1, XMFLOAT2 * pCenter2, float fRadius2 )
{
	float fx = pCenter1->x - pCenter2->x;
	float fy = pCenter1->y - pCenter2->y;
	float len = fx * fx + fy * fy;
	float fr = fRadius1 + fRadius2;
	if( len < fr * fr )
	{
		return true;	// 当たった
	}

	return false;		// 当たってない
}

// 矩形
bool CollisionBB3D(XMFLOAT3* pCenter1, XMFLOAT3* pSize1, XMFLOAT3* pCenter2, XMFLOAT3* pSize2)
{
	if (pCenter1->x + pSize1->x >=
		pCenter2->x - pSize2->x &&
		pCenter1->x - pSize1->x <=
		pCenter2->x + pSize2->x)
	{	// X方向が当たっている
		if (pCenter1->y + pSize1->y >=
			pCenter2->y - pSize2->y &&
			pCenter1->y - pSize1->y <=
			pCenter2->y + pSize2->y)
		{	// Y方向も当たっている
			if (pCenter1->z + pSize1->z >=
				pCenter2->z - pSize2->z &&
				pCenter1->z - pSize1->z <=
				pCenter2->z + pSize2->z)
			{	// X軸方向も当たっている
				return true;
			}
		}
	}
	// 当たらなかった
	return false;
}

// 球
bool CollisionBS(XMFLOAT3* pCenter1, float fRadius1, XMFLOAT3* pCenter2, float fRadius2)
{
	float fx = pCenter1->x - pCenter2->x;
	float fy = pCenter1->y - pCenter2->y;
	float fz = pCenter1->z - pCenter2->x;
	float len = fx * fx + fy * fy + fz * fz;
	float fr = fRadius1 + fRadius2;
	if (len < fr * fr)
	{
		return true;	// 当たった
	}

	return false;		// 当たってない
}

// 円柱
bool CollisionBCy(XMFLOAT3* pCenter1, float height1, float fRadius1, XMFLOAT3* pCenter2, float height2, float fRadius2)
{
	if (pCenter1->y + height1 >=
		pCenter2->y - height2 &&
		pCenter1->y - height1 <=
		pCenter2->y + height2)
	{	// Y軸方向が範囲内
		float fx = pCenter1->x - pCenter2->x;
		float fz = pCenter1->z - pCenter2->z;
		float len = fx * fx + fz * fz;
		float fr = fRadius1 + fRadius2;
		if (len < fr * fr) {
			return true;	// 当たった
		}
	}
	return false;
}