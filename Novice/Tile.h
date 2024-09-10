#pragma once
#include<Vector2.h>
#include <Novice.h>
#include"mouse.h"
#include <memory>

class Player;

class Tile {
public:
	void Initialize();

	void Update();

	void Draw();

	void SetPlayer(Player* player) { player_ = player; };

	
private:
	//タイル
	Vector2 tilepos[11];
	int tileradius[11];
	bool istile[11];
	Vector2 redtilepos[5];
	int redtileradius[5];
	Vector2 fixedtilepos[10];
	Vector2 fixedredtilepos[10];
	int fixedtileradius[10];
	int fixedredtileradius[10];
	bool isfixedtile[10];
	bool isfixedredtile[10];
	bool isredtile[5];
	
	bool isOnCollision;
	bool isRedOnCollision;
	
	Vector2 pos;
	std::unique_ptr<mouse> Mouse;
	Player* player_ = nullptr;
	

	char keys[256];
	char preKeys[256];

};
