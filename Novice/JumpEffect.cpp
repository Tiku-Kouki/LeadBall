#include "JumpEffect.h"
#include <cstdlib>
#include <Novice.h>

void JumpEffect::Initialize(Vector2 position) {
	emitterPosition = position;

	for (int i = 0; i < MAX_PARTICLES; i++) {
		particles[i].isActive = false;
	}
}

void JumpEffect::Update() {
	for (int i = 0; i < MAX_PARTICLES; i++) {
		if (!particles[i].isActive) {
			//初期化
			particles[i].Position = emitterPosition;
			particles[i].velocity.x = static_cast<float>(rand() % 10 - 5);
			particles[i].velocity.y = static_cast<float>(rand() % 10 - 5);
			particles[i].lifeTime = 1.0f;
			particles[i].isActive = true;
			break;
		}
	}

	for (int i = 0; i < MAX_PARTICLES; i++) {
		if (particles[i].isActive) {
			particles[i].Position.x += particles[i].velocity.x;
			particles[i].Position.y += particles[i].velocity.y;
			particles[i].lifeTime -= 0.1f;

			if (particles[i].lifeTime <= 0) {
				particles[i].isActive = false;
			}
		}
	}
}

void JumpEffect::Draw() {
	if (EffectFlag) {
		for (int i = 0; i < MAX_PARTICLES; i++) {
			if (particles[i].isActive) {
				Novice::DrawEllipse(static_cast<int>(particles[i].Position.x) - (int)scrollX, static_cast<int>(particles[i].Position.y) + 5, 5, 5, 0.0f, WHITE, kFillModeSolid);
			}
		}
	}
}

