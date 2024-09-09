#include "Tile.h"
#include"Player.h"
void Tile::Initialize() {
	for (int i = 0; i < 11; i++) {
		tilepos[i].x = 0.0f;
		tilepos[i].y = 0.0f;
		tileradius[i] = 100;
		istile[i] = false;
	}
	for (int i = 0; i < 5; i++) {
		redtilepos[i].x = 0.0f;
		redtilepos[i].y = 0.0f;
		redtileradius[i] = 100;
		isredtile[i] = false;
	}
	Mouse = std::make_unique<mouse>();
	
	
}

void Tile::Update() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	Mouse->GetMouse();
	

	for (int i = 0; i < 11; i++) {
		if (Mouse->leftGetMouse()) {
			if (istile[i] == false) {
				tilepos[i] = Mouse->SetMouse();
				istile[i] = true;
				break;
			}
		}
		if (tilepos[i].x <= Mouse->SetMouse().x && 
			 Mouse->SetMouse().x <= tilepos[i].x + tileradius[0] && 
			tilepos[i].y <= Mouse->SetMouse().y  &&
		    Mouse->SetMouse().y <= tilepos[i].y + tileradius[1] && 
			istile[i] == true && Mouse->leftGetMouse()) {
			istile[i] = false;
			break;
		}
		if (player_->GetPosition().x <= tilepos[i].x + tileradius[0] && tilepos[i].x <= player_->GetPosition().x + player_->GetSize() && player_->GetPosition().y <= tilepos[i].y + tileradius[1] &&
		    tilepos[i].y <= player_->GetPosition().y + player_->GetSize() &&
		    istile[i] == true)
		{
			player_->BLUEFlag();
		}
	}

	for (int i = 1; i < 5; i++) {
		if (Mouse->RightGetMouse()) {
			if (isredtile[i] == false) {
				redtilepos[i] = Mouse->SetMouse();
				isredtile[i] = true;
				break;
			}
		}
		if (redtilepos[i].x <= Mouse->SetMouse().x&& 
			Mouse->SetMouse().x <= redtilepos[i].x + redtileradius[0] && 
			redtilepos[i].y <= Mouse->SetMouse().y&&
		    Mouse->SetMouse().y <= redtilepos[i].y + redtileradius[1] && 
			isredtile[i] == true && Mouse->RightGetMouse() ) {
			isredtile[i] = false;
			break;
		}
		if (player_->GetPosition().x <= redtilepos[i].x + redtileradius[0] && redtilepos[i].x <= player_->GetPosition().x + player_->GetSize() &&
		    player_->GetPosition().y <= redtilepos[i].y + redtileradius[1] &&
		    redtilepos[i].y <= player_->GetPosition().y + player_->GetSize() && isredtile[i] == true) {
			player_->REDFlag();
		}
	}
	
}

void Tile::Draw() {
	
	for (int i = 0; i < 11; i++) {
		if (istile[i] == true) {
			Novice::DrawBox((int)tilepos[i].x, (int)tilepos[i].y, tileradius[i], tileradius[i], 0.0f, BLUE, kFillModeSolid);
		}
	}
	for (int i = 0; i < 5; i++) {
		if (isredtile[i] == true) {
			Novice::DrawBox((int)redtilepos[i].x, (int)redtilepos[i].y, redtileradius[i], redtileradius[i], 0.0f, RED, kFillModeSolid);
		}
	}
	
}




