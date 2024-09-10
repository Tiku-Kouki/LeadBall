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
	for (int i = 0; i < 10; i++)
	{
		fixedtilepos[i] = {0.0f};
		fixedredtilepos[i] = {0.0f};
		fixedtileradius[i] = 100;
		fixedredtileradius[i]=100;
		isfixedtile[i]=true;
		isfixedredtile[i]=true;
	}
	Mouse = std::make_unique<mouse>();
	fixedtilepos[0] = {100.0f, 500.0f};
	fixedtilepos[1] = {250.0f, 500.0f};
	fixedredtilepos[0] = {400.0f, 500.0f};
	isOnCollision = false;
}

void Tile::Update() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	Mouse->GetMouse();
	

	for (int i = 0; i < 11; i++) {
	
		if (isOnCollision==false&&Mouse->leftGetMouse() && istile[i] == false) {
			tilepos[i] = Mouse->SetMouse();
			istile[i] = true;
			break;
		}
		
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
		{
			istile[i] = false;
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
			break;
		}
		
			
		
		
	}

	for (int i = 0; i < 20; i++)
	{
		if (tilepos[i].x <= Mouse->SetMouse().x && Mouse->SetMouse().x <= tilepos[i].x + tileradius[0] && tilepos[i].y <= Mouse->SetMouse().y &&
		    Mouse->SetMouse().y <= tilepos[i].y + tileradius[1] && istile[i] == true) {
			isOnCollision = true;
			break;
		} else {
			isOnCollision = false;
		}
	}

	for (int i = 0; i < 20; i++) {
		if (redtilepos[i].x <= Mouse->SetMouse().x && Mouse->SetMouse().x <= redtilepos[i].x + redtileradius[0] && redtilepos[i].y <= Mouse->SetMouse().y && Mouse->SetMouse().y <= redtilepos[i].y + redtileradius[1] &&
		    isredtile[i] == true) {
			isRedOnCollision = true;
			break;
		} else {
			isRedOnCollision = false;
		}
	}

	for (int i = 1; i < 5; i++) {
		if (Mouse->RightGetMouse()) {
			if (isredtile[i] == false&&isRedOnCollision==false) {
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

	for (int i = 0; i < 10; i++) {
		if (player_->GetPosition().x <= fixedtilepos[i].x + fixedtileradius[0] && fixedtilepos[i].x <= player_->GetPosition().x + player_->GetSize() && 
			player_->GetPosition().y <= fixedtilepos[i].y + fixedtileradius[1] && fixedtilepos[i].y <= player_->GetPosition().y + player_->GetSize() && isfixedtile[i] == true) {
			player_->BLUEFlag();
		}
		if (player_->GetPosition().x <= fixedredtilepos[i].x + fixedredtileradius[0] && fixedredtilepos[i].x <= player_->GetPosition().x + player_->GetSize() &&
		    player_->GetPosition().y <= fixedredtilepos[i].y + fixedredtileradius[1] && fixedredtilepos[i].y <= player_->GetPosition().y + player_->GetSize() && isfixedredtile[i] == true) {
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
	for (int i = 0; i < 10; i++) {
		Novice::DrawBox((int)fixedtilepos[i].x+i*2, (int)fixedtilepos[i].y, fixedtileradius[i], fixedtileradius[i], 0.0f, BLUE, kFillModeSolid);
		Novice::DrawBox((int)fixedredtilepos[i].x+i*4, (int)fixedredtilepos[i].y, fixedredtileradius[i], fixedredtileradius[i], 0.0f, RED, kFillModeSolid);
	}
	
}




