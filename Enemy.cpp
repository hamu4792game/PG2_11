#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
	pos_ = { 100.0f,100.0f };
	speed_ = { 10.0f,10.0f };
	radius_ = 10.0f;
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
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	Limit();
}

void Enemy::Draw() {
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, 0xff0000ff, kFillModeSolid);
}