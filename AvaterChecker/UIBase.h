#pragma once

/** 
 * vec2i�N���X
 * x,y��2������int�^�ŗp�ӂ��܂�
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
 * UIBase�N���X
 * UI�Ŏg�p����N���X�̊���N���X
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
	* UI�̈ʒu��ݒ肷��
	* �����F�ݒ肷��width,height
	*/
	void SetPosition(vec2i _position)
	{
		m_position = _position;
	}

	/**
	* UI�̈ʒu���擾����
	* �߂�l:vec2i�^(x,y)
	*/
	vec2i GetPosition()
	{
		return m_position;
	}

	/**
	 * UI�̃T�C�Y��ݒ肷��
	 * �����F�ݒ肷��width,height
	 */
	void SetSize(vec2i _newSize)
	{
		m_size = _newSize;
	}

	/**
	 * UI�̃T�C�Y���擾����
	 * �߂�l:vec2i�^(x,y)
	 */
	vec2i GetSize()
	{
		return m_size;
	}

	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	//! �摜�̍���̍��W
	vec2i m_position;

	//! �摜�̉��A�c�̒���
	vec2i m_size;

private:
	//! �����̉摜�T�C�Y
	static const int defaultSize = 256;

};

