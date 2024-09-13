#include "Back.h"

void Back::Initialize() {
	position[0].x = 0;
	position[1].x = 1280;
	position[2].x = 0;
	position[3].x = 1280;

	scrollX = 0;
}

void Back::Update() {

	position[2].x--;
	position[3].x--;
	

	for (int i = 0; i <4; i++) {
		if (position[i].x  <= -1280) {
			position[i].x = 1280;
		}
	}
}
	
void Back::Draw() { 
	Novice::DrawSprite((int)position[0].x - (int)scrollX, (int)position[0].y, BackSp[0], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[1].x - (int)scrollX, (int)position[1].y, BackSp[0], 1, 1, 0.0f, WHITE);

	Novice::DrawSprite((int)position[2].x- (int)scrollX, (int)position[2].y, BackSp[1], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[3].x- (int)scrollX, (int)position[3].y, BackSp[1], 1, 1, 0.0f, WHITE);
}
