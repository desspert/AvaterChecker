#pragma once
#include "UIBase.h"
#include <vector>

/**
 * UIを総じて管理するクラス
 */
class UIManager
{
public:

	static UIManager& GetInstance()
	{
		static UIManager instance;
		return instance;
	}

	//! UIListに登録する
	UIBase& RegisterUI(UIBase* _pAddUI);
	
	void Update();

	void Render();
private :
	UIManager();
	~UIManager();

	//! 登録されたものを実行するリスト
	std::vector<UIBase*> UIList;	

};

