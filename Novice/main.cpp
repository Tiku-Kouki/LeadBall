#include <Novice.h>
#include"Tile.h"
#include"Player.h"
#include"Goal.h"
#include"Back.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);


	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	// プレイヤー
	Player* player = new Player;
	player->Initilize();

	Tile* tile = new Tile();
	tile->Initialize();
	tile->SetPlayer(player);

	Goal* goal = new Goal();
	goal->Initialize();
	goal->SetPlayer(player);
	player->SetGoal(goal);
	player->SetTile(tile);
	goal->SetTile(tile);

	Back* back = new Back();
	back->Initialize();
	back->SetPlayer(player);

	int Scene = 0;
	//タイル更新制限
	bool StageFlag = false;

	typedef struct Box {
		Vector2 Position;
		Vector2 Size;
		int Image;
	} Box;

	Box Item[4] = {
	    {100, 100, 100, 100},
        {300, 100, 100, 100},
        {100, 300, 100, 100},
        {300, 300, 100, 100}
    };

	std::unique_ptr<mouse> Mouse;

	int Sound[2] = {Novice::LoadAudio("./Resorce/Sound/BGM.mp3"), Novice::LoadAudio("./Resorce/Sound/SE.wav")};
	Novice::PlayAudio(Sound[0], true, 1.0f);
	Mouse = std::make_unique<mouse>();
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
		Mouse->GetMouse();
		switch (Scene) {
			case 0:
				//タイトル

			    if (Mouse->leftGetMouse()) {
				    Scene = 1;
				    Novice::PlayAudio(Sound[1], false, 1.0f);
				}

				Novice::DrawBox(100, 100, 100, 100, 0.0f, RED, kFillModeSolid);
				break;
		    case 1:
			    //画面選択
			    goal->Initialize();
			    tile->Initialize();
			    player->Initilize();
			    back->Initialize();
			    StageFlag = false;

				//ゲーム説明// ステージ１
			    // ステージ2// ステージ3の順番
			    for (int i = 0; i < 4; i++) {
				    Novice::DrawBox((int)Item[i].Position.x, (int)Item[i].Position.y, (int)Item[i].Size.x, (int)Item[i].Size.y, 0.0f, BLUE, kFillModeSolid);
			    
					if (Mouse->leftGetMouse() && Mouse->IsMouseOverBox((int)Item[i].Position.x, (int)Item[i].Position.y, (int)Item[i].Size.x, (int)Item[i].Size.y)) {
					    Scene = i + 3;
					    Novice::PlayAudio(Sound[1], false, 1.0f);
				    }
				} 
			    break;
		    case 2:
			    // クリア
			    if (Mouse->leftGetMouse()) {
				    Scene = 0;
				    Novice::PlayAudio(Sound[1], false, 1.0f);
			    }
			    Novice::DrawBox(100, 100, 100, 100, 0.0f, BLACK, kFillModeSolid);
			    break;
		    case 3:
			    // ゲーム説明
			    if (Mouse->leftGetMouse()) {
				    Scene = 1;
				    Novice::PlayAudio(Sound[1], false, 1.0f);
			    }
			    Novice::DrawBox(100, 100, 100, 100, 0.0f, WHITE, kFillModeSolid);
			    break;
		    case 4:
			    // ステージ１

				// Update
				//背景
			    back->Update();
			    //  //ゴール
			    goal->Update();
			    // プレイヤー
			    player->Update();
			    if (player->GetGoalSceneFlag()) {
				    Scene = 2;
				}
			    // タイル
			    if (!StageFlag) {
				    tile->Stage1();
			    }
			    StageFlag = true;
			    tile->Update();

			    // Draw
			    // 背景
			    back->Draw();
			    //  ゴール
			    goal->Draw();
			    // タイル
			    tile->Draw();
			    // プレイヤー
			    player->Draw();
			    break;
		    case 5:
			    // ステージ2
				
				//Update 
				// 背景
			    back->Update();
				// //ゴール
			    goal->Update();
			    // プレイヤー
			    player->Update();
			    if (player->GetGoalSceneFlag()) {
				    Scene = 2;
			    }
			    // タイル
			    if (!StageFlag) {
				    tile->Stage2();
			    }
			    StageFlag = true;
			    tile->Update();

				//Draw
			    // 背景
			    back->Draw();
			    // ゴール
			    goal->Draw();
				//タイル
			    tile->Draw();
			    // プレイヤー
			    player->Draw();
			    break;
		    case 6:
			    // ステージ3
				
				// Update
			    // 背景
			    back->Update();
			    //  //ゴール
			    goal->Update();
			    // プレイヤー
			    player->Update();
			    if (player->GetGoalSceneFlag()) {
				    Scene = 2;
			    }
			    // タイル
			    if (!StageFlag) {
				    tile->Stage3();
			    }
			    StageFlag = true;
			    tile->Update();

			    // Draw
			    // 背景
			    back->Draw();
			    //  ゴール
			    goal->Draw();
			    // タイル
			    tile->Draw();
			    // プレイヤー
			    player->Draw();
			    break;
		}
		
		
		
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		
		

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
