#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	static bool isAlive;
	Enemy(Vec2 pos, Vec2 speed, float rad);
private:
	class Player* player;
	void Limit();
public:
	void Update()override;
	void Draw()override;

};

