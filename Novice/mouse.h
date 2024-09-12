#pragma once
#include"Vector2.h"
 #include <Novice.h>
class mouse {
private:
	int mouseX, mouseY;

public:
	
	void GetMouse(/*int MouseX, int MouseY*/);
	bool leftGetMouse();
	bool RightGetMouse();
	Vector2 SetMouse() { return Vector2((float)mouseX, (float)mouseY); }

	int SoundSE[2] = {Novice::LoadAudio("./NoviceResources/Sound/Left.mp3"), Novice::LoadAudio("./NoviceResources/Sound/Right.mp3")};

};
