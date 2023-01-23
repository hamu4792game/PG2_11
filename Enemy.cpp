#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 8;
}

void Enemy::Update() {
	posX_ += speedX_;
	posY_ += speedY_;

	if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
		speedX_ *= -1;
	}
	if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
		speedY_ *= -1;
	}
}

void Enemy::Draw() {
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
}

//	ゲッター
int Enemy::getPosX() {
	return this->posX_;
}
int Enemy::getPosY() {
	return this->posY_;
}
int Enemy::getSpeedX() {
	return this->speedX_;
}
int Enemy::getSpeedY() {
	return this->speedY_;
}
int Enemy::getRadius() {
	return this->radius_;
}

//	セッター
void Enemy::setSpeedX(int speed) {
	this->speedX_ = speed;
}
void Enemy::setSpeedY(int speed) {
	this->speedY_ = speed;
}