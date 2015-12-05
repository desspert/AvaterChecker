#pragma once
#include "UIBase.h"
#include <vector>

/**
 * UI‚ğ‘‚¶‚ÄŠÇ—‚·‚éƒNƒ‰ƒX
 */
class UIManager
{
public:

	static UIManager& GetInstance()
	{
		static UIManager instance;
		return instance;
	}

	//! UIList‚É“o˜^‚·‚é
	UIBase& RegisterUI(UIBase* _pAddUI);
	
	void Update();

	void Render();
private :
	UIManager();
	~UIManager();

	//! “o˜^‚³‚ê‚½‚à‚Ì‚ğÀs‚·‚éƒŠƒXƒg
	std::vector<UIBase*> UIList;	

};

