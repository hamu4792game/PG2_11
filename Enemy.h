#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	static bool isAlive;
	Enemy(Vec2 pos, Vec2 speed, float rad);

private:
	void Limit();

public:
	void Update();
	void Draw();
};

