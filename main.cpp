#include <Novice.h>
#include "EnemyA.h"
#include "EnemyB.h"

const char* kWindowTitle = "PG2_11-3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	int kWindowWidth = 1280, kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//	インスタンス
	EnemyA* enemyA = new EnemyA({ 100.0f,100.0f }, 10.0f, { 30.0f,30.0f });
	EnemyB* enemyB = new EnemyB({ 700.0f,360.0f }, 50.0f, { 15.0f,0.0f });

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
