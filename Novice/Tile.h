#pragma once
#include<Vector2.h>
#include <Novice.h>
class Tile {
public:
	void Initialize();

	void Update();

	void Draw();

private:
	Vector2 tilepos[11];
	int tileradius[11];
	bool istile[11];
	Vector2 redtilepos[5];
	int redtileradius[5];
	bool isredtile[5];

	char keys[256];
	char preKeys[256];

};
