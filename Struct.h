#pragma once
#include "Global.h"

typedef struct {
	int x;
	int y;
} Transform;

//�v���C���[�̒�`
typedef struct {
	Transform transform;
	int r;
	int isJump;
	int jumpPow;
} PLAYER;

//�O�t���[���̃v���C���[�̒�`
typedef struct {
	int x;
	int y;
}OldPlayer;

//���̔���
typedef struct {
	Transform transform;
	int r;
	float speedX;
	float speedY;
	int isBullet;
}BULLET;