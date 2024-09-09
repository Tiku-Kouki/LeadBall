#pragma once
#include <Vector2.h>
#include <Novice.h>
class Player {
	public:
	void Start();
    void Update();
	void Draw();
	Vector2 GetPosition() { return Position; };
	float GetSize() { return  Size; }
	
	void BLUEFlag();
	void BLUEFlag2();
	void REDFlag();
	void REDFlag2();

	private:
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector2 Position;
	Vector2 Speed;
	Vector2 velocity;
	//加速度
	Vector2 acceleration;
	bool BlueFlag;
	bool RedFlag;
	bool isJump;
	

	const float Size = 32;
	const float Gravity=3;

	int Image[2] = {Novice::LoadTexture("./ResorceO/Player_1.png"), Novice::LoadTexture("./ResorceO/Player_2.png")};
};
