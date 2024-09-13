#pragma once
#include<Vector2.h>
#include <Novice.h>
#include"mouse.h"
#include <memory>
#include <algorithm>

class Player;

class Tile {
public:
	void Initialize();

	void Update();

	void Draw();

	void SetPlayer(Player* player) { player_ = player; };

	void SelectStage();

	void Stage1();
	void Stage2();
	void Stage3();

	void SelectUI();

	bool IsStage() { return isstage; }
	bool IsStage2() { return isstage2; }
	bool IsStage3() { return isstage3; }

	float Length(const Vector2& v);

	Vector2 Subtract(const Vector2& v1, Vector2& v2);

	bool IsCollision(Vector2 v, float radius, float minX, float maxX, float minY, float maxY);
	
private:
	//タイル
	Vector2 tilepos[11];
	int tileradius[11];
	int halfTileRadius[11];
	bool istile[11];

	Vector2 redtilepos[6];
	int redtileradius[6];
	int halfRedTileRadius[6];
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
	
	int SoundSE[2] = {Novice::LoadAudio("./Resorce/Sound/Left.mp3"), Novice::LoadAudio("./Resorce/Sound/Right.mp3")};


	char keys[256];
	char preKeys[256];

	int ui[11] = {Novice::LoadTexture("./Resorce/UI.png"), Novice::LoadTexture("./Resorce/0.png"), Novice::LoadTexture("./Resorce/1.png"),
				  Novice::LoadTexture("./Resorce/2.png"), Novice::LoadTexture("./Resorce/3.png"), Novice::LoadTexture("./Resorce/4.png"),
	              Novice::LoadTexture("./Resorce/5.png"),  Novice::LoadTexture("./Resorce/6.png"), Novice::LoadTexture("./Resorce/7.png"), 
				  Novice::LoadTexture("./Resorce/8.png"), Novice::LoadTexture("./Resorce/9.png")
	};

	const Vector2 ResetPos{1160, 60};
	const float ResetSize = 80;
};
