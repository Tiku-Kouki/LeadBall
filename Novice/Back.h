#pragma once
#include <Vector2.h>
#include <Novice.h>
#include <Player.h>

class Back {
public:
	void Initialize();
	void Update();
	void Draw();

	void SetPlayer(Player* player) { player_ = player; };

private:
	Player* player_ = nullptr;

	Vector2 position[6];

	int BackSp[2] = {Novice::LoadTexture("./Resources/Back.png"), Novice::LoadTexture("./Resources/BackCloud.png")};
};