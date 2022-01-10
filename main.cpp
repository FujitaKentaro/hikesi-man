#include "Player.h"
#include "Bullet.h"
#include "Map.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���


	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	//�X�e�B�b�N����
	DINPUT_JOYSTATE padInput;
	int pad;


	//�v���C���[
	Player* player = new Player();
	//��
	Bullet* bullet = new Bullet();
	//�}�b�v
	Map* map = new Map();

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}
		//�z��Ȃ̂�oldkey - keys;�̂悤�ɂł��Ȃ��B�v�f���P���R�s�[

		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
		GetJoypadDirectInputState(DX_INPUT_PAD1, &padInput);
		pad = GetJoypadInputState(DX_INPUT_PAD1);

		//�}�b�v�I��
		map->SelectMap1();

		//�v���C���[�ʒu�̕ۑ�
		player->SaveOldPlayer();

		//�v���C���[�̈ړ�
		player->PlayerMove(padInput.X, padInput.Rx, padInput.Ry);
		player->PlayerJump(pad);

		//�e�̔���
		player->PlayerShot(padInput.Rx, padInput.Ry);

		//�e�̋���
		player->bullet->BulletMove(player->G);

		//�}�b�v�`�b�v��̍��W�ʒu�̎擾
		player->GetPlayer(map->BLOCK_SIZE);
		player->GetOldPlayer(map->BLOCK_SIZE);
		bullet->GetBullet(map->BLOCK_SIZE);

		//�����蔻��
		player->BlockCollision(map->map);
		bullet->BlockCollision(map->map);

		//�X�N���[��
		player->GetScroll();

		// �`�揈��
		map->DrawMap(map->map, player->scroll);
		player->DrawPlayer();
		player->bullet->DrawBullet(player->scroll);

		//�f�o�b�O
		DrawFormatString(0, 0, GetColor(255, 255, 255), "X:%d Y:%d Z:%d",
			padInput.X, padInput.Y, padInput.Z);
		DrawFormatString(0, 16, GetColor(255, 255, 255), "Rx:%d Ry:%d Rz:%d",
			padInput.Rx, padInput.Ry, padInput.Rz);

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}

	delete player;
	delete bullet;
	delete map;

	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
