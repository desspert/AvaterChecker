#pragma once

#include "DxLib.h"

#include <map>
#include <string>
#include <assert.h>

/**
 * ���\�[�X���Ǘ�����N���X
 * �摜�݂̂�z��
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
	 * ���\�[�X�̓ǂݍ��݂�����
	 */
	void LoadResources()
	{
		//! ���C���V�[���Ŏg�p���郊�\�[�X�ǂݍ���(�֐�������ƂȂ��ǂ�)
		RegisterResource("bg", "res/bg.png");
		RegisterResource("boy", "res/�j�q.png");
		RegisterResource("activatedBoy", "res/�j�q����.png");
		RegisterResource("girl", "res/���q.png");
		RegisterResource("activatedGirl", "res/���q����.png");
		RegisterResource("man", "res/����.png");
		RegisterResource("activatedMan", "res/��������.png");

	}

	/**
	 * ���łɓo�^�����摜��o�^���̖��O�Ŏ擾����
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
	 * �摜��o�^����
	 * �����P�F�o�^���閼�O(std::string)
	 * �����Q�F�o�^���郊�\�[�X�̂���p�X
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


	//! ���\�[�X���i�[����ϐ�
	std::map<std::string, int> m_graphicList;


};