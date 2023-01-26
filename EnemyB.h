#pragma once
#include "Object.h"
class EnemyB : public Object
{
public:
	EnemyB(Vec2 pos, float rad, Vec2 speed);

private:
	void Limit();

public:
	void Update() override;
	void Draw()override;
};
