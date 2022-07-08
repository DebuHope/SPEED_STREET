//======================================================================================
// マップ進行度処理
// 制作：向出創
//======================================================================================

// ヘッダファイルのインクルード
#include"PlayerIcon.h"
#include"Texture.h"
#include"polygon.h"
#include "Player.h"
#include "Debugproc.h"
#include "Transition.h"
#include "CheckPoint.h"
#include "Game.h"

// マクロ定義
#define COMBO_POS_X	(305)
#define COMBO_POS_Y	(320)
#define COMBO_SIZE_X	(25)
#define COMBO_SIZE_Y	(25)

#define COMBO_TEXTURE		_T("data/texture/UI/PlayerIcon.png")

// グローバル変数宣言
static ID3D11ShaderResourceView* g_pTexture;

static XMFLOAT3 g_Position;		// 座標
static XMFLOAT2 g_Size;			// サイズ
static float	g_Angle;		// 回転角度
static XMFLOAT2 g_TexCoord;		// テクスチャ座標(ポリゴンの左上)(TextureCoordinate)
static XMFLOAT2 g_TexFrameSize;	// テクスチャを貼り付けるサイズ

static int		StageProgress;	// ステージ進捗

// static = 変数名が被っていてもここのヘッダファイルのみの変数になる

HRESULT LoadPlayerIcon()
{
	HRESULT hr = S_OK;
	ID3D11Device*	pDevice = GetDevice();

	hr = CreateTextureFromFile(pDevice, COMBO_TEXTURE, &g_pTexture);
	if (FAILED(hr)) return hr;

	StageProgress = 0;

	// ファイル読み込み
	FILE* fp;
	if ((fp = fopen("D_StageProgress.dat", "r")) != NULL) {
		// オープン成功
		fread(&StageProgress, sizeof(int), 1, fp);
		fclose(fp);
	}

	return hr;
}

//======================================================================================
// 初期化
//======================================================================================
void InitPlayerIcon()
{
	// パラメータの初期化
	g_Position		= XMFLOAT3(COMBO_POS_X, COMBO_POS_Y, 0.0f);
	g_Size			= XMFLOAT2(COMBO_SIZE_X, COMBO_SIZE_Y);
	g_Angle			= 0.0f;
	g_TexCoord		= XMFLOAT2(0.0f, 0.0f);
	g_TexFrameSize	= XMFLOAT2(1.0f, 1.0f);

	if (GetCheckFlag(0)) {
		g_Position.x = 447.5;
	}

	
}

//======================================================================================
// 終了
//======================================================================================
void UninitPlayerIcon()
{
	//// テクスチャ後片付け
	//for (int i = 0; i < MAX_TEXTURE; i++)
	//{
	//	SAFE_RELEASE(g_pTexture[i]);
	//}
}

//======================================================================================
// 更新
//======================================================================================
void UpdatePlayerIcon()
{
	g_Position.x += GetPlayerVel(0).z / 150;

	if (g_Position.x >= 590)
	{
		switch (GetSceneNo())
		{
		case SCENE_STAGE1_1:
			if(StageProgress <= 1)	StageProgress = 1;
			break;
		case SCENE_STAGE1_2:
			if (StageProgress <= 2)	StageProgress = 2;
			break;
		case SCENE_STAGE1_3:
			if (StageProgress <= 3)	StageProgress = 3;
			break;
		case SCENE_STAGE1_4:
			if (StageProgress <= 3)	StageProgress = 3;
			break;
		case SCENE_STAGE2_1:
			if (StageProgress <= 4)	StageProgress = 4;
			break;
		case SCENE_STAGE2_2:
			if (StageProgress <= 5)	StageProgress = 5;
			break;
		case SCENE_STAGE2_3:
			if (StageProgress <= 6)	StageProgress = 6;
			break;
		case SCENE_STAGE2_4:
			if (StageProgress <= 6)	StageProgress = 6;
			break;
		case SCENE_STAGE3_1:
			if (StageProgress <= 7)	StageProgress = 7;
			break;
		case SCENE_STAGE3_2:
			if (StageProgress <= 8)	StageProgress = 8;
			break;
		case SCENE_STAGE3_3:
			if (StageProgress <= 9)	StageProgress = 9;
			break;
		case SCENE_STAGE3_4:
			if (StageProgress <= 9)	StageProgress = 9;
			break;
		}
		// ファイルに書き込み
		FILE* fp;
		if ((fp = fopen("D_StageProgress.dat", "w")) != NULL) {
			// オープン成功
			fwrite(&StageProgress, sizeof(int), 1, fp);
			fclose(fp);
		}
		if (GetSceneNo() != SCENE_STAGE3_3) {
		StartChange(SCENE_SELECT, 2);
		}
		else {
			StartChange(SCENE_ENDING, 2);
		}
	}
}

//======================================================================================
// 描画
//======================================================================================
void DrawPlayerIcon()
{
	SetPolygonAngle(0.0f);				// 回転角度
	SetPolygonAlpha(1.0f);
	if (GetState() != 0 && GetState() != 2) {
		SetPolygonColor(0.3f, 0.3f, 0.3f);
	}
	else {
		SetPolygonColor(1.0f, 1.0f, 1.0f);
	}
	// ポリゴンの情報設定
	SetPolygonPos(g_Position.x, g_Position.y);		// 座標
	SetPolygonSize(COMBO_SIZE_X, COMBO_SIZE_Y);	// 大きさ
	SetPolygonAngle(g_Angle);				// 回転角度

	SetPolygonUV(g_TexCoord.x, g_TexCoord.y);	// UV座標
	SetPolygonFrameSize(g_TexFrameSize.x, g_TexFrameSize.y);	// 横幅縦幅
	SetPolygonTexture(g_pTexture);

	// ポリゴンの描画処理
	ID3D11DeviceContext*	pDeviceContext = GetDeviceContext();
	DrawPolygon(pDeviceContext);
}

XMFLOAT3 GetPlayerIconPos()
{
	return g_Position;
}

int GetStageProgress()
{
	return StageProgress;
}