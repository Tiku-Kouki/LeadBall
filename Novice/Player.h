#pragma once
#include <Vector2.h>
#include <Novice.h>

class Goal;

class Player {
	public:
	void Start();
    void Update();
	void Draw();
	void SetGoal(Goal* goal) { goal_ = goal; };
	Vector2 GetPosition() { return Position; };
	float GetSize() { return  Size; }
	
	int GetScroll() { return (int)scrollX; }

	void BLUEFlag();
	void REDFlag();

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

	//スクロール
	float startScrollX;
	float scrollX;
	float kWindowWidth = 1280;


	Goal* goal_ = nullptr;
	int goaltimer;
	int goalendtimer;

	const float Size = 32;
	const float Gravity=3;

	int Image[2] = {Novice::LoadTexture("./ResorceO/Player_1.png"), Novice::LoadTexture("./ResorceO/Player_2.png")};
};
