#include "Player.h"

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
	int map[20][50] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	//�}�b�v�̗�̐�
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	//�}�b�v�̗�̐�
	int mapCountY = sizeof(map) / sizeof(map[0]);
	//�u���b�N�T�C�Y�̐ݒ�
	const int BLOCK_SIZE = 48;

	//�X�e�B�b�N����
	DINPUT_JOYSTATE padInput;
	int pad;


	//�v���C���[
	Player* player = new Player();

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

		//�v���C���[�ʒu�̕ۑ�
		player->SaveOldPlayer();

		//�v���C���[�̈ړ�
		player->PlayerMove(padInput.X,padInput.Rx,padInput.Ry);
		player->PlayerJump(pad);

		//�e�̔���
		player->PlayerShot(padInput.Rx, padInput.Ry);

		//�e�̋���
		player->bullet->BulletMove(player->G);

		//�}�b�v�`�b�v��̍��W�ʒu�̎擾
		player->GetPlayer(BLOCK_SIZE);
		player->GetOldPlayer(BLOCK_SIZE);
		player->bullet->GetBullet(BLOCK_SIZE);

		//�����蔻��
		if (map[player->leftTopY][player->leftTopX] == BLOCK) {
			if (map[player->oldLeftTopY][player->leftTopX] == NONE && map[player->leftTopY][player->oldLeftTopX] == NONE) {}

			else if (map[player->oldLeftTopY][player->leftTopX] == NONE && map[player->leftTopY][player->oldLeftTopX] == BLOCK) {
				player->player.transform.y = player->oldPlayer.y;

			}

			else if (map[player->oldLeftTopY][player->leftTopX] == BLOCK && map[player->leftTopY][player->oldLeftTopX] == NONE) {
				player->player.transform.x = player->oldPlayer.x;
			}

			else if (map[player->oldLeftTopY][player->leftTopX] == BLOCK && map[player->leftTopY][player->oldLeftTopX] == BLOCK) {
				player->player.transform.x = player->oldPlayer.x;
				player->player.transform.y = player->oldPlayer.y;
			}
		}
		if (map[player->rightTopY][player->rightTopX] == BLOCK) {
			if (map[player->oldRightTopY][player->rightTopX] == NONE && map[player->rightTopY][player->oldRightTopX] == NONE) {}

			else if (map[player->oldRightTopY][player->rightTopX] == NONE && map[player->rightTopY][player->oldRightTopX] == BLOCK) {
				player->player.transform.y = player->oldPlayer.y;

			}

			else if (map[player->oldRightTopY][player->rightTopX] == BLOCK && map[player->rightTopY][player->oldRightTopX] == NONE) {
				player->player.transform.x = player->oldPlayer.x;
			}

			else if (map[player->oldRightTopY][player->rightTopX] == BLOCK && map[player->rightTopY][player->oldRightTopX] == BLOCK) {
				player->player.transform.x = player->oldPlayer.x;
				player->player.transform.y = player->oldPlayer.y;
			}
		}
		if (map[player->leftBottomY][player->leftBottomX] == BLOCK) {
			if (player->player.jumpPow <= 0) {
				player->player.isJump = 0;
			}
			if (map[player->oldLeftBottomY][player->leftBottomX] == NONE && map[player->leftBottomY][player->oldLeftBottomX] == NONE) {}

			else if (map[player->oldLeftBottomY][player->leftBottomX] == NONE && map[player->leftBottomY][player->oldLeftBottomX] == BLOCK) {
				player->player.transform.y = player->oldPlayer.y;
			}

			else if (map[player->oldLeftBottomY][player->leftBottomX] == BLOCK && map[player->leftBottomY][player->oldLeftBottomX] == NONE) {
				player->player.transform.x = player->oldPlayer.x;
			}

			else if (map[player->oldLeftBottomY][player->leftBottomX] == BLOCK && map[player->leftBottomY][player->oldLeftBottomX] == BLOCK) {
				player->player.transform.x = player->oldPlayer.x;
				player->player.transform.y = player->oldPlayer.y;
			}
		}
		if (map[player->rightBottomY][player->rightBottomX] == BLOCK) {
			if (player->player.jumpPow <= 0) {
				player->player.isJump = 0;
			}
			if (map[player->oldRightBottomY][player->rightBottomX] == NONE && map[player->rightBottomY][player->oldRightBottomX] == NONE) {}

			else if (map[player->oldRightBottomY][player->rightBottomX] == NONE && map[player->rightBottomY][player->oldRightBottomX] == BLOCK) {
				player->player.transform.y = player->oldPlayer.y;
			}

			else if (map[player->oldRightBottomY][player->rightBottomX] == BLOCK && map[player->rightBottomY][player->oldRightBottomX] == NONE) {
				player->player.transform.x = player->oldPlayer.x;
			}

			else if (map[player->oldRightBottomY][player->rightBottomX] == BLOCK && map[player->rightBottomY][player->oldRightBottomX] == BLOCK) {
				player->player.transform.x = player->oldPlayer.x;
				player->player.transform.y = player->oldPlayer.y;
			}
		}

		for (int i = 0; i < player->bullet->BULLET_CONST; i++) {
			if (map[player->bullet->leftTopY[i]][player->bullet->leftTopX[i]] == BLOCK) {
				player->bullet->bullet[i].isBullet = false;
			}
			if (map[player->bullet->leftBottomY[i]][player->bullet->leftBottomX[i]] == BLOCK) {
				player->bullet->bullet[i].isBullet = false;
			}
			if (map[player->bullet->rightTopY[i]][player->bullet->rightTopX[i]] == BLOCK) {
				player->bullet->bullet[i].isBullet = false;
			}
			if (map[player->bullet->rightBottomY[i]][player->bullet->rightBottomX[i]] == BLOCK) {
				player->bullet->bullet[i].isBullet = false;
			}
		}

		//�X�N���[��
		player->GetScroll();

		// �`�揈��
		for (int y = 0; y < mapCountY; y++) {
			for (int x = 0; x < mapCountX; x++) {
				if (map[y][x] == BLOCK) {
					DrawBox(x * BLOCK_SIZE - player->scroll, y * BLOCK_SIZE, (x + 1) * BLOCK_SIZE - player->scroll, (y + 1) * BLOCK_SIZE, GetColor(255, 255, 255), true);
				}
			}
		}

		player->DrawPlayer();
		player->bullet->DrawBullet(player->scroll);

		//�f�o�b�O
		DrawFormatString(0, 0, GetColor(255,255,255), "X:%d Y:%d Z:%d",
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

	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
