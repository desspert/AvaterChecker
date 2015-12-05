#include "UIManager.h"



UIManager::UIManager()
{
}


UIManager::~UIManager()
{
	for (int index = 0; index < UIList.size(); ++index)
	{
		delete UIList.at(index);
		UIList.at(index) = nullptr;
	}
}

UIBase& UIManager::RegisterUI(UIBase* _pAddUI)
{
	UIList.emplace_back(_pAddUI);
	return *_pAddUI;
}


void UIManager::Update()
{
	for (int index = 0; index < UIList.size(); ++index)
	{
		UIList.at(index)->Update();
	}
}

void UIManager::Render()
{
	for (int index = 0; index < UIList.size(); ++index)
	{
		UIList.at(index)->Render();
	}

}
