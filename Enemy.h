#pragma once
#include "Object.h"
class Enemy : public Object
{
public:
	Enemy();

private:
	void Limit();

public:
	void Update();
	void Draw();
};

