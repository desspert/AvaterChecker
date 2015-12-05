#pragma once

#include <memory>

/**
 * GameManager�N���X �Q�[���A�v���P�[�V�����̏����܂Ƃ߂�N���X
 * ����̓����V�[���������̂ŃV�[���̏�������ŗL�������L�q���Ă��镔��������܂�
 */
class GameManager
{
public:

	//! �E�B���h�E�̏��
	enum WindowInformation
	{
		Width = 640,
		Height = 480,
		ColorBit = 32
	};


	/**
	 * GameManager�̃C���X�^���X�𓾂�B
	 * �V���O���g���p
	 */
	static GameManager& GetInstance()
	{
		static GameManager instance;
		return instance;
	}

	/**
	 * ������
	 */
	void Initialize();

	/**
	 * �Q�[���̃��C�����[�v���L�q���܂��B
	 */
	void GameMainLoop();

private:
	GameManager();
	~GameManager();

	/**
	 * ���t���[���Ăԓ����������s��
	 */
	void Update();

	/**
	* ���t���[���Ăԕ`�揈�����s��
	*/
	void Render();
	
	/**
	 * UI�̏�����
	 */
	void UIInitialize();

};

