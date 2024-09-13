#pragma once
#include <Vector2.h>
#include <Novice.h>
class Back {
public:
	void Initialize();
	void Update();
	void Draw();

	void SetScrollX(float ScrollX) { scrollX = ScrollX; };

private:
	Vector2 position[4];
	float scrollX;

	int BackSp[2] = {Novice::LoadTexture("./Resorce/Back.png"), Novice::LoadTexture("./Resorce/BackCloud.png")};
};