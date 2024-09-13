#pragma once
#include <Vector2.h>
#include <Novice.h>
#include <JumpEffect.h>

class Goal;

class Tile;

class Player {
	public:
	void Initilize();
    void Update();
	void Draw();
	void SetGoal(Goal* goal) { goal_ = goal; };
	void SetTile(Tile* tile) { tile_ = tile; }
	Vector2 GetPosition() { return Position; };
	float GetSize() { return  Size; }
	
	int GetScroll() { return (int)scrollX; }
	bool GetGoalSceneFlag() { return GoalsceneFlag; }

	void BLUEFlag();
	void BLUEFlag2();
	void REDFlag();
	void REDFlag2();

	bool IsDrop() { return isdrop; }

	void CheckCollisionWithTile();

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
	bool isdrop;

	//スクロール
	float startScrollX;
	float scrollX;
	float kWindowWidth = 1280;
	float endscroll;


	Goal* goal_ = nullptr;
	int goaltimer;
	int goalendtimer;

	Tile* tile_ = nullptr;

	const float Size = 16;
	const float Gravity=3;

	JumpEffect jumpEffect_;
	bool isEffectActive = false; 
	float effectTimer = 0.0f;

	//ゴールしたか
	bool goalFlag;
	bool GoalsceneFlag;

	int Image[2] = {Novice::LoadTexture("./Resources/Player_1.png"), Novice::LoadTexture("./Resources/Player_2.png")};

	int SoundSE[3] = {Novice::LoadAudio("./Resources/Sound/Down.wav"),
					Novice::LoadAudio("./Resources/Sound/Jump1.wav"), 
					Novice::LoadAudio("./Resources/Sound/Jump2.wav")
	};
};