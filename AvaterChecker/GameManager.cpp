#include "GameManager.h"
#include "ResourceManager.h"
#include "UIManager.h"
#include "RawSprite.h"
#include "ChangeGraphButton.h"

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::Initialize()
{
	ResourceManager::GetInstance().LoadResources();
	UIInitialize();

}


void GameManager::UIInitialize()
{
	RawSprite* pBG = new RawSprite(vec2i(0, 0), vec2i(GameManager::WindowInformation::Width, GameManager::WindowInformation::Height),
		ResourceManager::GetInstance().GetGraphicByName("bg"));

	const int selectedGraphicStartY = 60;
	RawSprite* pSelectedGraphic = new RawSprite(vec2i(GameManager::WindowInformation::Width / 4, selectedGraphicStartY),
		vec2i(GameManager::WindowInformation::Width / 2, GameManager::WindowInformation::Height / 2),
		ResourceManager::GetInstance().GetGraphicByName("activatedBoy"));

	const int buttonStartX = 100;
	const int buttonStartY = GameManager::WindowInformation::Height - 150;
	const int buttonSize = 100;
	ChangeGraphButton* pBoyButton = new ChangeGraphButton(vec2i(buttonStartX, buttonStartY),
		vec2i(buttonSize, buttonSize),
		ResourceManager::GetInstance().GetGraphicByName("boy"),
		ResourceManager::GetInstance().GetGraphicByName("activatedBoy"),
		*pSelectedGraphic);

	ChangeGraphButton* pGirlButton = new ChangeGraphButton(vec2i(GameManager::WindowInformation::Width / 2 - buttonSize / 2, buttonStartY),
		vec2i(buttonSize, buttonSize),
		ResourceManager::GetInstance().GetGraphicByName("girl"),
		ResourceManager::GetInstance().GetGraphicByName("activatedGirl"),
		*pSelectedGraphic);

	ChangeGraphButton* pManButton = new ChangeGraphButton(vec2i(GameManager::WindowInformation::Width / 2 + buttonStartX, buttonStartY),
		vec2i(buttonSize, buttonSize),
		ResourceManager::GetInstance().GetGraphicByName("man"),
		ResourceManager::GetInstance().GetGraphicByName("activatedMan"),
		*pSelectedGraphic);

	//! �o�^
	UIManager::GetInstance().RegisterUI(pBG);
	UIManager::GetInstance().RegisterUI(pBoyButton);
	UIManager::GetInstance().RegisterUI(pGirlButton);
	UIManager::GetInstance().RegisterUI(pManButton);
	UIManager::GetInstance().RegisterUI(pSelectedGraphic);

}


void GameManager::GameMainLoop()
{

	Update();

	Render();

}


void GameManager::Update()
{
	UIManager::GetInstance().Update();
}

void GameManager::Render()
{
	//! �`�悳��Ă���摜����x�폜����
	ClearDrawScreen();

	//! �����ɑ��N���X���̕`�揈�����L�q����
	UIManager::GetInstance().Render();


	//! �o�b�N�o�b�t�@�ɕ`�悳��Ă���摜��\������
	ScreenFlip();
}
