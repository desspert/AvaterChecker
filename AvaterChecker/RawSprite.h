#pragma once

#include "UIBase.h"
/*************************************
**
** Spriteクラス
** * UIBaseを元に描画する機能
** があります。
**
*************************************/
class RawSprite : public UIBase
{
public:
	explicit RawSprite(vec2i _position,vec2i _size, int _grapHandle);
	~RawSprite();


	/**
	 * 描画する画像を設定する
	 * 引数：変更する画像のハンドル
	 */
	void SetGraph(int _graphHandle);

	/**
	 * 描画する画像を取得する
	 * 戻り値：描画する画像のハンドル
	 */
	int GetGraph()const;


	void Update() {};
	/**
	 * 画像を描画する
	 * m_sizeの位置、サイズを基本とします。
	 */
	void Render();

protected:

	//! ResourceManagerから画像のハンドルを得る
	int m_graphic;
private:
};

