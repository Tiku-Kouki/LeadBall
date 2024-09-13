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

	Vector2 position[8];

	int BackSp[2] = {Novice::LoadTexture("./Resorce/Back.png"), Novice::LoadTexture("./Resorce/BackCloud.png")};
};