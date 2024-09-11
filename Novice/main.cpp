#include <Novice.h>
#include"Tile.h"
#include<Player.h>
#include"Goal.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//プレイヤー
	Player* player=new Player;
	player->Start();
	

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Tile* tile = new Tile();
	tile->Initialize();
	tile->SetPlayer(player);

	Goal* goal = new Goal();
	goal->Initialize();
	goal->SetPlayer(player);
	player->SetGoal(goal);

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
		
		//タイル
		tile->Update();
		//ゴール
		goal->Update();
		
		///
		
		// プレイヤー
		player->Update();
		
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		//タイル
		tile->Draw();

		
		// プレイヤー
		player->Draw();
		//ゴール
		goal->Draw();

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

	delete tile;
	delete goal;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
