#include "Goal.h"
#include"Player.h"
#include"Tile.h"
void Goal::Initialize() 
{ 
	position = {3000, 500};
	radius = {100, 100};
	startposition = {0, 500};
	startradius = {50, 50};
}

void Goal::Update() 
{
	if (tile_->IsStage())
	{
		position.x = 2700;
	}
	if (tile_->IsStage2())
	{
		position.x = 3540;
	}
	if (tile_->IsStage3()) {
		position.x = 3000;
	}
}

void Goal::Draw() 
{ 
	//Novice::DrawBox((int)position.x-player_->GetScroll(), (int)position.y, (int)radius.x, (int)radius.y, 0.0f, GREEN, kFillModeSolid); 
	//Novice::DrawBox((int)startposition.x-player_->GetScroll(), (int)startposition.y, (int)startradius.x, (int)startradius.y, 0.0f, BLACK, kFillModeSolid);

	Novice::DrawSprite((int)position.x - player_->GetScroll(), (int)position.y, Sprite, 1, 1, 0.0f, WHITE);
}
