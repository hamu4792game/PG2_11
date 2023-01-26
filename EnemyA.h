#pragma once
#include "Object.h"
class EnemyA : public Object
{
public:
	EnemyA(Vec2 pos, float rad, Vec2 speed);

private:
	void Limit();

public:
	void Update() override;
	void Draw()override;
};
