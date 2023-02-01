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
	virtual void Update();
	virtual void Draw();

};

bool Collision(Object::Vec2 pos1, float radius1, Object::Vec2 pos2, float radius2);
