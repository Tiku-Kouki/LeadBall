#include "mouse.h"
void mouse::GetMouse(/*int MouseX, int MouseY*/) {


	Novice::GetMousePosition(&mouseX, &mouseY);

	/*mouseY *= -1;
	mouseY += 720;*/

	
	
	 
}

bool mouse::leftGetMouse() {

	bool num = Novice::IsTriggerMouse(0);
	if (num) {
		Novice::PlayAudio(SoundSE[0], false, 0.5f);
	}
	return num;
}

bool mouse::RightGetMouse() {
	bool num = Novice::IsTriggerMouse(1);
	if (num) {
		Novice::PlayAudio(SoundSE[1], false, 0.5f);
	}
	return num;
}
