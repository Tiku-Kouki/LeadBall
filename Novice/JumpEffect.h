#pragma once
#include <Vector2.h>
class JumpEffect {
public:
	void Initialize(Vector2 position);

	void Update();

	void Draw();

	void SetPosition(Vector2 position) { emitterPosition = position; };

	void SetEffectFlag(bool effectFlag) { EffectFlag = effectFlag; };

private:
	typedef struct Particle {
		bool isActive;                 // パーティクルが生きてるかのフラグ
		Vector2 Position;             // パーティクルの位置
		const Vector2 emitterMax; // パーティクルの放出範囲の最大値
		const Vector2 emitter;       // パーティクルのx座標の放出範囲の最大値
		float lifeTime;           // パーティクルの寿命
		Vector2 velocity;
	}Particle;

	 static const int MAX_PARTICLES = 100;
	Particle particles[MAX_PARTICLES];
	Vector2 emitterPosition;   
	/*typedef struct vector {
		Vector2 Position;
		float radius;
	};*/

	Particle particle[100]{true,0,0,1280,16,5,5};

	float effectDuration = 1.0f;
	float displayTime = 0.0f;
	bool EffectFlag = false;
};
