#pragma once
#include<Vector2.h>
#include<Novice.h>
class Goal {
public:
	void Initialize();

	void Update();

	void Draw();

	Vector2 GetPosition() { return position; }

	Vector2 GetRadius() { return radius; }

private:
	Vector2 position;

	Vector2 radius;
	//スタートも作っておく
	Vector2 startposition;
	Vector2 startradius;

};
