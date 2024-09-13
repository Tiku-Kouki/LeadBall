#include "Back.h"

void Back::Initialize() {
	position[0].x = 0;
	position[1].x = 1280;
	position[2].x = 2560;
	position[3].x = 0;
	position[4].x = 1280;
	position[5].x = 2560;
}

void Back::Update() {

	position[3].x -= 0.5f;
	position[4].x -= 0.5f;
	position[5].x -= 0.5f;

	for (int i = 0; i < 4; i++) {
		if (position[i].x <= -1280.0f - player_->GetScroll()) {
			position[i].x = 1280.0f - player_->GetScroll();
		}
	}
}

void Back::Draw() {
	Novice::DrawSprite((int)position[0].x - player_->GetScroll(), (int)position[0].y, BackSp[0], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[1].x - player_->GetScroll(), (int)position[1].y, BackSp[0], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[2].x - player_->GetScroll(), (int)position[2].y, BackSp[0], 1, 1, 0.0f, WHITE);


	Novice::DrawSprite((int)position[3].x - player_->GetScroll(), (int)position[3].y, BackSp[1], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[4].x - player_->GetScroll(), (int)position[4].y, BackSp[1], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[5].x - player_->GetScroll(), (int)position[5].y, BackSp[1], 1, 1, 0.0f, WHITE);
}
