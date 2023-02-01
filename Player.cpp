#include "Player.h"
#include "Bullet.h"
#include "Key/Key.h"


Player::Player() :kMaxBullet(10) {
	pos_ = { 500.0f,600.0f };
	radius_ = 50.0f;
	speed_ = { 10.0f,10.0f };

	bullet = new Bullet[kMaxBullet];
}

Player::~Player() {
	delete[] bullet;
}

void Player::Move() {
	//	à⁄ìÆ
	if (Key::IsPressed(DIK_W) || Key::IsPressed(DIK_UP))
	{
		pos_.y -= speed_.y;
	}
	if (Key::IsPressed(DIK_S) || Key::IsPressed(DIK_DOWN))
	{
		pos_.y += speed_.y;
	}
	if (Key::IsPressed(DIK_A) || Key::IsPressed(DIK_LEFT))
	{
		pos_.x -= speed_.x;
	}
	if (Key::IsPressed(DIK_D) || Key::IsPressed(DIK_RIGHT))
	{
		pos_.x += speed_.x;
	}

	//	êßå¿
	if (pos_.x - radius_ <= 0)
	{
		pos_.x = 0 + radius_;
	}
	else if (pos_.x + radius_ >= 1280)
	{
		pos_.x = 1280 - radius_;
	}
	if (pos_.y - radius_ <= 0.0f)
	{
		pos_.y = 0.0f + radius_;
	}
	else if (pos_.y + radius_ >= 720.0f)
	{
		pos_.y = 720.0f - radius_;
	}
}

void Player::Update() {
	Move();
	//	ÉtÉâÉOÇóßÇƒÇÈ
	if (Key::IsTrigger(DIK_SPACE))
	{
		for (int i = 0; i < kMaxBullet; i++)
		{
			if (!bullet[i].getBullet())
			{
				bullet[i].setBullet(true);
				bullet[i].setPos(pos_);
				break;
			}
		}
	}

	for (int i = 0; i < kMaxBullet; i++)
	{
		bullet[i].Update();
	}
}

void Player::Draw() {

	for (int i = 0; i < kMaxBullet; i++)
	{
		bullet[i].Draw();
	}
	Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y),
		static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xffffffff, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "%f %f", pos_.x, pos_.y);
}

Object::Vec2 Player::getPos() {
	return pos_;
}

float Player::getRad() {
	return radius_;
}

Object::Vec2 Player::getBulletPos(int index) {
	return bullet[index].getPos();
}
float Player::getBulletRad(int index) {
	return bullet[index].getRad();
}