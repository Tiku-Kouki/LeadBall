#include "Player.h"

void Player::Start() {

	Position = {50,500};
	Speed = {3, 3};
	BlueFlag = true;
	RedFlag = false;
	velocity = {2.0f, -10.0f};
	isJump = false;
	acceleration = {0.0f, 0.2f};
	
	jumpEffect.Initialize(Position);
	effectTimer = 8;
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
	if (isEffectActive) {
		effectTimer--;
		if (effectTimer == 0) {
			effectTimer = 8;
			isEffectActive = false;
		}
	}
	jumpEffect.SetEffectFlag(isEffectActive);
		
	
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
		jumpEffect.SetPosition(Position);
	}
	if (Position.y >= 800)
	{
		Position.y = 500;
		Position.x = 0;
		velocity.y = -10.0f;
		isJump = false;
		jumpEffect.Initialize(Position);
	}
	jumpEffect.Update();
	/*if (BlueFlag == true && RedFlag == false) {
		velocity.y = -10.0f;
	} else if (BlueFlag == false && RedFlag == true) {
		velocity.y = -15.0f;
	}*/
	//重力
	//Position.y += Gravity;
	
}

void Player::Draw() {
	jumpEffect.Draw();
	//ボール青くなる
	if (BlueFlag == true && RedFlag == false) {
		Novice::DrawSprite((int)Position.x-32, (int)Position.y-32, Image[1], 2, 2, 0.0f, WHITE);
	}
	//ボール赤くなる
	if (BlueFlag == false && RedFlag == true) {
		Novice::DrawSprite((int)Position.x-32, (int)Position.y-32, Image[0], 2, 2, 0.0f, WHITE);
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
	isEffectActive = true;
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
	isEffectActive = true;
}

void Player::REDFlag2() { RedFlag = false; }
