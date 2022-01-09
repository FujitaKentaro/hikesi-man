#include "Player.h"

Player::Player() {
	player = {
		{
			100,
			800
		},
		20,
		0,
		0
	};

	oldPlayer = {
		0,
		0
	};

	//����̍��W
	leftTopX = 0;
	leftTopY = 0;
	//�����̍��W
	leftBottomX = 0;
	leftBottomY = 0;
	//�E���̍��W
	rightTopX = 0;
	rightTopY = 0;
	//�E���̍��W
	rightBottomX = 0;
	rightBottomY = 0;
	//1�t���[���O�̍���̍��W
	oldLeftTopX = 0;
	oldLeftTopY = 0;
	//1�t���[���O�̉E��̍��W
	oldRightTopX = 0;
	oldRightTopY = 0;
	//1�t���[���O�̍����̍��W
	oldLeftBottomX = 0;
	oldLeftBottomY = 0;
	//1�t���[���O�̉E���̍��W
	oldRightBottomX = 0;
	oldRightBottomY = 0;

	scroll = 0;

	bullet = new Bullet;
}

Player::~Player() {
	delete bullet;
}

void Player::SaveOldPlayer() {
	oldPlayer.x = player.transform.x;
	oldPlayer.y = player.transform.y;
}

void Player::PlayerMove(int LInputX, int RInputX, int RInputY) {
	if (LInputX > 0 || LInputX < 0) {
		player.transform.x += LInputX / 200;
	}
	player.transform.y += G - player.jumpPow;

	if ((RInputX <= 0 && RInputY < 0) || (RInputX <= 0 && RInputY > 0) || RInputX < 0) {
		if (player.isJump == 1) {
			player.transform.x += (RInputX * -1) / 50;
			player.transform.y += (RInputY * -1) / 50;
		}
	}
}

void Player::PlayerJump(int pad) {
	if (pad & PAD_INPUT_6 && player.isJump == 0) {
		player.isJump = 1;
		player.jumpPow = 20;
	}

	if (player.isJump == 1 && player.jumpPow > 0) {
		player.jumpPow--;
	}
}

void Player::PlayerShot(int InputX, int InputY) {
	if ((InputX <= 0 && InputY < 0) || (InputX <= 0 && InputY > 0) || InputX < 0) {
		bullet->BulletShot(player.transform, InputX, InputY);
	}
}

void Player::GetPlayer(int BLOCK_SIZE) {
	//����̍��W�̎擾
	leftTopX = (player.transform.x - player.r) / BLOCK_SIZE;
	leftTopY = (player.transform.y - player.r) / BLOCK_SIZE;
	//�E��̍��W�̎擾
	rightTopX = (player.transform.x + player.r - 1) / BLOCK_SIZE;
	rightTopY = (player.transform.y - player.r) / BLOCK_SIZE;
	//�����̍��W�̎擾
	leftBottomX = (player.transform.x - player.r) / BLOCK_SIZE;
	leftBottomY = (player.transform.y + player.r - 1) / BLOCK_SIZE;
	//�E���̍��W�̎擾
	rightBottomX = (player.transform.x + player.r - 1) / BLOCK_SIZE;
	rightBottomY = (player.transform.y + player.r - 1) / BLOCK_SIZE;
}

void Player::GetOldPlayer(int BLOCK_SIZE) {
	//1�t���[���O�̍���̍��W�̎擾
	oldLeftTopX = (oldPlayer.x - player.r) / BLOCK_SIZE;
	oldLeftTopY = (oldPlayer.y - player.r) / BLOCK_SIZE;
	//1�t���[���O�̉E��̍��W�̎擾
	oldRightTopX = (oldPlayer.x + player.r - 1) / BLOCK_SIZE;
	oldRightTopY = (oldPlayer.y - player.r) / BLOCK_SIZE;
	//1�t���[���O�̍����̍��W�̎擾
	oldLeftBottomX = (oldPlayer.x - player.r) / BLOCK_SIZE;
	oldLeftBottomY = (oldPlayer.y + player.r - 1) / BLOCK_SIZE;
	//1�t���[���O�̉E���̍��W�̎擾
	oldRightBottomX = (oldPlayer.x + player.r - 1) / BLOCK_SIZE;
	oldRightBottomY = (oldPlayer.y + player.r - 1) / BLOCK_SIZE;
}

void Player::GetScroll() {
	if (player.transform.x >= WIN_WIDTH / 2 && player.transform.x <= WIN_WIDTH + (WIN_WIDTH / 2)) {
		scroll = player.transform.x - WIN_WIDTH / 2;
	}
}


void Player::DrawPlayer() {
	DrawBox(player.transform.x - player.r - scroll, player.transform.y - player.r,
		player.transform.x + player.r - scroll, player.transform.y + player.r, GetColor(200, 200, 200), true);
}