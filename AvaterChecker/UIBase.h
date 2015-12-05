#pragma once

/** 
 * vec2iクラス
 * x,yの2成分をint型で用意します
 */
struct vec2i
{
	vec2i()
	{
		x = y = 0;
	};

	vec2i(int _x, int _y) 
	{
		x = _x;
		y = _y;
	};

	int x;
	int y;
};


/**
 * UIBaseクラス
 * UIで使用するクラスの既定クラス
 */
class UIBase
{
public:
	UIBase():
		m_position(vec2i(0,0)), m_size(vec2i(defaultSize, defaultSize))
	{
	}
	UIBase(vec2i _position,vec2i _size):
		m_position(_position),m_size(_size)
	{
	}

	~UIBase() {}


	/**
	* UIの位置を設定する
	* 引数：設定するwidth,height
	*/
	void SetPosition(vec2i _position)
	{
		m_position = _position;
	}

	/**
	* UIの位置を取得する
	* 戻り値:vec2i型(x,y)
	*/
	vec2i GetPosition()
	{
		return m_position;
	}

	/**
	 * UIのサイズを設定する
	 * 引数：設定するwidth,height
	 */
	void SetSize(vec2i _newSize)
	{
		m_size = _newSize;
	}

	/**
	 * UIのサイズを取得する
	 * 戻り値:vec2i型(x,y)
	 */
	vec2i GetSize()
	{
		return m_size;
	}

	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	//! 画像の左上の座標
	vec2i m_position;

	//! 画像の横、縦の長さ
	vec2i m_size;

private:
	//! 初期の画像サイズ
	static const int defaultSize = 256;

};

