#pragma once
#include "UIBase.h"
#include <vector>

/**
 * UI�𑍂��ĊǗ�����N���X
 */
class UIManager
{
public:

	static UIManager& GetInstance()
	{
		static UIManager instance;
		return instance;
	}

	//! UIList�ɓo�^����
	UIBase& RegisterUI(UIBase* _pAddUI);
	
	void Update();

	void Render();
private :
	UIManager();
	~UIManager();

	//! �o�^���ꂽ���̂����s���郊�X�g
	std::vector<UIBase*> UIList;	

};

