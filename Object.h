#pragma once
class Object
{
public:
	struct Vec2
	{
		float x, y;
	};

public:
	Vec2 pos_;
	Vec2 speed_;
	float radius_;
};

