#include "Tile.h"
#include"Player.h"
void Tile::Initialize() {
	//青のタイルの初期化
	for (int i = 0; i < 11; i++) {
		tilepos[i].x = 0.0f;
		tilepos[i].y = 0.0f;
		tileradius[i] = 50;
		halfTileRadius[i] = 25;
		istile[i] = false;
	}
	//赤のタイルの初期化
	for (int i = 0; i < 6; i++) {
		redtilepos[i].x = 0.0f;
		redtilepos[i].y = 0.0f;
		redtileradius[i] = 50;
		halfRedTileRadius[i] = 25;
		isredtile[i] = false;
	}
	//固定タイルの初期化
	for (int i = 0; i < 15; i++)
	{
		fixedtilepos[i] = {0.0f};
		fixedredtilepos[i] = {0.0f};
		fixedtilepos[i].x = -200.0f;
		fixedredtilepos[i].x = -200.0f;
		fixedtileradius[i] = 50;
		fixedredtileradius[i] = 50;
		isfixedtile[i] = true;
		isfixedredtile[i] = true;
	}
	Mouse = std::make_unique<mouse>();

	
	
	isstage = false;
	isstage2 = false;
	isstage3 = false;
	

	isOnCollision = false;
}

void Tile::Update() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	Mouse->GetMouse();
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
	{
		isstage = true;
		isstage2 = false;
		isstage3 = false;
	}
	if (keys[DIK_LSHIFT] && preKeys[DIK_LSHIFT] == 0) {
		isstage2 = true;
		isstage = false;
		isstage3 = false;
	}
	if (keys[DIK_RSHIFT] && preKeys[DIK_RSHIFT] == 0) {
		isstage3 = true;
		isstage = false;
		isstage2 = false;
	}

	SelectStage();

	for (int i = 0; i < tileNum; i++) {
	
		if (isOnCollision==false&&Mouse->leftGetMouse() && istile[i] == false) {
			tilepos[i] = Mouse->SetMouse();
			tilepos[i].x += player_->GetScroll() - halfTileRadius[i];
			tilepos[i].y -= halfTileRadius[i];
			istile[i] = true;
			bluecaunter += 1;
			break;
		}
		
		
		   
		if (tilepos[i].x <= Mouse->SetMouse().x + player_->GetScroll() && 
			 Mouse->SetMouse().x + player_->GetScroll() <= tilepos[i].x + tileradius[0] && 
			tilepos[i].y <= Mouse->SetMouse().y  &&
		    Mouse->SetMouse().y <= tilepos[i].y + tileradius[1] && 
			istile[i] == true && Mouse->leftGetMouse()) {
			istile[i] = false;
			bluecaunter -= 1;
			break;
		}
		
		
		
		if (player_->GetPosition().x  <= tilepos[i].x + tileradius[0] && tilepos[i].x <= player_->GetPosition().x+ player_->GetSize() &&
		    player_->GetPosition().y <= tilepos[i].y + tileradius[1] &&
		    tilepos[i].y <= player_->GetPosition().y + player_->GetSize() &&
		    istile[i] == true)
		{
			player_->BLUEFlag();
			break;
		}
		
			
		
		
	}
	//クリックしたものを表示しなくするための処理
	for (int i = 0; i < 30; i++)
	{
		if (tilepos[i].x <= Mouse->SetMouse().x  && Mouse->SetMouse().x  <= tilepos[i].x + tileradius[0] && tilepos[i].y <= Mouse->SetMouse().y &&
		    Mouse->SetMouse().y <= tilepos[i].y + tileradius[1] && istile[i] == true) {
			isOnCollision = true;
			break;
		} else {
			isOnCollision = false;
		}
	}

	for (int i = 0; i < 30; i++) {
		if (redtilepos[i].x <= Mouse->SetMouse().x + player_->GetScroll() && Mouse->SetMouse().x + player_->GetScroll() <= redtilepos[i].x + redtileradius[0] &&
		    redtilepos[i].y <= Mouse->SetMouse().y &&
		    Mouse->SetMouse().y <= redtilepos[i].y + redtileradius[1] &&
		    isredtile[i] == true) {
			isRedOnCollision = true;
			break;
		} else {
			isRedOnCollision = false;
		}
	}
	//------------------------------------//

	for (int i = 0; i < redtileNum; i++) {
		if (Mouse->RightGetMouse()) {
			if (isredtile[i] == false&&isRedOnCollision==false) {
				redtilepos[i] = Mouse->SetMouse() ;
				redtilepos[i].x += player_->GetScroll() - halfRedTileRadius[i];
				redtilepos[i].y -= halfRedTileRadius[i];
				isredtile[i] = true;
				redcaunter += 1;
				break;
			}
		}
		if (redtilepos[i].x <= Mouse->SetMouse().x + player_->GetScroll() && 
			Mouse->SetMouse().x + player_->GetScroll() <= redtilepos[i].x + redtileradius[0] && 
			redtilepos[i].y <= Mouse->SetMouse().y&&
		    Mouse->SetMouse().y <= redtilepos[i].y + redtileradius[1] && 
			isredtile[i] == true && Mouse->RightGetMouse() ) {
			isredtile[i] = false;
			redcaunter -= 1;
			break;
		}
		if (player_->GetPosition().x <= redtilepos[i].x + redtileradius[0] && redtilepos[i].x <= player_->GetPosition().x + player_->GetSize() &&
		    player_->GetPosition().y <= redtilepos[i].y + redtileradius[1] &&
		    redtilepos[i].y <= player_->GetPosition().y + player_->GetSize() && isredtile[i] == true) {
			player_->REDFlag();
			break;
		}
	}

	for (int i = 0; i < 15; i++) {
		if (player_->GetPosition().x <= fixedtilepos[i].x + fixedtileradius[0] && fixedtilepos[i].x <= player_->GetPosition().x + player_->GetSize() &&
		    player_->GetPosition().y <= fixedtilepos[i].y + fixedtileradius[1] && fixedtilepos[i].y <= player_->GetPosition().y + player_->GetSize() && isfixedtile[i] == true ) {
			
			player_->BLUEFlag();
			break;
		}
		if (player_->GetPosition().x <= fixedredtilepos[i].x + fixedredtileradius[0] && fixedredtilepos[i].x <= player_->GetPosition().x + player_->GetSize() &&
		    player_->GetPosition().y <= fixedredtilepos[i].y + fixedredtileradius[1] && fixedredtilepos[i].y <= player_->GetPosition().y + player_->GetSize() && isfixedredtile[i] == true) {
		
			player_->REDFlag();
			break;
		}
	}


	
}

