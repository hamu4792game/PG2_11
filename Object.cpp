#include "Object.h"
#include "math.h"

bool Collision(Object::Vec2 pos1, float radius1, Object::Vec2 pos2, float radius2) {
	float a = pos1.x - pos2.x;
	float b = pos1.y - pos2.y;
	float distance = sqrtf(a * a + b * b);
	if (distance <= radius1 + radius2)
	{
		return true;
	}
	return false;
}

void Object::Update() {

}

void Object::Draw() {

}