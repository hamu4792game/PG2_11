#pragma once
class Object
{
public:
	struct Vec2
	{
		float x, y;
	};

protected:
	Vec2 pos_;
	Vec2 speed_;
	float radius_;

public:
	bool Collision(Vec2 pos1, float rad1, Vec2 pos2, float rad2);
	virtual void Update();
	virtual void Draw();

};