void Tile::Draw() {
	
	for (int i = 0; i < tileNum; i++) {
		if (istile[i] == true) {
			Novice::DrawBox((int)tilepos[i].x - player_->GetScroll(), (int)tilepos[i].y, tileradius[i], tileradius[i], 0.0f, BLUE, kFillModeSolid);
			Novice::DrawBox((int)tilepos[i].x - player_->GetScroll(), (int)tilepos[i].y, tileradius[i], tileradius[i], 0.0f, BLACK, kFillModeWireFrame);
		}
		
	}
	for (int i = 0; i < redtileNum; i++) {
		if (isredtile[i] == true) {
			Novice::DrawBox((int)redtilepos[i].x - player_->GetScroll(), (int)redtilepos[i].y, redtileradius[i], redtileradius[i], 0.0f, RED, kFillModeSolid);
			Novice::DrawBox((int)redtilepos[i].x - player_->GetScroll(), (int)redtilepos[i].y, redtileradius[i], redtileradius[i], 0.0f, BLACK, kFillModeWireFrame);
		}
	}
	for (int i = 0; i < 15; i++) {
		if (isfixedtile[i] == true) {
			Novice::DrawBox((int)fixedtilepos[i].x + i * 2 - player_->GetScroll(), (int)fixedtilepos[i].y, fixedtileradius[i], fixedtileradius[i], 0.0f, BLUE, kFillModeSolid);
			Novice::DrawBox((int)fixedtilepos[i].x + i * 2 - player_->GetScroll(), (int)fixedtilepos[i].y, fixedtileradius[i], fixedtileradius[i], 0.0f, WHITE, kFillModeWireFrame);
		}
		if (isfixedredtile[i] == true) {
			Novice::DrawBox((int)fixedredtilepos[i].x + i * 4 - player_->GetScroll(), (int)fixedredtilepos[i].y, fixedredtileradius[i], fixedredtileradius[i], 0.0f, RED, kFillModeSolid);
			Novice::DrawBox((int)fixedredtilepos[i].x + i * 4 - player_->GetScroll(), (int)fixedredtilepos[i].y, fixedredtileradius[i], fixedredtileradius[i], 0.0f, WHITE, kFillModeWireFrame);
		}
	}

	
	/*	for (int i = 0; i < 70; i++)
		{
		Novice::DrawLine(0 + (50 * i) - player_->GetScroll(), 0 , 0 + (50 * i) - player_->GetScroll(), 720, BLACK);
		}
	    for (int j = 0; j < 14; j++) {
		    Novice::DrawLine(0 - player_->GetScroll(), 0 + (50 * j) , 3960 - player_->GetScroll(), 0 + (50 * j) , BLACK);
	    }*/
	
}

