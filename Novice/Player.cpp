#include "Player.h"

void Player::Start() {

	Position = {50,500};
	Speed = {3, 3};
	BlueFlag = true;
	RedFlag = false;
}

void Player::Update() { 
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//Position.x += Speed.x; 

	//色替え
	if (keys[DIK_R] != 0 && preKeys[DIK_R] == 0) {
		RedFlag = true;
		BlueFlag = false;
	}
	if (keys[DIK_B] != 0 && preKeys[DIK_B] == 0) {
		RedFlag = false;
		BlueFlag = true;
	}

	//ジャンプ
	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
		if (BlueFlag == true && RedFlag == false) {
			Position.y -= 100;
		} else if (BlueFlag == false && RedFlag == true) {
			Position.y -= 200;
		}
	}

	//重力
	Position.y += Gravity;
}

void Player::Draw() {
	 Novice::DrawEllipse((int)Position.x, (int)Position.y, (int)Size, (int)Size, 0.0f, RED, kFillModeSolid);
	//ボール青くなる
	if (BlueFlag == true && RedFlag == false) {
		Novice::DrawSprite((int)Position.x, (int)Position.y, Image[1], 1, 1, 0.0f, WHITE);
	}
	//ボール赤くなる
	if (BlueFlag == false && RedFlag == true) {
		Novice::DrawSprite((int)Position.x, (int)Position.y, Image[0], 1, 1, 0.0f, WHITE);
	}
}

//ジャンプの制限作る
