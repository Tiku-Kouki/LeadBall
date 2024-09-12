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

	void SelectStage();

	bool IsStage() { return isstage; }
	bool IsStage2() { return isstage2; }
	bool IsStage3() { return isstage3; }
	
private:
	//タイル
	Vector2 tilepos[11];
	int tileradius[11];
	bool istile[11];

	Vector2 redtilepos[6];
	int redtileradius[6];
	bool isredtile[6];

	Vector2 fixedtilepos[15];
	Vector2 fixedredtilepos[15];
	int fixedtileradius[15];
	int fixedredtileradius[15];
	bool isfixedtile[15];
	bool isfixedredtile[15];
	
	int tileNum;
	int redtileNum;
	
	bool isOnCollision;
	bool isRedOnCollision;

	bool isstage;
	bool isstage2;
	bool isstage3;

	//確認用
	int bluecaunter;
	int redcaunter;
	
	Vector2 pos;
	std::unique_ptr<mouse> Mouse;
	Player* player_ = nullptr;
	

	char keys[256];
	char preKeys[256];

};
