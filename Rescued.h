#pragma once
#include "struct.h"
#include "Player.h"

class Rescued {
//�N���X�ϐ�
public:
	Transform transform;
	int r;
	int isRescued;
	Player* player;

//�N���X�֐�
public:
	Rescued();
	~Rescued();
	void RescuedCollision();
	void Move();
	void Draw();
};