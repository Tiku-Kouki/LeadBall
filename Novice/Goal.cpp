#include "Goal.h"
#include"Player.h"
void Goal::Initialize() 
{ 
	position = {1100, 600};
	radius = {100, 100};
	startposition = {30, 550};
	startradius = {50, 50};
}

void Goal::Update() {}

void Goal::Draw() 
{ 
	Novice::DrawBox((int)position.x-player_->GetScroll(), (int)position.y, (int)radius.x, (int)radius.y, 0.0f, GREEN, kFillModeSolid); 
	Novice::DrawBox((int)startposition.x-player_->GetScroll(), (int)startposition.y, (int)startradius.x, (int)startradius.y, 0.0f, BLACK, kFillModeSolid);
}
