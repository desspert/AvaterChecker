#pragma once
#include "Button.h"


/**
* ChangeGraphButtonクラス
* UIBase>RawSprite>ButtonBase を継承している。
* クリックした際に画像を受け取っているRawSpriteの情報を変更する
*/
class ChangeGraphButton : public ButtonBase
{
public:
	/**
	 * インスタンス生成時に、変更前と変更後の画像と、変更するRawSpriteの参照を得る
	 */
	ChangeGraphButton(const vec2i& _position,const vec2i& _size,
		int _grapHandle, int _refChangedGraphHandle,
		RawSprite& _changingSprite);
	~ChangeGraphButton();

	void Update();

	void Render()
	{
		RawSprite::Render();
	}

protected:
	//! クリック時の処理をまとめた実装部
	void RunEvent();

private:

	//! 画像を変更する処理
	void ChangeGraphic();

	//! ボタンに初期状態のボタンの画像を記憶する
	int m_originGraphic;

	//! ボタンに変更後のボタンの画像を記憶する
	int m_changedGraphic;

	//! 変更を与えるSpriteの情報
	RawSprite& m_refChangingSprite;

};

