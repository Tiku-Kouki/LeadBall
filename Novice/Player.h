#pragma once
#include <Vector2.h>
#include <Novice.h>

class Player {
	public:
	void Start();
    void Update();
	void Draw();

	private:
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector2 Position;
	Vector2 Speed;
	bool BlueFlag;
	bool RedFlag;

	const float Size = 32;
	const float Gravity=1;

	int Image[2] = {Novice::LoadTexture("./ResorceO/Player_1.png"), Novice::LoadTexture("./ResorceO/Player_2.png")};
};
