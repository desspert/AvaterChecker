#pragma once

#include <memory>

/**
 * GameManagerクラス ゲームアプリケーションの情報をまとめるクラス
 * 今回はワンシーンだったのでシーンの初期化や固有処理を記述している部分があります
 */
class GameManager
{
public:

	//! ウィンドウの情報
	enum WindowInformation
	{
		Width = 640,
		Height = 480,
		ColorBit = 32
	};


	/**
	 * GameManagerのインスタンスを得る。
	 * シングルトン用
	 */
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	/**
	 * 初期化
	 */
	void Initialize();

	/**
	 * ゲームのメインループを記述します。
	 */
	void GameMainLoop();

private:
	GameManager();
	~GameManager();

	/**
	 * 毎フレーム呼ぶ内部処理実行部
	 */
	void Update();

	/**
	* 毎フレーム呼ぶ描画処理実行部
	*/
	void Render();
	
	/**
	 * UIの初期化
	 */
	void UIInitialize();

};

