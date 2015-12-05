#include "ChangeGraphButton.h"

#include "DxLib.h"

ChangeGraphButton::ChangeGraphButton(const vec2i& _position, const vec2i& _size, int _grapHandle,int _changedGraphHandle,RawSprite& _changingSprite):
	ButtonBase(_position, _size, _grapHandle),
	m_originGraphic(_grapHandle),
	m_changedGraphic(_changedGraphHandle),
	m_refChangingSprite(_changingSprite)
{
}


ChangeGraphButton::~ChangeGraphButton()
{
}

void ChangeGraphButton::Update()
{

	//! オンカーソル時の処理
	if (OnMousePoint())
	{

		m_graphic = m_changedGraphic;

		//! クリック時の処理
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		{
			RunEvent();
		}
	}
	else
	{
		m_graphic = m_originGraphic;
	}
}


void ChangeGraphButton::RunEvent()
{
	ChangeGraphic();
}


void ChangeGraphButton::ChangeGraphic()
{
	m_refChangingSprite.SetGraph(m_changedGraphic);
}
