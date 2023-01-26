#include "EnemyA.h"
#include <Novice.h>

EnemyA::EnemyA(Vec2 pos, float rad, Vec2 speed) {
	pos_ = pos;
	radius_ = rad;
	speed_ = speed;
}

void EnemyA::Limit() {
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

void EnemyA::Update() {
	pos_.x += speed_.x;
	pos_.y += speed_.y;
	Limit();
}

void EnemyA::Draw() {
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, 0xffff00ff, kFillModeSolid);
}