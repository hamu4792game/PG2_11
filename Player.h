#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player();
private:

public:

	Vec2 getPos();
	float getRad();
	void Update() override;
	void Draw() override;
};

