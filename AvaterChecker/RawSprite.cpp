#include "RawSprite.h"
#include "DxLib.h"
#include <assert.h>

RawSprite::RawSprite(vec2i _position, vec2i _size, int _grapHandle):
	UIBase::UIBase(_position,_size),m_graphic(_grapHandle)
{
}


RawSprite::~RawSprite()
{
}

void RawSprite::SetGraph(int _graphHandle)
{
	m_graphic = _graphHandle;
}

int RawSprite::GetGraph()const
{
	return m_graphic;
}

void RawSprite::Render()
{
	if (m_graphic == -1)
	{
		assert(!"m_graphic is null");
	}
	
	DrawExtendGraph(m_position.x, m_position.y, m_position.x + m_size.x , m_position.y + m_size.y, m_graphic,FALSE);
}