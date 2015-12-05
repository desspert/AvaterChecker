#pragma once
#include "RawSprite.h"

/**
 * ButtonBase�N���X
 * UIBase>RawSprite���p�����Ă���B
 * RawSprite�ɃN���b�N�����ۂ̋�������������
 */
class ButtonBase : public RawSprite
{
public:
	ButtonBase(vec2i _position, vec2i _size, int _grapHandle);
	~ButtonBase();

	virtual void Update() {};
	virtual void Render() 
	{
		RawSprite::Render();
	}


protected:

	/**
	 * �}�E�X�����g�͈͓̔��ɂ��邩�ǂ����𔻒f����
	 * �߂�l�Ftrue...�͈͓��i�I���J�[�\�� false...�͈͊O
	 */
	bool OnMousePoint();


	/**
	 * �ŗL�̋������L�q����
	 */
	virtual void RunEvent() = 0;

};

