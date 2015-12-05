#include "Button.h"
#include "DxLib.h"


ButtonBase::ButtonBase(const vec2i& _position, const vec2i& _size, int _grapHandle):
	RawSprite(_position, _size, _grapHandle)
{
}


ButtonBase::~ButtonBase()
{
}




bool ButtonBase::OnMousePoint()const
{
	int mouseX, mouseY;

	GetMousePoint(&mouseX, &mouseY);

	if (mouseX < m_position.x || mouseX > m_position.x + m_size.x
	||  mouseY < m_position.y || mouseY > m_position.y + m_size.y)
	{
		return false;
	}

	return true;

}
