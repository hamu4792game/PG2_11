#pragma once
#include "Object.h"

class Bullet :public Object
{
public:
	Bullet();

private:
	bool isShot;

public:
	//	
	bool getBullet();
	Vec2 getPos();
	float getRad();
	//
	void setBullet(bool flag);
	void setPos(Vec2 pos);

public:
	void Update() override;
	void Draw() override;

};