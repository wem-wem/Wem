#include "appEnv.hpp"

// アプリのウインドウサイズ
enum Window {
	WIDTH = 1500,
	HEIGHT = 950
};


// 
// メインプログラム
// 
int main() {
	while (1){
		// アプリウインドウの準備
		AppEnv app_env(Window::WIDTH, Window::HEIGHT);

		// サウンド読み込み
		Media OP("res/BGM_SE/OP.wav");

		// 再生
		OP.play();
		// ループ設定
		OP.looping(true);
		// 音量(0.0?1.0)
		OP.gain(0.5);

		Texture setumei("res/setumei.png");

		Texture Title1("res/Title1.png");
		Texture Title2("res/Title2.png");
		Texture Title3("res/Title3.png");
		Texture Title4("res/Title4.png");
		Texture Title5("res/Title5.png");
		Texture Title6("res/Title6.png");
		Texture Title7("res/Title7.png");

		Texture Start0("res/Start0.png");
		Texture Start1("res/Start1.png");
		Texture Start2("res/Start2.png");
		Texture Start3("res/Start3.png");
		Texture Start4("res/Start4.png");
		Texture Start5("res/Start5.png");
		Texture Start6("res/Start6.png");
		Texture Start7("res/Start7.png");
		Texture Start8("res/Start8.png");
		Texture Start9("res/Start9.png");

		Texture Door("res/door2.png");
		Texture Door1("res/door3.png");
		Texture Door2("res/door4.png");

		Texture Door1_1("res/door1_1.png");
		Texture Door1_3("res/door1_3.png");
		Texture Door1_4("res/door1_4.png");

		Texture Key("res/key.png");

		float start_angle = 0;
		float title_angle = 0;

		// メインループ
		while (1) {
			// ウィンドウが閉じられたらアプリを終了
			if (!app_env.isOpen()) return 0;

			// 描画準備
			app_env.setupDraw();

			app_env.bgColor(Color(0, 0, 0));	// 背景色

			// タイトル表示

			title_angle += 0.06;

			float title_change = (std::sin(title_angle));

			if (title_change >= -1.0 && title_change <= -0.83){
				drawTextureBox(-500, 0,
					1000, 300,
					0, 0,
					1024, 512,
					Title1, Color(1, 1, 1));
			}
			if (title_change >= -0.83 && title_change <= -0.5){
				drawTextureBox(-500, 0,
					1000, 300,
					0, 0,
					1024, 512,
					Title2, Color(1, 1, 1));
			}
			if (title_change >= -0.5 && title_change <= -0.2){
				drawTextureBox(-500, 0,
					1000, 300,
					0, 0,
					1024, 512,
					Title3, Color(1, 1, 1));
			}
			if (title_change >= -0.2 && title_change <= 0.2){
				drawTextureBox(-500, 0,
					1000, 300,
					0, 0,
					1024, 512,
					Title4, Color(1, 1, 1));
			}
			if (title_change >= 0.2 && title_change <= 0.5){
				drawTextureBox(-500, 0,
					1000, 300,
					0, 0,
					1024, 512,
					Title5, Color(1, 1, 1));
			}
			if (title_change >= 0.5 && title_change <= 0.83){
				drawTextureBox(-500, 0,
					1000, 300,
					0, 0,
					1024, 512,
					Title5, Color(1, 1, 1));
			}
			if (title_change >= 0.83 && title_change <= 1.0){
				drawTextureBox(-500, 0,
					1000, 300,
					0, 0,
					1024, 512,
					Title5, Color(1, 1, 1));
			}

			// 「PUSH START」表示
			start_angle += 0.05;
			float start_change = (std::sin(start_angle));

			if (start_change >= -1.0 && start_change <= -0.9){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start0, Color(1, 1, 1));
			}
			if (start_change >= -0.9 && start_change <= -0.7){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start1, Color(1, 1, 1));
			}
			if (start_change >= -0.7 && start_change <= -0.5){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start2, Color(1, 1, 1));
			}
			if (start_change >= -0.5 && start_change <= -0.3){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start3, Color(1, 1, 1));
			}
			if (start_change >= -0.3 && start_change <= -0.1){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start4, Color(1, 1, 1));
			}
			if (start_change >= -0.1 && start_change <= 0.1){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start5, Color(1, 1, 1));
			}
			if (start_change >= 0.1 && start_change <= 0.3){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start6, Color(1, 1, 1));
			}
			if (start_change >= 0.3 && start_change <= 0.5){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start7, Color(1, 1, 1));
			}
			if (start_change >= 0.5 && start_change <= 0.7){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start8, Color(1, 1, 1));
			}
			if (start_change >= 0.7 && start_change <= 0.9){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start8, Color(1, 1, 1));
			}
			if (start_change >= 0.9 && start_change <= 1.0){
				drawTextureBox(-310, -200,
					600, 250,
					0, 0,
					1024, 512,
					Start9, Color(1, 1, 1));
			}

			if (app_env.isPushKey(' ')) break;

			// 画面を更新
			app_env.update();
		}

		/*************************************************/
		/*					説明画面                      */
		/*************************************************/
		while (1){
			if (!app_env.isOpen()) return 0;
			app_env.setupDraw();

			drawTextureBox(-500, -300, 1000, 600,
				0, 0, 512, 512,
				setumei, Color(1, 1, 1));
			if (app_env.isPushKey(GLFW_KEY_ENTER))
			{// 停止
				OP.stop();
			}
			if (app_env.isPushKey(GLFW_KEY_ENTER)){
				break;
			}
			app_env.update();
		}

		/*************************************************/
		/*　　　　　　　　　　　ステージ１                    */
		/*************************************************/

		/*上から光を当てた時の立ち絵*/
		// 左向
		Texture char1_1("res/char1_1.png");
		Texture char2_1("res/char2_1.png");
		Texture char3_1("res/char3_1.png");
		// 右向
		Texture char1_2("res/char1_2.png");
		Texture char2_2("res/char2_2.png");
		Texture char3_2("res/char3_2.png");

		/*下から光を当てた時の立ち絵*/
		// 左向
		Texture char1_5("res/char1_5.png");
		Texture char2_5("res/char2_5.png");
		Texture char3_5("res/char3_5.png");
		// 右向
		Texture char1_6("res/char1_6.png");
		Texture char2_6("res/char2_6.png");
		Texture char3_6("res/char3_6.png");

		/*左から光を当てた時の立ち絵*/
		// 上向
		Texture char1_4("res/char1_4.png");
		Texture char2_4("res/char2_4.png");
		Texture char3_4("res/char3_4.png");
		// 下向
		Texture char1_8("res/char1_8.png");
		Texture char2_8("res/char2_8.png");
		Texture char3_8("res/char3_8.png");

		/*右から光を当てた時の立ち絵*/
		// 上向
		Texture char1_3("res/char1_3.png");
		Texture char2_3("res/char2_3.png");
		Texture char3_3("res/char3_3.png");
		// 下向
		Texture char1_7("res/char1_7.png");
		Texture char2_7("res/char2_7.png");
		Texture char3_7("res/char3_7.png");

		// 点灯ライト
		Texture light1_1("res/light1_1.png");
		Texture light1_2("res/light1_2.png");
		Texture light1_3("res/light1_3.png");
		Texture light1_4("res/light1_4.png");

		// 不点灯ライト
		Texture light2_1("res/light2_1.png");
		Texture light2_2("res/light2_2.png");
		Texture light2_3("res/light2_3.png");
		Texture light2_4("res/light2_4.png");

		// 点灯矢印
		Texture vec1_1("res/vec1_1.png");
		Texture vec1_2("res/vec1_2.png");
		Texture vec1_3("res/vec1_3.png");
		Texture vec1_4("res/vec1_4.png");

		// 不点灯矢印
		Texture vec2_1("res/vec2_1.png");
		Texture vec2_2("res/vec2_2.png");
		Texture vec2_3("res/vec2_3.png");
		Texture vec2_4("res/vec2_4.png");

		// クリア後選択画像
		Texture clear1("res/clear1.png");
		Texture clear2("res/clear2.png");
		Texture clear3("res/clear3.png");

		// 初期位置(ｘ軸)
		float pos_x = 200;

		// 初期位置(y軸)
		float pos_y = -300;

		float x = 0;
		float y = 0;
		int gravity_mode = 1;
		int game_mode = 0;
		int clear_mode = 0;
		float char_angle = 0;
		float door_angle = 0;
		float clear_angle = 0;

		// サウンドの読み込み
		Media playing("res/BGM_SE/playing.wav");
		Media clear("res/BGM_SE/clear.wav");
		Media Switch("res/BGM_SE/Switch.wav");
		Media fall("res/BGM_SE/fall.wav");
		Media walk("res/BGM_SE/walk.wav");
		walk.pitch(0.6);
		// 再生
		playing.play();
		clear.play();
		// ループ設定
		playing.looping(true);
		clear.looping(true);
		// 音量(0.0?1.0)
		playing.gain(0.35);
		clear.gain(0.0);

		/*************************************************/

		while (1){

			if (!app_env.isOpen()) return 0;
			app_env.setupDraw();

			// 背景黒色
			app_env.bgColor(Color(0, 0, 0));

			// マップ内背景白色
			drawFillBox(-500, -300, 1000, 600, Color(1, 1, 1));

			// 矢印の枠線
			drawBox(30, -380, 60, 60, 7, Color(0.5, 0.5, 0.5));
			drawBox(30, 330, 60, 60, 7, Color(0.5, 0.5, 0.5));
			drawBox(-580, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));
			drawBox(525, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));

			// ドア絵切り替え速度
			door_angle += 0.1;
			float door_change = (std::sin(door_angle));

			// 出口(ドア)
			if (game_mode != 1){
				drawTextureBox(273, 174,
					126, 126,
					0, 0, 126, 126,
					Door, Color(1, 1, 1));
			}
			else{
				if (door_change >= -1.0 && door_change <= 0){
					drawTextureBox(273, 174,
						126, 126,
						0, 0,
						126, 126,
						Door1, Color(1, 1, 1));
				}
				if (door_change >= 0 && door_change <= 1.0){
					drawTextureBox(273, 174,
						126, 126,
						0, 0,
						126, 126,
						Door2, Color(1, 1, 1));
				}
			}

			// キャラクター立ち絵切り替え速度
			char_angle += 0.05;
			float char_change = (std::sin(char_angle));

			/*************************************************/

			// 枠を抜けない為の制御
			if (x >= 698){ x = 698; }
			if (x <= -246){ x = -246; }

			if (y < 0){ y = 0; }
			if (y >= 545){ y = 545; }

			/*************************************************/
			// 上から光を当てた場合…
			if (app_env.isPushKey(GLFW_KEY_UP)){
				Switch.play();
				Switch.gain(0.5);
				if (gravity_mode == 1) {
					if (gravity_mode == 2){
						if (gravity_mode == 3){
							gravity_mode = 0;
						}
					}
				}
				else {
					gravity_mode = 1;
				}
			}
			/*************************************************/

			// 下から光を当てた場合…
			if (app_env.isPushKey(GLFW_KEY_DOWN)){
				Switch.play();
				Switch.gain(0.5);
				if (gravity_mode == 0){
					if (gravity_mode == 2){
						if (gravity_mode == 3){
							gravity_mode = 1;
						}
					}
				}
				else{
					gravity_mode = 0;
				}
			}

			/*************************************************/

			// 左から光を当てた場合…
			if (app_env.isPushKey(GLFW_KEY_LEFT)){
				Switch.play();
				Switch.gain(0.5);
				if (gravity_mode == -1){
					if (gravity_mode == 2){
						gravity_mode = 3;
					}
				}
				else{
					gravity_mode = 2;
				}
			}

			/*************************************************/

			// 右から光を当てた場合…
			if (app_env.isPushKey(GLFW_KEY_RIGHT)){
				Switch.play();
				Switch.gain(0.5);
				if (gravity_mode == -1){
					if (gravity_mode == 3){
						gravity_mode = 2;
					}
				}
				else{
					gravity_mode = 3;
				}
			}

			/*************************************************/

			// 各モードの設定
			/*************************************************/
			/*				下から光を当てた場合				*/
			/*************************************************/

			if (gravity_mode == 0){
				y += 3.5;

				// ライト表示
				drawTextureBox(-38, -420,
					100, 100,
					0, 0, 32, 32,
					light1_1, Color(1, 1, 1));

				drawTextureBox(-100, 330,
					100, 100,
					0, 0, 32, 32,
					light2_2, Color(1, 1, 1));

				drawTextureBox(-620, -70,
					100, 100,
					0, 0, 32, 32,
					light2_3, Color(1, 1, 1));

				drawTextureBox(525, -10,
					100, 100,
					0, 0, 32, 32,
					light2_4, Color(1, 1, 1));

				// 矢印
				drawTextureBox(30, -380,
					60, 60,
					0, 0, 64, 64,
					vec1_2, Color(1, 1, 1));

				drawTextureBox(30, 330,
					60, 60,
					0, 0, 64, 64,
					vec2_1, Color(1, 1, 1));

				drawTextureBox(-580, 70,
					60, 60,
					0, 0, 64, 64,
					vec2_4, Color(1, 1, 1));

				drawTextureBox(525, 70,
					60, 60,
					0, 0, 64, 64,
					vec2_3, Color(1, 1, 1));

				// 左に移動
				if (app_env.isPressKey('A')){
					x += 1.5;

					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_5, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_5, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_5, Color(1, 1, 1));
					}
				}

				// 右に移動
				else if (app_env.isPressKey('D')){
					x -= 1.5;
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_6, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_6, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_6, Color(1, 1, 1));
					}
				}
				// どのキーも押していない状態(通常立ち絵)
				else {
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_5, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_5, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_5, Color(1, 1, 1));
					}
				}
				if (app_env.isPushKey('A')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('A')){
					walk.looping(false);
				}
				if (app_env.isPushKey('D')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('D')){
					walk.looping(false);
				}

			}

			/*************************************************/
			/*		　　	　上から光を当てた場合		　			*/
			/************************************************/

			if (gravity_mode == 1){
				y -= 3.5;

				drawTextureBox(-38, -420,
					100, 100,
					0, 0, 32, 32,
					light2_1, Color(1, 1, 1));

				drawTextureBox(-100, 330,
					100, 100,
					0, 0, 32, 32,
					light1_2, Color(1, 1, 1));

				drawTextureBox(-620, -70,
					100, 100,
					0, 0, 32, 32,
					light2_3, Color(1, 1, 1));

				drawTextureBox(525, -10,
					100, 100,
					0, 0, 32, 32,
					light2_4, Color(1, 1, 1));

				// 矢印
				drawTextureBox(30, -380,
					60, 60,
					0, 0, 64, 64,
					vec2_2, Color(1, 1, 1));

				drawTextureBox(30, 330,
					60, 60,
					0, 0, 64, 64,
					vec1_1, Color(1, 1, 1));

				drawTextureBox(-580, 70,
					60, 60,
					0, 0, 64, 64,
					vec2_4, Color(1, 1, 1));

				drawTextureBox(525, 70,
					60, 60,
					0, 0, 64, 64,
					vec2_3, Color(1, 1, 1));

				// 左に移動
				if (app_env.isPressKey('A')){
					x += 1.5;

					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_1, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_1, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_1, Color(1, 1, 1));
					}
				}

				// 右に移動
				else if (app_env.isPressKey('D')){
					x -= 1.5;
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_2, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_2, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_2, Color(1, 1, 1));
					}
				}
				// どのキーも押していない状態(通常立ち絵)
				else {
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_1, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_1, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_1, Color(1, 1, 1));
					}
				}
				if (app_env.isPushKey('A')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('A')){
					walk.looping(false);
				}
				if (app_env.isPushKey('D')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('D')){
					walk.looping(false);
				}
			}

			/*************************************************/
			/*			左から光を当てた場合					*/
			/************************************************/

			if (gravity_mode == 2){
				x -= 3.5;

				drawTextureBox(-38, -420,
					100, 100,
					0, 0, 32, 32,
					light2_1, Color(1, 1, 1));

				drawTextureBox(-100, 330,
					100, 100,
					0, 0, 32, 32,
					light2_2, Color(1, 1, 1));

				drawTextureBox(-620, -70,
					100, 100,
					0, 0, 32, 32,
					light1_3, Color(1, 1, 1));

				drawTextureBox(525, -10,
					100, 100,
					0, 0, 32, 32,
					light2_4, Color(1, 1, 1));

				// 矢印
				drawTextureBox(30, -380,
					60, 60,
					0, 0, 64, 64,
					vec2_2, Color(1, 1, 1));

				drawTextureBox(30, 330,
					60, 60,
					0, 0, 64, 64,
					vec2_1, Color(1, 1, 1));

				drawTextureBox(-580, 70,
					60, 60,
					0, 0, 64, 64,
					vec1_4, Color(1, 1, 1));

				drawTextureBox(525, 70,
					60, 60,
					0, 0, 64, 64,
					vec2_3, Color(1, 1, 1));

				// 上に移動
				if (app_env.isPressKey('W')){
					y += 1.5;

					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_4, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_4, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_4, Color(1, 1, 1));
					}
				}

				// 下に移動
				else if (app_env.isPressKey('S')){
					y -= 1.5;
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_8, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_8, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_8, Color(1, 1, 1));
					}
				}
				// どのキーも押していない状態(通常立ち絵)
				else {
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_8, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_8, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_8, Color(1, 1, 1));
					}
				}
				if (app_env.isPushKey('W')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('W')){
					walk.looping(false);
				}
				if (app_env.isPushKey('S')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('S')){
					walk.looping(false);
				}
			}

			/*************************************************/
			/*               右から光を当てた場合              */
			/************************************************/
			if (gravity_mode == 3){
				x += 3.5;
				// 上に移動

				drawTextureBox(-38, -420,
					100, 100,
					0, 0, 32, 32,
					light2_1, Color(1, 1, 1));

				drawTextureBox(-100, 330,
					100, 100,
					0, 0, 32, 32,
					light2_2, Color(1, 1, 1));

				drawTextureBox(-620, -70,
					100, 100,
					0, 0, 32, 32,
					light2_3, Color(1, 1, 1));

				drawTextureBox(525, -10,
					100, 100,
					0, 0, 32, 32,
					light1_4, Color(1, 1, 1));

				// 矢印
				drawTextureBox(30, -380,
					60, 60,
					0, 0, 64, 64,
					vec2_2, Color(1, 1, 1));

				drawTextureBox(30, 330,
					60, 60,
					0, 0, 64, 64,
					vec2_1, Color(1, 1, 1));

				drawTextureBox(-580, 70,
					60, 60,
					0, 0, 64, 64,
					vec2_4, Color(1, 1, 1));

				drawTextureBox(525, 70,
					60, 60,
					0, 0, 64, 64,
					vec1_3, Color(1, 1, 1));

				if (app_env.isPressKey('W')){
					y += 1.5;

					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_3, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_3, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_3, Color(1, 1, 1));
					}
				}

				// 下に移動
				else if (app_env.isPressKey('S')){
					y -= 1.5;
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_7, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_7, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_7, Color(1, 1, 1));
					}
				}
				// どのキーも押していない状態(通常立ち絵)
				else {
					if (char_change >= -1.0 && char_change <= -0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char1_7, Color(1, 1, 1));
					}
					if (char_change >= -0.5 && char_change <= 0.5){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char2_7, Color(1, 1, 1));
					}
					if (char_change >= 0.5 && char_change <= 1){
						drawTextureBox(pos_x - x, pos_y + y,
							50, 50,
							0, 0,
							256, 256,
							char3_7, Color(1, 1, 1));
					}
				}
				if (app_env.isPushKey('W')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('W')){
					walk.looping(false);
				}
				if (app_env.isPushKey('S')){
					walk.play();
					walk.looping(true);
					walk.gain(0.2);
				}
				if (app_env.isPullKey('S')){
					walk.looping(false);
				}
			}
			/*************************************************/

			// 枠線(ステージ全景)
			drawBox(-502, -302, 1002, 602, 3, Color(0, 0, 0));

			// 横線
			// ①
			drawFillBox(-350, -200, 850, 10, Color(0, 0, 0));
			if (x <= 598 && x >= -250){
				if (y >= 50 && y <= 55){
					y = 50;
				}
			}
			if (x <= 598 && x >= -250){
				if (y <= 110 && y >= 105){
					y = 110;
				}
			}
			if (y >= 56 && y <= 104){
				if (x <= 598){
					x = 598;
				}
			}

			// ②
			drawFillBox(-500, -50, 750, 10, Color(0, 0, 0));
			if (x <= 800 && x >= -50){
				if (y >= 200 && y <= 205){
					y = 200;
				}
			}
			if (x <= 800 && x >= -50){
				if (y >= 255 && y <= 260){
					y = 260;
				}
			}
			if (y >= 206 && y <= 254){
				if (x >= -50){
					x = -50;
				}
			}

			// ③
			drawFillBox(-400, 100, 800, 10, Color(0, 0, 0));
			if (x <= 650 && x >= -200){
				if (y >= 350 && y <= 355){
					y = 350;
				}
			}
			if (x <= 650 && x >= -200){
				if (y >= 405 && y <= 410){
					y = 410;
				}
			}
			if (y >= 356 && y <= 404){
				if (x <= 650 && x >= -190){
					x = 650;
				}
			}

			// 縦線
			drawFillBox(400, 100, 10, 200, Color(0, 0, 0));
			if (x >= -210 && x <= -205){
				if (y >= 350 && y <= 600){
					x = -210;
				}
			}
			if (x <= -150 && x >= -155){
				if (y >= 390 && y <= 600){
					x = -150;
				}
			}

			/*****************************************/
			/*　　ゲームの進行に合わせた画像表示の切り替え　*/
			/****************************************/

			if (x <= -225 && x >= -275){
				if (y >= 515 && y <= 565){
					game_mode = 1;
				}
			}

			// 鍵
			if (game_mode != 1){
				fall.play();
				fall.gain(0.3);

				drawTextureBox(445, 245,
					50, 50,
					0, 0, 64, 64,
					Key, Color(1, 1, 1));
			}

			if (game_mode == 1){
				if (x <= -70 && x >= -190){
					if (y >= 474 && y <= 600){

						x = -90;
						y = 500;
						playing.stop();
						walk.gain(0.0);
						clear.gain(0.5);

						// クリア後画像の移動速度
						clear_angle += 3;
						if (clear_angle >= 300){
							clear_angle = 300;
						}

						if (clear_mode == 0){
							drawTextureBox(-290, 300 - clear_angle,
								500, 500,
								0, 0, 256, 256,
								clear1, Color(1, 1, 1));
						}

						if (app_env.isPushKey(GLFW_KEY_UP)){
							clear_mode = 1;
						}
						if (clear_mode == 1){

							drawTextureBox(-290, 300 - clear_angle,
								500, 500,
								0, 0, 256, 256,
								clear2, Color(1, 1, 1));

							if (app_env.isPushKey(GLFW_KEY_ENTER)){
								break;
							}
						}

						if (app_env.isPushKey(GLFW_KEY_DOWN)){
							clear_mode = 2;
						}
						if (clear_mode == 2){

							drawTextureBox(-290, 300 - clear_angle,
								500, 500,
								0, 0, 256, 256,
								clear3, Color(1, 1, 1));

							if (app_env.isPushKey(GLFW_KEY_ENTER)){
								break;
							}
						}
					}
				}
			}
			app_env.update();
		}
		/***********/
		/*ステージ２*/
		/**********/

		// 初期位置(ｘ軸)
		float pos_x1 = -500;

		// 初期位置(y軸)
		float pos_y1 = -300;

		float x1 = 0;
		float y1 = 0;
		int gravity_mode1 = 1;
		int game_mode1 = 0;
		int clear_mode1 = 0;
		float char_angle1 = 0;
		float door_angle1 = 0;
		float clear_angle1 = 0;

		// 再生
		playing.play();
		clear.play();
		// ループ設定
		playing.looping(true);
		clear.looping(true);
		// 音量(0.0?1.0)
		playing.gain(0.35);
		clear.gain(0.0);

		/*************************************************/
		if (clear_mode == 1){
			while (1){

				if (!app_env.isOpen()) return 0;
				app_env.setupDraw();

				// 背景黒色
				app_env.bgColor(Color(0, 0, 0));

				// マップ内背景白色
				drawFillBox(-500, -300, 1000, 600, Color(1, 1, 1));

				// 矢印の枠線
				drawBox(30, -380, 60, 60, 7, Color(0.5, 0.5, 0.5));
				drawBox(30, 330, 60, 60, 7, Color(0.5, 0.5, 0.5));
				drawBox(-580, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));
				drawBox(525, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));

				// ドア絵切り替え速度
				door_angle1 += 0.1;
				float door_change1 = (std::sin(door_angle1));

				// 出口(ドア)
				if (game_mode1 != 1){
					drawTextureBox(270, -190,
						126, 126,
						0, 0, 126, 126,
						Door1_1, Color(1, 1, 1));
				}
				else{
					if (door_change1 >= -1.0 && door_change1 <= 0){
						drawTextureBox(270, -190,
							126, 126,
							0, 0,
							126, 126,
							Door1_3, Color(1, 1, 1));
					}
					if (door_change1 >= 0 && door_change1 <= 1.0){
						drawTextureBox(270, -190,
							126, 126,
							0, 0,
							126, 126,
							Door1_4, Color(1, 1, 1));
					}
				}

				// キャラクター立ち絵切り替え速度
				char_angle1 += 0.05;
				float char_change1 = (std::sin(char_angle1));

				/*************************************************/

				// 枠を抜けない為の制御
				if (x1 <= -950){ x1 = -950; }
				if (x1 >= 0){ x1 = 0; }

				if (y1 < 0){ y1 = 0; }
				if (y1 >= 545){ y1 = 545; }

				/*************************************************/
				// 上から光を当てた場合…
				if (app_env.isPushKey(GLFW_KEY_UP)){
					Switch.play();
					Switch.gain(0.5);
					if (gravity_mode1 == 1) {
						if (gravity_mode1 == 2){
							if (gravity_mode1 == 3){
								gravity_mode1 = 0;
							}
						}
					}
					else {
						gravity_mode1 = 1;
					}
				}
				/*************************************************/

				// 下から光を当てた場合…
				if (app_env.isPushKey(GLFW_KEY_DOWN)){
					Switch.play();
					Switch.gain(0.5);
					if (gravity_mode1 == 0){
						if (gravity_mode1 == 2){
							if (gravity_mode1 == 3){
								gravity_mode1 = 1;
							}
						}
					}
					else{
						gravity_mode1 = 0;
					}
				}

				/*************************************************/

				// 左から光を当てた場合…
				if (app_env.isPushKey(GLFW_KEY_LEFT)){
					Switch.play();
					Switch.gain(0.5);
					if (gravity_mode1 == -1){
						if (gravity_mode1 == 2){
							gravity_mode1 = 3;
						}
					}
					else{
						gravity_mode1 = 2;
					}
				}

				/*************************************************/

				// 右から光を当てた場合…
				if (app_env.isPushKey(GLFW_KEY_RIGHT)){
					Switch.play();
					Switch.gain(0.5);
					if (gravity_mode1 == -1){
						if (gravity_mode1 == 3){
							gravity_mode1 = 2;
						}
					}
					else{
						gravity_mode1 = 3;
					}
				}

				/*************************************************/

				// 各モードの設定
				/*************************************************/
				/*				下から光を当てた場合				*/
				/*************************************************/

				if (gravity_mode1 == 0){
					y1 += 3.5;

					// ライト表示
					drawTextureBox(-38, -420,
						100, 100,
						0, 0, 32, 32,
						light1_1, Color(1, 1, 1));

					drawTextureBox(-100, 330,
						100, 100,
						0, 0, 32, 32,
						light2_2, Color(1, 1, 1));

					drawTextureBox(-620, -70,
						100, 100,
						0, 0, 32, 32,
						light2_3, Color(1, 1, 1));

					drawTextureBox(525, -10,
						100, 100,
						0, 0, 32, 32,
						light2_4, Color(1, 1, 1));

					// 矢印
					drawTextureBox(30, -380,
						60, 60,
						0, 0, 64, 64,
						vec1_2, Color(1, 1, 1));

					drawTextureBox(30, 330,
						60, 60,
						0, 0, 64, 64,
						vec2_1, Color(1, 1, 1));

					drawTextureBox(-580, 70,
						60, 60,
						0, 0, 64, 64,
						vec2_4, Color(1, 1, 1));

					drawTextureBox(525, 70,
						60, 60,
						0, 0, 64, 64,
						vec2_3, Color(1, 1, 1));

					// 左に移動
					if (app_env.isPressKey('A')){
						x1 += 1.5;

						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_5, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_5, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_5, Color(1, 1, 1));
						}
					}

					// 右に移動
					else if (app_env.isPressKey('D')){
						x1 -= 1.5;
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_6, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_6, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_6, Color(1, 1, 1));
						}
					}
					// どのキーも押していない状態(通常立ち絵)
					else {
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_5, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_5, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_5, Color(1, 1, 1));
						}
					}
					if (app_env.isPushKey('A')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('A')){
						walk.looping(false);
					}
					if (app_env.isPushKey('D')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('D')){
						walk.looping(false);
					}

				}

				/*************************************************/
				/*		　　	　上から光を当てた場合		　			*/
				/************************************************/

				if (gravity_mode1 == 1){
					y1 -= 3.5;

					drawTextureBox(-38, -420,
						100, 100,
						0, 0, 32, 32,
						light2_1, Color(1, 1, 1));

					drawTextureBox(-100, 330,
						100, 100,
						0, 0, 32, 32,
						light1_2, Color(1, 1, 1));

					drawTextureBox(-620, -70,
						100, 100,
						0, 0, 32, 32,
						light2_3, Color(1, 1, 1));

					drawTextureBox(525, -10,
						100, 100,
						0, 0, 32, 32,
						light2_4, Color(1, 1, 1));

					// 矢印
					drawTextureBox(30, -380,
						60, 60,
						0, 0, 64, 64,
						vec2_2, Color(1, 1, 1));

					drawTextureBox(30, 330,
						60, 60,
						0, 0, 64, 64,
						vec1_1, Color(1, 1, 1));

					drawTextureBox(-580, 70,
						60, 60,
						0, 0, 64, 64,
						vec2_4, Color(1, 1, 1));

					drawTextureBox(525, 70,
						60, 60,
						0, 0, 64, 64,
						vec2_3, Color(1, 1, 1));

					// 左に移動
					if (app_env.isPressKey('A')){
						x1 += 1.5;

						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_1, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_1, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_1, Color(1, 1, 1));
						}
					}

					// 右に移動
					else if (app_env.isPressKey('D')){
						x1 -= 1.5;
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_2, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_2, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_2, Color(1, 1, 1));
						}
					}
					// どのキーも押していない状態(通常立ち絵)
					else {
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_1, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_1, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_1, Color(1, 1, 1));
						}
					}
					if (app_env.isPushKey('A')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('A')){
						walk.looping(false);
					}
					if (app_env.isPushKey('D')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('D')){
						walk.looping(false);
					}
				}

				/*************************************************/
				/*			左から光を当てた場合					*/
				/************************************************/

				if (gravity_mode1 == 2){
					x1 -= 3.5;

					drawTextureBox(-38, -420,
						100, 100,
						0, 0, 32, 32,
						light2_1, Color(1, 1, 1));

					drawTextureBox(-100, 330,
						100, 100,
						0, 0, 32, 32,
						light2_2, Color(1, 1, 1));

					drawTextureBox(-620, -70,
						100, 100,
						0, 0, 32, 32,
						light1_3, Color(1, 1, 1));

					drawTextureBox(525, -10,
						100, 100,
						0, 0, 32, 32,
						light2_4, Color(1, 1, 1));

					// 矢印
					drawTextureBox(30, -380,
						60, 60,
						0, 0, 64, 64,
						vec2_2, Color(1, 1, 1));

					drawTextureBox(30, 330,
						60, 60,
						0, 0, 64, 64,
						vec2_1, Color(1, 1, 1));

					drawTextureBox(-580, 70,
						60, 60,
						0, 0, 64, 64,
						vec1_4, Color(1, 1, 1));

					drawTextureBox(525, 70,
						60, 60,
						0, 0, 64, 64,
						vec2_3, Color(1, 1, 1));

					// 上に移動
					if (app_env.isPressKey('W')){
						y1 += 1.5;

						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_4, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_4, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_4, Color(1, 1, 1));
						}
					}

					// 下に移動
					else if (app_env.isPressKey('S')){
						y1 -= 1.5;
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_8, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_8, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_8, Color(1, 1, 1));
						}
					}
					// どのキーも押していない状態(通常立ち絵)
					else {
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_8, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_8, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_8, Color(1, 1, 1));
						}
					}
					if (app_env.isPushKey('W')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('W')){
						walk.looping(false);
					}
					if (app_env.isPushKey('S')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('S')){
						walk.looping(false);
					}
				}

				/*************************************************/
				/*               右から光を当てた場合              */
				/************************************************/
				if (gravity_mode1 == 3){
					x1 += 3.5;
					// 上に移動

					drawTextureBox(-38, -420,
						100, 100,
						0, 0, 32, 32,
						light2_1, Color(1, 1, 1));

					drawTextureBox(-100, 330,
						100, 100,
						0, 0, 32, 32,
						light2_2, Color(1, 1, 1));

					drawTextureBox(-620, -70,
						100, 100,
						0, 0, 32, 32,
						light2_3, Color(1, 1, 1));

					drawTextureBox(525, -10,
						100, 100,
						0, 0, 32, 32,
						light1_4, Color(1, 1, 1));

					// 矢印
					drawTextureBox(30, -380,
						60, 60,
						0, 0, 64, 64,
						vec2_2, Color(1, 1, 1));

					drawTextureBox(30, 330,
						60, 60,
						0, 0, 64, 64,
						vec2_1, Color(1, 1, 1));

					drawTextureBox(-580, 70,
						60, 60,
						0, 0, 64, 64,
						vec2_4, Color(1, 1, 1));

					drawTextureBox(525, 70,
						60, 60,
						0, 0, 64, 64,
						vec1_3, Color(1, 1, 1));

					if (app_env.isPressKey('W')){
						y1 += 1.5;

						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_3, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_3, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_3, Color(1, 1, 1));
						}
					}

					// 下に移動
					else if (app_env.isPressKey('S')){
						y1 -= 1.5;
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_7, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_7, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_7, Color(1, 1, 1));
						}
					}
					// どのキーも押していない状態(通常立ち絵)
					else {
						if (char_change1 >= -1.0 && char_change1 <= -0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char1_7, Color(1, 1, 1));
						}
						if (char_change1 >= -0.5 && char_change1 <= 0.5){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char2_7, Color(1, 1, 1));
						}
						if (char_change1 >= 0.5 && char_change1 <= 1){
							drawTextureBox(pos_x1 - x1, pos_y1 + y1,
								50, 50,
								0, 0,
								256, 256,
								char3_7, Color(1, 1, 1));
						}
					}
					if (app_env.isPushKey('W')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('W')){
						walk.looping(false);
					}
					if (app_env.isPushKey('S')){
						walk.play();
						walk.looping(true);
						walk.gain(0.2);
					}
					if (app_env.isPullKey('S')){
						walk.looping(false);
					}
				}
				/*************************************************/

				// 枠線(ステージ全景)
				drawBox(-502, -302, 1004, 604, 3, Color(0, 0, 0));

				// 横線
				// ①
				drawFillBox(-500, -200, 100, 10, Color(0, 0, 0));
				if (x1 <= 5 && x1 >= -100){
					if (y1 >= 50 && y1 <= 55){
						y1 = 50;
					}
				}
				if (x1 <= 5 && x1 >= -100){
					if (y1 <= 110 && y1 >= 105){
						y1 = 110;
					}
				}
				if (y1 >= 51 && y1 <= 100){
					if (x1 >= -101 && x1 <= -96){
						x1 = -101;
					}
				}

				// ②
				drawFillBox(-320, -200, 740, 10, Color(0, 0, 0));
				if (x1 <= -139 && x1 >= -910){
					if (y1 >= 50 && y1 <= 55){
						y1 = 50;
					}
				}
				if (x1 <= -139 && x1 >= -910){
					if (y1 <= 110 && y1 >= 105){
						y1 = 110;
					}
				}
				if (y1 >= 49 && y1 <= 111){
					if (x1 >= -920 && x1 <= -915){
						x1 = -920;
					}
				}

				// ③
				drawFillBox(-320, 190, 740, 10, Color(0, 0, 0));
				if (x1 <= -139 && x1 >= -910){
					if (y1 >= 440 && y1 <= 445){
						y1 = 440;
					}
				}
				if (x1 <= -139 && x1 >= -910){
					if (y1 <= 500 && y1 >= 495){
						y1 = 500;
					}
				}
				if (y1 >= 439 && y1 <= 501){
					if (x1 >= -920 && x1 <= -915){
						x1 = -920;
					}
				}

				// ④
				drawFillBox(-30, 40, 450, 10, Color(0, 0, 0));
				if (x1 <= -421 && x1 >= -910){
					if (y1 <= 350 && y1 >= 345){
						y1 = 350;
					}
				}
				if (x1 <= -421 && x1 >= -910){
					if (y1 <= 295 && y1 >= 290){
						y1 = 290;
					}
				}
				if (y1 >= 291 && y1 <= 349){
					if (x1 >= -425 && x1 <= -420){
						x1 = -420;
					}
				}

				// ⑤
				drawFillBox(-120, -50, 540, 10, Color(0, 0, 0));
				if (x1 <= -341 && x1 >= -920){
					if (y1 <= 260 && y1 >= 255){
						y1 = 260;
					}
				}
				if (x1 <= -331 && x1 >= -910){
					if (y1 <= 205 && y1 >= 200){
						y1 = 200;
					}
				}
				if (y1 >= 201 && y1 <= 259){
					if (x1 >= -335 && x1 <= -330){
						x1 = -330;
					}
				}

				// 縦線
				// ①
				drawFillBox(-400, -200, 10, 400, Color(0, 0, 0));
				if (x1 <= -50 && x1 >= -55){
					if (y1 >= 90 && y1 <= 500){
						x1 = -49;
					}
				}
				if (x1 <= -105 && x1 >= -110){
					if (y1 >= 51 && y1 <= 500){
						x1 = -111;
					}
				}
				if (y1 >= 495 && y1 <= 500){
					if (x1 <= -49 && x1 >= -100){
						y1 = 500;
					}
				}

				// ②
				drawFillBox(-320, -200, 10, 400, Color(0, 0, 0));
				if (x1 <= -130 && x1 >= -135){
					if (y1 >= 51 && y1 <= 500){
						x1 = -128;
					}
				}
				if (x1 <= -185 && x1 >= -190){
					if (y1 >= 95 && y1 <= 498){
						x1 = -190;
					}
				}
				if (y1 >= 495 && y1 <= 500){
					if (x1 <= -130 && x1 >= -190){
						y1 = 500;
					}
				}

				// ③
				drawFillBox(410, -200, 10, 160, Color(0, 0, 0));
				if (x1 <= -860 && x1 >= -865){
					if (y1 >= 110 && y1 <= 250){
						x1 = -860;
					}
				}
				if (x1 <= -915 && x1 >= -920){
					if (y1 >= 110 && y1 <= 260){
						x1 = -920;
					}
				}
				if (y1 >= 257 && y1 <= 262){
					if (x1 <= -861 && x1 >= -919){
						y1 = 262;
					}
				}

				// ④
				drawFillBox(410, 40, 10, 160, Color(0, 0, 0));
				if (x1 <= -860 && x1 >= -865){
					if (y1 >= 298 && y1 <= 490){
						x1 = -860;
					}
				}
				if (x1 <= -915 && x1 >= -920){
					if (y1 >= 290 && y1 <= 500){
						x1 = -920;
					}
				}
				if (y1 >= 288 && y1 <= 292){
					if (x1 <= -861 && x1 >= -919){
						y1 = 288;
					}
				}

				// ⑤
				drawFillBox(-120, -50, 10, 100, Color(0, 0, 0));
				if (x1 <= -330 && x1 >= -335){
					if (y1 >= 201 && y1 <= 349){
						x1 = -330;
					}
				}
				if (x1 <= -385 && x1 >= -390){
					if (y1 >= 201 && y1 <= 349){
						x1 = -390;
					}
				}
				if (y1 >= 345 && y1 <= 350){
					if (x1 <= -331 && x1 >= -389){
						y1 = 350;
					}
				}

				/*****************************************/
				/*　　ゲームの進行に合わせた画像表示の切り替え　*/
				/****************************************/

				if (x1 >= -60 && x1 <= -10){
					if (y1 >= 110 && y1 <= 160){
						game_mode1 = 1;
					}
				}

				// 鍵
				if (game_mode1 != 1){
					fall.play();
					fall.gain(0.3);

					drawTextureBox(-490, -190,
						50, 50,
						0, 0, 64, 64,
						Key, Color(1, 1, 1));
				}

				if (game_mode1 == 1){
					if (x1 <= -775 && x1 >= -890){
						if (y1 >= 110 && y1 <= 220){

							x1 = -803;
							y1 = 165;
							playing.stop();
							walk.gain(0.0);
							clear.gain(0.5);

							// クリア後画像の移動速度
							clear_angle1 += 3;
							if (clear_angle1 >= 300){
								clear_angle1 = 300;
							}

							if (clear_mode1 == 0){
								drawTextureBox(-290, 300 - clear_angle1,
									500, 500,
									0, 0, 256, 256,
									clear1, Color(1, 1, 1));
							}

							if (app_env.isPushKey(GLFW_KEY_UP)){
								clear_mode1 = 1;
							}
							if (clear_mode1 == 1){

								drawTextureBox(-290, 300 - clear_angle1,
									500, 500,
									0, 0, 256, 256,
									clear2, Color(1, 1, 1));

								if (app_env.isPushKey(GLFW_KEY_ENTER)){
									break;
								}
							}

							if (app_env.isPushKey(GLFW_KEY_DOWN)){
								clear_mode1 = 2;
							}
							if (clear_mode1 == 2){

								drawTextureBox(-290, 300 - clear_angle1,
									500, 500,
									0, 0, 256, 256,
									clear3, Color(1, 1, 1));

								if (app_env.isPushKey(GLFW_KEY_ENTER)){
									break;
								}
							}
						}
					}
				}
				app_env.update();
			}

			// 入力のフラッシュ
			app_env.flushInput();
		}
	}
}
