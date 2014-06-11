#include "appEnv.hpp"

// �A�v���̃E�C���h�E�T�C�Y
enum Window {
	WIDTH = 1500,
	HEIGHT = 950
};


// 
// ���C���v���O����
// 
int main() {
	while (1){
		// �A�v���E�C���h�E�̏���
		AppEnv app_env(Window::WIDTH, Window::HEIGHT);

		// �T�E���h�ǂݍ���
		Media OP("res/BGM_SE/OP.wav");

		// �Đ�
		OP.play();
		// ���[�v�ݒ�
		OP.looping(true);
		// ����(0.0?1.0)
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

		// ���C�����[�v
		while (1) {
			// �E�B���h�E������ꂽ��A�v�����I��
			if (!app_env.isOpen()) return 0;

			// �`�揀��
			app_env.setupDraw();

			app_env.bgColor(Color(0, 0, 0));	// �w�i�F

			// �^�C�g���\��

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

			// �uPUSH START�v�\��
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

			// ��ʂ��X�V
			app_env.update();
		}

		/*************************************************/
		/*					�������                      */
		/*************************************************/
		while (1){
			if (!app_env.isOpen()) return 0;
			app_env.setupDraw();

			drawTextureBox(-500, -300, 1000, 600,
				0, 0, 512, 512,
				setumei, Color(1, 1, 1));
			if (app_env.isPushKey(GLFW_KEY_ENTER))
			{// ��~
				OP.stop();
			}
			if (app_env.isPushKey(GLFW_KEY_ENTER)){
				break;
			}
			app_env.update();
		}

		/*************************************************/
		/*�@�@�@�@�@�@�@�@�@�@�@�X�e�[�W�P                    */
		/*************************************************/

		/*�ォ����𓖂Ă����̗����G*/
		// ����
		Texture char1_1("res/char1_1.png");
		Texture char2_1("res/char2_1.png");
		Texture char3_1("res/char3_1.png");
		// �E��
		Texture char1_2("res/char1_2.png");
		Texture char2_2("res/char2_2.png");
		Texture char3_2("res/char3_2.png");

		/*��������𓖂Ă����̗����G*/
		// ����
		Texture char1_5("res/char1_5.png");
		Texture char2_5("res/char2_5.png");
		Texture char3_5("res/char3_5.png");
		// �E��
		Texture char1_6("res/char1_6.png");
		Texture char2_6("res/char2_6.png");
		Texture char3_6("res/char3_6.png");

		/*��������𓖂Ă����̗����G*/
		// ���
		Texture char1_4("res/char1_4.png");
		Texture char2_4("res/char2_4.png");
		Texture char3_4("res/char3_4.png");
		// ����
		Texture char1_8("res/char1_8.png");
		Texture char2_8("res/char2_8.png");
		Texture char3_8("res/char3_8.png");

		/*�E������𓖂Ă����̗����G*/
		// ���
		Texture char1_3("res/char1_3.png");
		Texture char2_3("res/char2_3.png");
		Texture char3_3("res/char3_3.png");
		// ����
		Texture char1_7("res/char1_7.png");
		Texture char2_7("res/char2_7.png");
		Texture char3_7("res/char3_7.png");

		// �_�����C�g
		Texture light1_1("res/light1_1.png");
		Texture light1_2("res/light1_2.png");
		Texture light1_3("res/light1_3.png");
		Texture light1_4("res/light1_4.png");

		// �s�_�����C�g
		Texture light2_1("res/light2_1.png");
		Texture light2_2("res/light2_2.png");
		Texture light2_3("res/light2_3.png");
		Texture light2_4("res/light2_4.png");

		// �_�����
		Texture vec1_1("res/vec1_1.png");
		Texture vec1_2("res/vec1_2.png");
		Texture vec1_3("res/vec1_3.png");
		Texture vec1_4("res/vec1_4.png");

		// �s�_�����
		Texture vec2_1("res/vec2_1.png");
		Texture vec2_2("res/vec2_2.png");
		Texture vec2_3("res/vec2_3.png");
		Texture vec2_4("res/vec2_4.png");

		// �N���A��I���摜
		Texture clear1("res/clear1.png");
		Texture clear2("res/clear2.png");
		Texture clear3("res/clear3.png");

		// �����ʒu(����)
		float pos_x = 200;

		// �����ʒu(y��)
		float pos_y = -300;

		float x = 0;
		float y = 0;
		int gravity_mode = 1;
		int game_mode = 0;
		int clear_mode = 0;
		float char_angle = 0;
		float door_angle = 0;
		float clear_angle = 0;

		// �T�E���h�̓ǂݍ���
		Media playing("res/BGM_SE/playing.wav");
		Media clear("res/BGM_SE/clear.wav");
		Media Switch("res/BGM_SE/Switch.wav");
		Media fall("res/BGM_SE/fall.wav");
		Media walk("res/BGM_SE/walk.wav");
		walk.pitch(0.6);
		// �Đ�
		playing.play();
		clear.play();
		// ���[�v�ݒ�
		playing.looping(true);
		clear.looping(true);
		// ����(0.0?1.0)
		playing.gain(0.35);
		clear.gain(0.0);

		/*************************************************/

		while (1){

			if (!app_env.isOpen()) return 0;
			app_env.setupDraw();

			// �w�i���F
			app_env.bgColor(Color(0, 0, 0));

			// �}�b�v���w�i���F
			drawFillBox(-500, -300, 1000, 600, Color(1, 1, 1));

			// ���̘g��
			drawBox(30, -380, 60, 60, 7, Color(0.5, 0.5, 0.5));
			drawBox(30, 330, 60, 60, 7, Color(0.5, 0.5, 0.5));
			drawBox(-580, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));
			drawBox(525, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));

			// �h�A�G�؂�ւ����x
			door_angle += 0.1;
			float door_change = (std::sin(door_angle));

			// �o��(�h�A)
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

			// �L�����N�^�[�����G�؂�ւ����x
			char_angle += 0.05;
			float char_change = (std::sin(char_angle));

			/*************************************************/

			// �g�𔲂��Ȃ��ׂ̐���
			if (x >= 698){ x = 698; }
			if (x <= -246){ x = -246; }

			if (y < 0){ y = 0; }
			if (y >= 545){ y = 545; }

			/*************************************************/
			// �ォ����𓖂Ă��ꍇ�c
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

			// ��������𓖂Ă��ꍇ�c
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

			// ��������𓖂Ă��ꍇ�c
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

			// �E������𓖂Ă��ꍇ�c
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

			// �e���[�h�̐ݒ�
			/*************************************************/
			/*				��������𓖂Ă��ꍇ				*/
			/*************************************************/

			if (gravity_mode == 0){
				y += 3.5;

				// ���C�g�\��
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

				// ���
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

				// ���Ɉړ�
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

				// �E�Ɉړ�
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
				// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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
			/*		�@�@	�@�ォ����𓖂Ă��ꍇ		�@			*/
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

				// ���
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

				// ���Ɉړ�
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

				// �E�Ɉړ�
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
				// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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
			/*			��������𓖂Ă��ꍇ					*/
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

				// ���
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

				// ��Ɉړ�
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

				// ���Ɉړ�
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
				// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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
			/*               �E������𓖂Ă��ꍇ              */
			/************************************************/
			if (gravity_mode == 3){
				x += 3.5;
				// ��Ɉړ�

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

				// ���
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

				// ���Ɉړ�
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
				// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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

			// �g��(�X�e�[�W�S�i)
			drawBox(-502, -302, 1002, 602, 3, Color(0, 0, 0));

			// ����
			// �@
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

			// �A
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

			// �B
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

			// �c��
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
			/*�@�@�Q�[���̐i�s�ɍ��킹���摜�\���̐؂�ւ��@*/
			/****************************************/

			if (x <= -225 && x >= -275){
				if (y >= 515 && y <= 565){
					game_mode = 1;
				}
			}

			// ��
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

						// �N���A��摜�̈ړ����x
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
		/*�X�e�[�W�Q*/
		/**********/

		// �����ʒu(����)
		float pos_x1 = -500;

		// �����ʒu(y��)
		float pos_y1 = -300;

		float x1 = 0;
		float y1 = 0;
		int gravity_mode1 = 1;
		int game_mode1 = 0;
		int clear_mode1 = 0;
		float char_angle1 = 0;
		float door_angle1 = 0;
		float clear_angle1 = 0;

		// �Đ�
		playing.play();
		clear.play();
		// ���[�v�ݒ�
		playing.looping(true);
		clear.looping(true);
		// ����(0.0?1.0)
		playing.gain(0.35);
		clear.gain(0.0);

		/*************************************************/
		if (clear_mode == 1){
			while (1){

				if (!app_env.isOpen()) return 0;
				app_env.setupDraw();

				// �w�i���F
				app_env.bgColor(Color(0, 0, 0));

				// �}�b�v���w�i���F
				drawFillBox(-500, -300, 1000, 600, Color(1, 1, 1));

				// ���̘g��
				drawBox(30, -380, 60, 60, 7, Color(0.5, 0.5, 0.5));
				drawBox(30, 330, 60, 60, 7, Color(0.5, 0.5, 0.5));
				drawBox(-580, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));
				drawBox(525, 70, 60, 60, 7, Color(0.5, 0.5, 0.5));

				// �h�A�G�؂�ւ����x
				door_angle1 += 0.1;
				float door_change1 = (std::sin(door_angle1));

				// �o��(�h�A)
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

				// �L�����N�^�[�����G�؂�ւ����x
				char_angle1 += 0.05;
				float char_change1 = (std::sin(char_angle1));

				/*************************************************/

				// �g�𔲂��Ȃ��ׂ̐���
				if (x1 <= -950){ x1 = -950; }
				if (x1 >= 0){ x1 = 0; }

				if (y1 < 0){ y1 = 0; }
				if (y1 >= 545){ y1 = 545; }

				/*************************************************/
				// �ォ����𓖂Ă��ꍇ�c
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

				// ��������𓖂Ă��ꍇ�c
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

				// ��������𓖂Ă��ꍇ�c
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

				// �E������𓖂Ă��ꍇ�c
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

				// �e���[�h�̐ݒ�
				/*************************************************/
				/*				��������𓖂Ă��ꍇ				*/
				/*************************************************/

				if (gravity_mode1 == 0){
					y1 += 3.5;

					// ���C�g�\��
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

					// ���
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

					// ���Ɉړ�
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

					// �E�Ɉړ�
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
					// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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
				/*		�@�@	�@�ォ����𓖂Ă��ꍇ		�@			*/
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

					// ���
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

					// ���Ɉړ�
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

					// �E�Ɉړ�
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
					// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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
				/*			��������𓖂Ă��ꍇ					*/
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

					// ���
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

					// ��Ɉړ�
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

					// ���Ɉړ�
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
					// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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
				/*               �E������𓖂Ă��ꍇ              */
				/************************************************/
				if (gravity_mode1 == 3){
					x1 += 3.5;
					// ��Ɉړ�

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

					// ���
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

					// ���Ɉړ�
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
					// �ǂ̃L�[�������Ă��Ȃ����(�ʏ헧���G)
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

				// �g��(�X�e�[�W�S�i)
				drawBox(-502, -302, 1004, 604, 3, Color(0, 0, 0));

				// ����
				// �@
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

				// �A
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

				// �B
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

				// �C
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

				// �D
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

				// �c��
				// �@
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

				// �A
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

				// �B
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

				// �C
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

				// �D
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
				/*�@�@�Q�[���̐i�s�ɍ��킹���摜�\���̐؂�ւ��@*/
				/****************************************/

				if (x1 >= -60 && x1 <= -10){
					if (y1 >= 110 && y1 <= 160){
						game_mode1 = 1;
					}
				}

				// ��
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

							// �N���A��摜�̈ړ����x
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

			// ���͂̃t���b�V��
			app_env.flushInput();
		}
	}
}
