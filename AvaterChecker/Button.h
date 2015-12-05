#pragma once
#include "RawSprite.h"

/**
 * ButtonBaseクラス
 * UIBase>RawSpriteを継承している。
 * RawSpriteにクリックした際の挙動を実装する
 */
class ButtonBase : public RawSprite
{
public:
	ButtonBase(const vec2i& _position, const vec2i& _size, int _grapHandle);
	~ButtonBase();

	virtual void Update() {}
	virtual void Render() {}


protected:

	/**
	 * マウスが自身の範囲内にいるかどうかを判断する
	 * 戻り値：true...範囲内（オンカーソル false...範囲外
	 */
	bool OnMousePoint() const;


	/**
	 * 固有の挙動を記述する
	 */
	virtual void RunEvent() = 0 ;

};

