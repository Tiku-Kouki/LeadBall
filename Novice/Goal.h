#pragma once
#include<Vector2.h>
#include<Novice.h>

class Player;

class Goal {
public:
	void Initialize();

	void Update();

	void Draw();

	void SetPlayer(Player* player) { player_ = player; };

	Vector2 GetPosition() { return position; }

	Vector2 GetRadius() { return radius; }

private:
	Vector2 position;

	Vector2 radius;
	//スタートも作っておく
	Vector2 startposition;
	Vector2 startradius;

	Player* player_ = nullptr;

};
