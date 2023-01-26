#include "EnemyB.h"
#include <Novice.h>

EnemyB::EnemyB(Vec2 pos, float rad, Vec2 speed) {
	pos_ = pos;
	radius_ = rad;
	speed_ = speed;
}

void EnemyB::Limit() {
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
}

void EnemyB::Update() {
	pos_.x += speed_.x;
	Limit();
}

void EnemyB::Draw() {
	Novice::DrawEllipse(pos_.x, pos_.y, radius_, radius_, 0.0f, 0xff0000ff, kFillModeSolid);
}