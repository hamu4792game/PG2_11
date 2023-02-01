#include "Enemy.h"
#include <Novice.h>
#include "Player.h"

bool Enemy::isAlive = true;

Enemy::Enemy(Vec2 pos, Vec2 speed, float rad) {
	pos_ = pos;
	speed_ = speed;
	radius_ = rad;

	player = new Player;
}

Enemy::~Enemy() {
	delete player;
}

void Enemy::Limit() {
	if (pos_.x - radius_ <= 0.0f)
	{
		pos_.x = radius_;
		speed_.x *= -1;
	}
	else if (pos_.x + radius_ >= 1280.0f)
	{
		pos_.x = 1280.0f - radius_;
		speed_.x *= -1;
	}

	if (pos_.y - radius_ <= 0.0f)
	{
		pos_.y = radius_;
		speed_.y *= -1;
	}
	else if (pos_.y + radius_ >= 720.0f)
	{
		pos_.y = 720.0f - radius_;
		speed_.y *= -1;
	}
}

void Enemy::Update() {
	if (isAlive)
	{
		pos_.x += speed_.x;
		//	pos_.y += speed_.y;
		Limit();
	}
}

void Enemy::Draw() {
	if (isAlive)
	{
		Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, 0xff0000ff, kFillModeSolid);
	}
}

Object::Vec2 Enemy::getPos() {
	return pos_;
}

float Enemy::getRad() {
	return radius_;
}