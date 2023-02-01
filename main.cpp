#include <Novice.h>
#include "Key/Key.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

const char* kWindowTitle = "PG2_13-1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	int kWindowWidth = 1280, kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	//	インスタンス
	Player* player = new Player();
	Enemy* enemy1 = new Enemy({ 50.0f,100.0f }, { 10.0f,10.0f }, 50.0f);
	Enemy* enemy2 = new Enemy({ 500.0f,400.0f }, { 10.0f,10.0f }, 50.0f);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		Key::Input();

		///
		/// ↓更新処理ここから
		///

		if (Key::IsTrigger(DIK_R))
		{
			enemy1->isAlive = true;
		}
		
		player->Update();
		enemy1->Update();
		enemy2->Update();

		//	衝突判定
		for (int i = 0; i < 10; i++)
		{
			if (Collision(player->getBulletPos(i), player->getBulletRad(i), enemy1->getPos(), enemy1->getRad()))
			{
				enemy1->isAlive = false;
			}
			if (Collision(player->getBulletPos(i), player->getBulletRad(i), enemy2->getPos(), enemy2->getRad()))
			{
				enemy2->isAlive = false;
			}
		}
		
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		enemy1->Draw();
		enemy2->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Key::IsTrigger(DIK_ESCAPE)) {
			break;
		}
	}

	delete player;
	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
