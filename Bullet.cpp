#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet() {
	pos_ = { -100.0f,0.0f };
	radius_ = 10.0f;
	speed_ = { 10.0f,10.0f };
	isShot = false;
}

bool Bullet::getBullet() {
	return isShot;
}

Object::Vec2 Bullet::getPos() {
	return pos_;
}

float Bullet::getRad() {
	return radius_;
}

void Bullet::setBullet(bool flag) {
	this->isShot = flag;
}

void Bullet::setPos(Vec2 pos) {
	this->pos_ = pos;
}

void Bullet::Update() {
	if (isShot)
	{
		pos_.y -= speed_.y;
	}

	if (pos_.y - radius_ <= 0.0f)
	{
		pos_ = { -100.0f,0.0f };
		isShot = false;
	}
}

void Bullet::Draw() {

	if (isShot)
	{
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
			static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xff0000ff, kFillModeSolid);
	}
}