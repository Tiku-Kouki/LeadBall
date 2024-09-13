#include "Back.h"

void Back::Initialize() {
	position[0].x = 0;
	position[1].x = 1280;
	position[2].x = 0;
	position[3].x = 1280;
	position[4].x = 2560;
	position[5].x = 2560;
	position[6].x = 3840;
	position[7].x = 3840;

}

void Back::Update() {

	position[3].x--;
	position[4].x--;
	position[5].x--;
	if (position[4].x <= -1280.0f + player_->GetScroll()) {
		position[4].x += 1280.0f /* - player_->GetScroll()*/;
	}
	if (position[6].x <= -1280.0f + player_->GetScroll()) {
		position[6].x += 1280.0f /* - player_->GetScroll()*/;
	}
	/*if (position[1].x <= -1280.0f - player_->GetScroll()) {
	    position[1].x += 1280.0f - player_->GetScroll();
	}
	if (position[2].x <= -1280.0f - player_->GetScroll()) {
	    position[2].x += 1280.0f - player_->GetScroll();
	}
	if (position[3].x <= -1280.0f - player_->GetScroll()) {
	    position[3].x += 1280.0f - player_->GetScroll();
	}*/
	if (player_->IsDrop()) {
		Initialize();
	}

	/*for (int i = 0; i < 4; i++) {
		if (position[i].x <= -1280.0f - player_->GetScroll()) {
			position[i].x += 1280.0f -player_->GetScroll();
		}
	}*/

	//if (position[0].x <= -1280.0f + player_->GetScroll()) {
	//	position[0].x += 1280.0f/* - player_->GetScroll()*/;
	//}
	//if (position[1].x <= -1280.0f + player_->GetScroll()) {
	//	position[1].x += 1280.0f /* - player_->GetScroll()*/;
	//}
	/*if (position[1].x <= -1280.0f - player_->GetScroll()) {
		position[1].x += 1280.0f - player_->GetScroll();
	}
	if (position[2].x <= -1280.0f - player_->GetScroll()) {
		position[2].x += 1280.0f - player_->GetScroll();
	}
	if (position[3].x <= -1280.0f - player_->GetScroll()) {
		position[3].x += 1280.0f - player_->GetScroll();
	}*/
}
	
void Back::Draw() { 
	Novice::DrawSprite((int)position[0].x - player_->GetScroll(), (int)position[0].y, BackSp[0], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[1].x - player_->GetScroll(), (int)position[1].y, BackSp[0], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[4].x - player_->GetScroll(), (int)position[4].y, BackSp[0], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[6].x - player_->GetScroll(), (int)position[6].y, BackSp[0], 1, 1, 0.0f, WHITE);

	Novice::DrawSprite((int)position[2].x - player_->GetScroll(), (int)position[2].y, BackSp[1], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[3].x - player_->GetScroll(), (int)position[3].y, BackSp[1], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[5].x - player_->GetScroll(), (int)position[5].y, BackSp[1], 1, 1, 0.0f, WHITE);
	Novice::DrawSprite((int)position[7].x - player_->GetScroll(), (int)position[7].y, BackSp[1], 1, 1, 0.0f, WHITE);


}
