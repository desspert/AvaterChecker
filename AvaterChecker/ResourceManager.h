#pragma once

#include "DxLib.h"

#include <map>
#include <string>
#include <assert.h>

/**
 * リソースを管理するクラス
 * 画像のみを想定
 */
class ResourceManager
{
public:
	
	static ResourceManager& GetInstance()
	{
		static ResourceManager instance;
		return instance;
	}

	/**
	 * リソースの読み込みをする
	 */
	void LoadResources()
	{
		//! メインシーンで使用するリソース読み込み(関数化するとなお良い)
		RegisterResource("bg", "res/bg.png");
		RegisterResource("boy", "res/男子.png");
		RegisterResource("activatedBoy", "res/男子差分.png");
		RegisterResource("girl", "res/女子.png");
		RegisterResource("activatedGirl", "res/女子差分.png");
		RegisterResource("man", "res/中世.png");
		RegisterResource("activatedMan", "res/中世差分.png");

	}

	/**
	 * すでに登録した画像を登録時の名前で取得する
	 */
	int GetGraphicByName(std::string searchName) const
	{
		if (m_graphicList.empty())
		{
			assert(!"m_graphicList is Empty");
		}

		auto foundIte = m_graphicList.find(searchName);
		if (foundIte == m_graphicList.end())
		{
			assert(!"searchName's value is not found");
		}

		return foundIte->second;

	}


	/**
	 * 画像を登録する
	 * 引数１：登録する名前(std::string)
	 * 引数２：登録するリソースのあるパス
	 */
	void RegisterResource(const std::string& _name,const std::string& _path)
	{

		if (m_graphicList.find(_name) != m_graphicList.end())
		{
			assert(!"That's Name is already used");
		}

		if((m_graphicList[_name] = LoadGraph(_path.c_str())) == -1)
		{
			assert(!"That's wrong path");
		}

	}

private:
	ResourceManager() {};
	~ResourceManager() {};


	//! リソースを格納する変数
	std::map<std::string, int> m_graphicList;


};