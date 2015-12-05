#pragma once

#include "UIBase.h"
/*************************************
**
** Sprite�N���X
** * UIBase�����ɕ`�悷��@�\
** ������܂��B
**
*************************************/
class RawSprite : public UIBase
{
public:
	explicit RawSprite(vec2i _position,vec2i _size, int _grapHandle);
	~RawSprite();


	/**
	 * �`�悷��摜��ݒ肷��
	 * �����F�ύX����摜�̃n���h��
	 */
	void SetGraph(int _graphHandle);

	/**
	 * �`�悷��摜���擾����
	 * �߂�l�F�`�悷��摜�̃n���h��
	 */
	int GetGraph()const;


	void Update() {};
	/**
	 * �摜��`�悷��
	 * m_size�̈ʒu�A�T�C�Y����{�Ƃ��܂��B
	 */
	void Render();

protected:

	//! ResourceManager����摜�̃n���h���𓾂�
	int m_graphic;
private:
};

