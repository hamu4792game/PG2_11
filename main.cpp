#include <Novice.h>
#include "Enemy.h"

const char* kWindowTitle = "PG2_11-";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	int kWindowWidth = 1280, kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Enemy* enemyA = new Enemy(100, 300, 4, 0);
	Enemy* enemyB = new Enemy(300, 300, -4, 0);


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		enemyA->Update();
		enemyB->Update();

		// エネミー同士の当たり判定処理
		float distX = enemyA->getPosX() - enemyB->getPosX();
		float distY = enemyA->getPosY() - enemyB->getPosY();
		float dist = (distX * distX) + (distY * distY);
		int radius = enemyA->getRadius() + enemyB->getRadius();
		if (dist <= radius * radius) {
			enemyA->setSpeedX(enemyA->getSpeedX() * -1);
			enemyA->setSpeedY(4);
			enemyB->setSpeedX(enemyB->getSpeedX() * -1);
			enemyB->setSpeedY(-3);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enemyA->Draw();
		enemyB->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete enemyA;
	delete enemyB;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}