#pragma once
#include "Object.h"
class Player : public Object
{
public:
	Player();
	~Player();
private:
	const int kMaxBullet;
	class Bullet* bullet;
	void Move();
public:
	//
	Vec2 getPos();
	float getRad();
	//
	Vec2 getBulletPos(int index);
	float getBulletRad(int index);
	//
	void Update() override;
	void Draw() override;
};

