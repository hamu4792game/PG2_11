#include <Novice.h>
#include "Player.h"
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

	//	インスタンス
	Player* player = new Player();
	Enemy* enemy1 = new Enemy({ 50.0f,100.0f }, { 10.0f,10.0f }, 50.0f);
	Enemy* enemy2 = new Enemy({ 500.0f,400.0f }, { 10.0f,10.0f }, 50.0f);

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

		
		enemy1->Update();
		enemy2->Update();
		if (keys[DIK_SPACE])
		{
			enemy1->isAlive = false;
		}else if (keys[DIK_R])
		{
			enemy1->isAlive = true;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		enemy1->Draw();
		enemy2->Draw();

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

	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
