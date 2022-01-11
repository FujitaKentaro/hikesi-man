#include "Scene.h"

//�R���X�g���N�^
Scene::Scene() {
	player = new Player;
	bullet = new Bullet;
	rescued = new Rescued;
	map = new Map;
	fire = new Fire;
}

//�R���X�g���N�^
Scene::~Scene() {
	delete player;
	delete bullet;
	delete rescued;
	delete map;
	delete fire;
}


///-----�֐�-----///
void Scene::Update(char* keys,char* oldkeys) {
	if (keys == nullptr || oldkeys == nullptr) {
		printf("null\n");
		return;
	}
	GetJoypadDirectInputState(DX_INPUT_PAD1, &padInput);
	pad = GetJoypadInputState(DX_INPUT_PAD1);

	//�}�b�v�I��
	map->SelectMap1();

	//�΂̐ݒu
	if (keys[KEY_INPUT_F] == 1) {
		fire->SetFire(map->map);
	}

	//�v���C���[�ʒu�̕ۑ�
	player->SaveOldPlayer();

	//�v���C���[�̈ړ�
	player->PlayerMove(padInput.X, padInput.Rx, padInput.Ry);
	player->PlayerJump(pad);

	//�e�̔���
	player->PlayerShot(padInput.Rx, padInput.Ry);

	//�e�̋���
	player->bullet->BulletMove(player->G);

	//����
	fire->FireFighting(player->bullet->bullet);

	//�}�b�v�`�b�v��̍��W�ʒu�̎擾
	player->GetPlayer(map->BLOCK_SIZE);
	player->GetOldPlayer(map->BLOCK_SIZE);
	player->bullet->GetBullet(map->BLOCK_SIZE);

	//�����蔻��
	player->BlockCollision(map->map);
	player->bullet->BlockCollision(map->map);

	//�X�N���[��
	player->GetScroll();
}

void Scene::Draw() {
	// �`�揈��
	fire->DrawFire(player->scroll);
	map->DrawMap(map->map, player->scroll);
	player->DrawPlayer();
	player->bullet->DrawBullet(player->scroll);

	//�f�o�b�O
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	DrawBox(0, 0, 500, 100, GetColor(255, 255, 255), true);
	DrawFormatString(0, 0, GetColor(50, 50, 50), "X:%d Y:%d Z:%d",
		padInput.X, padInput.Y, padInput.Z);
	DrawFormatString(0, 16, GetColor(50, 50, 50), "Rx:%d Ry:%d Rz:%d",
		padInput.Rx, padInput.Ry, padInput.Rz);

	DrawFormatString(0, 32, GetColor(50, 50, 50), "���X�e�B�b�N�F�ړ��@�E�X�e�B�b�N�F����(���̂�)");
	DrawFormatString(0, 48, GetColor(50, 50, 50), "LB:�W�����v");
	DrawFormatString(0, 64, GetColor(50, 50, 50), "F�L�[:����(�f�o�b�O�p)");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}