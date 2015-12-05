#pragma once
#include "Button.h"


/**
* ChangeGraphButton�N���X
* UIBase>RawSprite>ButtonBase ���p�����Ă���B
* �N���b�N�����ۂɉ摜���󂯎���Ă���RawSprite�̏���ύX����
*/
class ChangeGraphButton : public ButtonBase
{
public:
	/**
	 * �C���X�^���X�������ɁA�ύX�O�ƕύX��̉摜�ƁA�ύX����RawSprite�̎Q�Ƃ𓾂�
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
	//! �N���b�N���̏������܂Ƃ߂�������
	void RunEvent();

private:

	//! �摜��ύX���鏈��
	void ChangeGraphic();

	//! �{�^���ɏ�����Ԃ̃{�^���̉摜���L������
	int m_originGraphic;

	//! �{�^���ɕύX��̃{�^���̉摜���L������
	int m_changedGraphic;

	//! �ύX��^����Sprite�̏��
	RawSprite& m_refChangingSprite;

};

