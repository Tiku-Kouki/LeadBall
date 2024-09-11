#include "Player.h"
#include"Goal.h"
#include"Tile.h"
void Player::Start() {

	Position = {25,465};
	Speed = {3, 3};
	BlueFlag = true;
	RedFlag = false;
	velocity = {1.97f, -10.0f};
	isJump = false;
	acceleration = {0.0f, 0.5f};
	
	// スクロール
	startScrollX = 500;
	scrollX = 0;

	goaltimer = 0;
	goalendtimer = 0;
	endscroll = 2000;
}

void Player::Update() { 
	// キー入力を受け取る
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

	//Position.x += Speed.x; 

	if (tile_->IsStage())
	{
		acceleration.y = 0.4f;
	}
	if (tile_->IsStage2()) {
		acceleration.y = 0.5f;
	}
	
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
		
	if (keys[DIK_D])
	{
		Position.x += velocity.x+40;
	}
	if (keys[DIK_A])
	{
		Position.x -= velocity.x+40;
	}
	
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
		Position.y = 465;
		Position.x = 25;
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
	// スクロールの処理
	if (Position.x >= kWindowWidth + startScrollX+endscroll) {

		scrollX = kWindowWidth+endscroll;
	} else if (Position.x >= startScrollX) {

		scrollX = Position.x - startScrollX;
	}
}





	


void Player::Draw() {
	Novice::DrawEllipse((int)Position.x - (int)scrollX, (int)Position.y, (int)Size, (int)Size, 0.0f, RED, kFillModeSolid);
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

void Player::REDFlag() { velocity.y=-15.0f;
	BlueFlag = false;
	RedFlag = true;
}


//ジャンプの制限作る
