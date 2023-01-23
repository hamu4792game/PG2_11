#pragma once
class Enemy
{
public:	// メンバ関数


	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X座標</param>
	/// <param name="posY">Y座標</param>
	/// <param name="speedX">移動速度X</param>
	/// <param name="speedY">移動速度Y</param>
	Enemy(int posX, int posY, int speedX, int speedY);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


private:	// メンバ変数
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;

public:		//	ゲッター
	int getPosX();
	int getPosY();
	int getSpeedX();
	int getSpeedY();
	int getRadius();
	//	セッター
	void setSpeedX(int speed);
	void setSpeedY(int speed);
};
