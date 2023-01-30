#include "Object.h"
#include "math.h"

bool Object::Collision(Vec2 pos1, float rad1, Vec2 pos2, float rad2) {
	float a = pos1.x - pos2.x;
	float b = pos1.y - pos2.y;
	float distance = sqrtf(a * a + b * b);
	if (distance <= rad1 + rad2)
	{
		return true;
	}
	return false;
}

void Object::Update() {

}

void Object::Draw() {

}