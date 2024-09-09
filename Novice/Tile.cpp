#include "Tile.h"

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

}

void Tile::Update() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);
	if (keys[DIK_D]) {
		tilepos[0].x += 1.0f;
	}
	if (keys[DIK_A]) {
		tilepos[0].x -= 1.0f;
	}
	for (int i = 1; i < 11; i++) {
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			if (istile[i] == false) {
				tilepos[i] = tilepos[0];
				istile[i] = true;
				break;
			}
		}
		if (tilepos[i].x <= tilepos[0].x + tileradius[0] && 
			tilepos[0].x <= tilepos[i].x + tileradius[0] && 
			tilepos[i].y <= tilepos[0].y + tileradius[1] &&
		    tilepos[0].y <= tilepos[i].y + tileradius[1] && 
			istile[i] == true && keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
			istile[i] = false;
			break;
		}
	}

	for (int i = 1; i < 5; i++) {
		if (keys[DIK_LSHIFT] && preKeys[DIK_LSHIFT] == 0) {
			if (isredtile[i] == false) {
				redtilepos[i] = tilepos[0];
				isredtile[i] = true;
				break;
			}
		}
		if (redtilepos[i].x <= tilepos[0].x + tileradius[0] && tilepos[0].x <= redtilepos[i].x + redtileradius[0] && redtilepos[i].y <= tilepos[0].y + tileradius[1] &&
		    tilepos[0].y <= redtilepos[i].y + redtileradius[1] && isredtile[i] == true && keys[DIK_LSHIFT] && preKeys[DIK_LSHIFT] == 0) {
			isredtile[i] = false;
			break;
		}
	}
}

void Tile::Draw() {
	Novice::DrawBox((int)tilepos[0].x, (int)tilepos[0].y, tileradius[0], tileradius[0], 0.0f, BLUE, kFillModeSolid);
	for (int i = 1; i < 11; i++) {
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
