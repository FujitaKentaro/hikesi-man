#pragma once
#include "Struct.h"
#include "Map.h"

class Bullet {
public:
	Bullet();
	~Bullet();

public:
	void BulletShot(Transform transform, int x, int y);
	void BulletMove(const int G);
	void GetBullet(int BLOCK_SIZE);
	void BlockCollision(int map[][50]);

	void DrawBullet(int scroll);
public:
	const int BULLET_CONST = 500;
	BULLET bullet[500];

	//����̍��W
	int leftTopX[500];
	int leftTopY[500];
	//�����̍��W
	int leftBottomX[500];
	int	leftBottomY[500];
	//�E���̍��W
	int rightTopX[500];
	int rightTopY[500];
	//�E���̍��W
	int rightBottomX[500];
	int rightBottomY[500];

	//�}�b�v
	Map* map;
};