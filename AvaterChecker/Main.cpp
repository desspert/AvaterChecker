/**
 * �T�v�F���C���֐�
 * ���C�����[�v�������ɋL�q����܂��B
 */

#include "DxLib.h"
#include "GameManager.h"



//! DxLib�����y�[�W����R�s�y���������ł��B
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//! �E�B���h�E���[�h�ŕ`�悷��悤�ɐݒ�
	ChangeWindowMode(TRUE);

	//! �E�B���h�E�T�C�Y�A�g�p�J���[�r�b�g���̎w��
	SetGraphMode(GameManager::WindowInformation::Width, GameManager::WindowInformation::Height, GameManager::WindowInformation::ColorBit);
	
	//! �`�����o�b�N�o�b�t�@�ɂ���i���ScreenFlip�ɂ���ĕ\�ɂ���K�v������B�j
	SetDrawScreen(DX_SCREEN_BACK);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}



	GameManager::GetInstance().Initialize();

	//���C�����[�v
	while (ProcessMessage() == false && CheckHitKey(KEY_INPUT_ESCAPE) == FALSE)
	{

		GameManager::GetInstance().GameMainLoop();
	}


	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}