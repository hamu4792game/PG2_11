#include "Player.h"

Player::Player() {
	pos_ = { 500.0f,600.0f };
	radius_ = 50.0f;
	speed_ = { 10.0f,10.0f };
}

Object::Vec2 Player::getPos() {
	return pos_;
}

float Player::getRad() {
	return radius_;
}