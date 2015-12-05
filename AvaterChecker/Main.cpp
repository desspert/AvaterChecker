/**
 * 概要：メイン関数
 * メインループがここに記述されます。
 */

#include "DxLib.h"
#include "GameManager.h"



//! DxLib公式ページからコピペしただけです。
// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//! ウィンドウモードで描画するように設定
	ChangeWindowMode(TRUE);

	//! ウィンドウサイズ、使用カラービット数の指定
	SetGraphMode(GameManager::WindowInformation::Width, GameManager::WindowInformation::Height, GameManager::WindowInformation::ColorBit);
	
	//! 描画先をバックバッファにする（後でScreenFlipによって表にする必要がある。）
	SetDrawScreen(DX_SCREEN_BACK);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}



	GameManager::GetInstance().Initialize();

	//メインループ
	while (ProcessMessage() == false && CheckHitKey(KEY_INPUT_ESCAPE) == FALSE)
	{

		GameManager::GetInstance().GameMainLoop();
	}


	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}