void Tile::SelectStage() 
{
	// ステージ1にする処理
	if (isstage == true) {
		fixedtilepos[0] = {100.0f, 500.0f};
		fixedtilepos[1] = {198.0f, 500.0f};
		fixedtilepos[2] = {296.0f, 500.0f};
		fixedtilepos[3] = {494.0f, 500.0f};
		fixedtilepos[4] = {692.0f, 500.0f};
		fixedredtilepos[0] = {900.0f, 500.0f};
		fixedredtilepos[1] = {1046.0f, 500.0f};
		fixedredtilepos[2] = {1192.0f, 500.0f};
		fixedredtilepos[3] = {1488.0f, 500.0f};
		fixedredtilepos[4] = {1783.0f, 500.0f};
		fixedtilepos[5] = {2089.0f, 500.0f};
		fixedtilepos[6] = {2338.0f, 500.0f};
		fixedredtilepos[5] = {2530.0f, 500.0f};
		tileNum = 7;
		redtileNum = 5;
	}
	// ステージ2にする処理
	if (isstage2 == true) {
		fixedtilepos[0] = {100.0f, 500.0f};
		fixedtilepos[1] = {198.0f, 500.0f};
		fixedtilepos[2] = {248.0f, 450.0f};
		fixedtilepos[3] = {298.0f, 400.0f};
		fixedtilepos[4] = {398.0f, 500.0f};
		fixedtilepos[5] = {492.0f, 500.0f};
		fixedtilepos[6] = {602.0f, 400.0f};
		fixedtilepos[7] = {692.0f, 500.0f};
		fixedredtilepos[0] = {792.0f, 500.0f};
		fixedredtilepos[1] = {892.0f, 400.0f};
		fixedredtilepos[2] = {992.0f, 300.0f};
		fixedredtilepos[3] = {1092.0f, 500.0f};
		fixedredtilepos[4] = {1242.0f, 500.0f};
		fixedredtilepos[5] = {1442.0f, 300.0f};
		fixedtilepos[8] = {1692.0f, 500.0f};
		fixedredtilepos[6] = {1742.0f, 450.0f};
		fixedredtilepos[7] = {2042.0f, 300.0f};
		fixedtilepos[9] = {2292.0f, 450.0f};
		fixedredtilepos[8] = {2392.0f, 500.0f};
		fixedredtilepos[9] = {2542.0f, 450.0f};
		fixedredtilepos[10] = {2692.0f, 450.0f};
		fixedtilepos[11] = {3142.0f, 450.0f};
		fixedredtilepos[10] = {3292.0f, 450.0f};
		bluecaunter = 11;
		redcaunter = 8;
	}
	//ステージ3にする処理
	if (isstage3 == true) {
		fixedredtilepos[0] = {100.0f, 500.0f};
		fixedredtilepos[1] = {250.0f, 600.0f};
		fixedtilepos[0] = {350.0f, 550.0f};
		fixedtilepos[1] = {500.0f, 350.0f};
		fixedtilepos[2] = {750.0f, 550.0f};
		fixedtilepos[3] = {900.0f, 500.0f};
		fixedredtilepos[1] = {950.0f, 450.0f};
		fixedtilepos[4] = {1050.0f, 300.0f};
		fixedredtilepos[2] = {1150.0f, 400.0f};
		fixedtilepos[5] = {1350.0f, 500.0f};
		fixedtilepos[6] = {1550.0f, 500.0f};
		fixedtilepos[7] = {1650.0f, 550.0f};
		fixedredtilepos[3] = {1800.0f, 550.0f};
		fixedtilepos[8] = {2000.0f, 550.0f};
		fixedtilepos[9] = {2050.0f, 500.0f};
		fixedtilepos[10] = {2100.0f, 450.0f};
		fixedtilepos[11] = {2300.0f, 250.0f};
		fixedredtilepos[4] = {2400.0f, 500.0f};
		fixedtilepos[12] = {2550.0f, 500.0f};
		fixedtilepos[13] = {2600.0f, 450.0f};
		fixedredtilepos[4] = {2800.0f, 450.0f};
		tileNum = 12;
		redtileNum = 6;
	}
}




