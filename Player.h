#pragma once
#include "Struct.h"
#include "Bullet.h"
#include "Map.h"

class Player {
public:
	Player();
	~Player();

public:
	void SaveOldPlayer();
	void GetPlayerBottom(int BLOCK_SIZE);
	void ResetIsJump(int map[][50]);

	void PlayerMove(int LInputX, int RInputX, int RInputY);
	void PlayerJump(int pad);
	void PlayerShot(int InputX, int InputY);
	void GetPlayer(int BLOCK_SIZE);
	void GetOldPlayer(int BLOCK_SIZE);
	void GetScroll();
	void BlockCollision(int map[][50]);
	void DownPlayer(int map[][50],int BLOCK_SIZE);

	void DrawPlayer();
public:
	PLAYER player;
	OldPlayer oldPlayer;

	//�v���C���[�̏㉺�ړ�����
	int inertia,inertiaSpeed;

	//����̍��W
	int leftTopX, leftTopY;
	//�����̍��W
	int leftBottomX, leftBottomY;
	//�E���̍��W
	int rightTopX, rightTopY;
	//�E���̍��W
	int rightBottomX, rightBottomY;
	//1�t���[���O�̍���̍��W
	int oldLeftTopX, oldLeftTopY;
	//1�t���[���O�̉E��̍��W
	int oldRightTopX, oldRightTopY;
	//1�t���[���O�̍����̍��W
	int oldLeftBottomX, oldLeftBottomY;
	//1�t���[���O�̉E���̍��W
	int oldRightBottomX, oldRightBottomY;

	//�W�����v�Ǘ��p�̍��W
	int jumpLeftBottomX, jumpLeftBottomY;
	int jumpRightBottomX, jumpRightBottomY;

	//�d��
	const int G = 15;

	//�X�N���[��
	int scroll;

	//�e
	Bullet* bullet;
	//�}�b�v
	Map* map;
};