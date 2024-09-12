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
	bool IsMouseOverBox(int boxX, int boxY, int boxWidth, int boxHeight);

	Vector2 SetMouse() { return Vector2((float)mouseX, (float)mouseY); }

	
};
