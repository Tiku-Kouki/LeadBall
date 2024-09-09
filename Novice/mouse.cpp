#include "mouse.h"
 #include <Novice.h>
void mouse::GetMouse(/*int MouseX, int MouseY*/) {


	Novice::GetMousePosition(&mouseX, &mouseY);

	/*mouseY *= -1;
	mouseY += 720;*/

	
	
	 
}

bool mouse::leftGetMouse() {

	bool num = Novice::IsTriggerMouse(0);

	return num;
}

bool mouse::RightGetMouse() {
	bool num = Novice::IsTriggerMouse(1);

	return num;
}
