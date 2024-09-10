#include "Player.h"

void Player::Start() {

	Position = {50,500};
	Speed = {3, 3};
	BlueFlag = true;
	RedFlag = false;
	velocity = {2.0f, -10.0f};
	isJump = false;
	acceleration = {0.0f, 0.2f};
	
	// スクロール
	startScrollX = 500;
	scrollX = 0;

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
	
	isJump = true;
		
	
	if (isJump == false)
	{
		velocity.y = -10.0f;
	}
	if (isJump == true)
	{
		Position.x += velocity.x;
		Position.y += velocity.y;
		// 重力
		velocity.y += acceleration.y;
	}
	if (Position.y >= 800)
	{
		Position.y = 500;
		Position.x = 0;
		velocity.y = -10.0f;
		isJump = false;

		scrollX = 0;
	}
	/*if (BlueFlag == true && RedFlag == false) {
		velocity.y = -10.0f;
	} else if (BlueFlag == false && RedFlag == true) {
		velocity.y = -15.0f;
	}*/
	//重力
	//Position.y += Gravity;


	//スクロールの処理
	if (Position.x >= kWindowWidth + startScrollX) {

		scrollX = kWindowWidth;
	}
	else if (Position.x >= startScrollX) {
	
		scrollX = Position.x - startScrollX;
	
	}

	
}

void Player::Draw() {
	Novice::DrawEllipse((int)Position.x , (int)Position.y, (int)Size, (int)Size, 0.0f, RED, kFillModeSolid);
	//ボール青くなる
	if (BlueFlag == true && RedFlag == false) {
		Novice::DrawSprite((int)Position.x - (int)scrollX, (int)Position.y, Image[1], 1, 1, 0.0f, WHITE);
	}
	//ボール赤くなる
	if (BlueFlag == false && RedFlag == true) {
		Novice::DrawSprite((int)Position.x- (int)scrollX, (int)Position.y, Image[0], 1, 1, 0.0f, WHITE);
	}
	
}

//Vector2 Player::GetPosition() { 
//	Vector2 position;
//	position.x = Position.x;
//	position.y = Position.y;
//	return position;
//}

void Player::BLUEFlag() 
{ velocity.y=-10.0f;
	BlueFlag = true;
	RedFlag = false;
}

void Player::BLUEFlag2() { 
	if (keys[DIK_A])
	{
		Position.x += 100;
	}
}

void Player::REDFlag() { velocity.y=-15.0f;
	BlueFlag = false;
	RedFlag = true;
}

void Player::REDFlag2() { RedFlag = false; }

//ジャンプの制限作る
