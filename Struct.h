#pragma once
#include "Global.h"

//�v���C���[�̒�`
typedef struct {
	int x;
	int y;
} Transform;

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