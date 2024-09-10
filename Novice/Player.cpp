#include "Player.h"
#include"Goal.h"
void Player::Start() {

	Position = {50,500};
	Speed = {3, 3};
	BlueFlag = true;
	RedFlag = false;
	velocity = {2.0f, -10.0f};
	isJump = false;
	acceleration = {0.0f, 0.2f};
	goaltimer = 0;
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
	}
	/*if (BlueFlag == true && RedFlag == false) {
		velocity.y = -10.0f;
	} else if (BlueFlag == false && RedFlag == true) {
		velocity.y = -15.0f;
	}*/
	//重力
	//Position.y += Gravity;

	if (Position.x <= goal_->GetPosition().x + goal_->GetRadius().x &&
		goal_->GetPosition().x <= Position.x + Size &&
		Position.y <= goal_->GetPosition().y + Size &&
		goal_->GetPosition().y <= Position.y + Size)
	{
		if (goaltimer <= 100) {
			velocity.x = 0.0f;
			velocity.y = 0.0f;
			goaltimer++;
		}
		if (goaltimer >= 101)
		{
			velocity.y = -5.0f;
			goalendtimer++;
		}
		if (goalendtimer >= 100)
		{
			goalendtimer = 101;
		}
	}
	
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

void Player::REDFlag() { velocity.y=-15.0f;
	BlueFlag = false;
	RedFlag = true;
}


//ジャンプの制限作る
