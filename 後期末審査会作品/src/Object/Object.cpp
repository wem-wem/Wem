#pragma once
#include "Object.h"
#include "../Collision.h"

// �R���X�g���N�^
Square::Square():
num("res/png/number.png"),
num_chihaya("res/png/number_chihaya.png"),
comma("res/png/comma.png"),
board("res/png/board.png"),
pause_board("res/png/pause_board.png"),
count_1("res/png/count_1.png"),
count_2("res/png/count_2.png"),
count_3("res/png/count_3.png"),
count_start("res/png/count_start.png"),
count_end("res/png/count_end.png"),
wallpaper("res/png/wallpaper.png"),
time_board("res/png/time_board.png"),
syukka_board("res/png/syukka_board.png"),
dodai1("res/png/dodai1.png"),
dodai2("res/png/dodai2.png"),
dodai3("res/png/dodai3.png"),
dodai4("res/png/dodai4.png"),
dodai5("res/png/dodai5.png"),
dodai6("res/png/dodai6.png"),
dodai7("res/png/dodai7.png"),
pause1("res/png/pause1.png"),
pause2("res/png/pause2.png"),
pause3("res/png/pause3.png"),
pause4("res/png/pause4.png"),

// �A�C�e���摜------------------------------------------------
season1("res/item/season1/season1.png"),
season2("res/item/season2/season2.png"),
season3("res/item/season3/season3.png"),
season4("res/item/season4/season4.png"),
season5("res/item/season5/season5.png"),
season6("res/item/season6/season6.png"),
season7("res/item/season7/season7.png"),
season8("res/item/season8/season8.png"),
season9("res/item/season9/season9.png"),
season10("res/item/season10/season10.png"),
hazure("res/item/hazure.png"),

// �a�f�l�E�r�d------------------------------------------------
Game_Bgm("res/wav/game.wav"),
Attack("res/se/Attack.wav"),
Choice("res/se/Choice.wav"),
Enter("res/se/Enter.wav"),
Time_Up("res/se/Time_Up.wav"),
Countdown_Se("res/se/Countdown.wav"),
Shutter("res/se/Shutter.wav"),
Stop("res/se/Stop.wav")
{
  random.setSeed(u_int(time(nullptr))); // ��������̐����ŏ�����

  // ���n�Ӑ搶����̋�����
  //const char* texname[] = {"","","",};
  //for (int texIndex = 0; texIndex < TEX_NUM; texIndex++)
  //{
  //  texList[texIndex] = new Texture(texname[texIndex]);
  //}

  flip_MOVE = 12; // ��ɐ�����ԑ��x

  trigger = false;    // �I�u�W�F�N�g���P�������n�߂�悤�ɂ���ׂ̃X�C�b�`
  timer = 0;           // trigger��true�ɂ���ׂ̃^�C�}�[

  score = 0;          // �Q�[���Ƃ��Ă̓��_
  bad_score = 0;  // �Q�[���Ƃ��Ă̌��_
  obj_score = 0;   // �E���獶�֗��ꂽ�A�C�e���̍��v��
  recycle_point = 0; // �n�Y���A�C�e���ׂ̈̓_��

  money = 0;

  count_stop = false; // �ꎞ��~�p�̃X�C�b�`

  time_limit = 60 * 60; // �������Ԃ͊e�X�e�[�W�P��

  // �J�n�O�̃J�E���g�_�E��--------------------------------------------------
  CDtimer = 4 * 60;
  CDswitch = true;

  // �w�i�\���̐؂�ւ��p-----------------------------------------------------
  slide = 0;
  light_switch = false;
  shutter = 0;
  shutter_switch = false;
  shutter_UD = false;

  // �I�����̉�ʐ؂�ւ��p--------------------------------------------------
  end_timer = 3 * 60;
  end_switch = false;
}

// �w�i�\���p�̊֐�
void Square::Background(bool& main_quick){
  // BGM�Đ�
  if (!CDswitch){
    if (!Game_Bgm.isPlaying()){
      Game_Bgm.gain(0.2);
      Game_Bgm.play();
      Game_Bgm.looping(true);
    }
  }

  // �ǎ�
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1024, 512,
    wallpaper, Color(1, 1, 1));

  if (!count_stop && !CDswitch && !end_switch){
    if (main_quick) slide += 12;
    else slide += 6;
    if (slide >= 1002) slide = 0;
  }

  // ���T�C�N���W��
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1000, 500,
    board, Color(1, 1, 1));
  drawTextureBox(-WIDTH/2 + 40, 40, 85,85,
    0, 0, 256,256,
    hazure, Color(1,1,1));

  // �x���g�R���x�A
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1024, 512,
    dodai1, Color(1, 1, 1));

    drawTextureBox(-WIDTH/2 + 54, -214, 893, 73,
      0+slide, 0, 1024, 128,
      dodai2, Color(1, 1, 1));

    // ���T�C�N���_�N�g
    if (slide < 501){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
        0, 0, 1024, 512,
        dodai5, Color(1, 1, 1));
    }
    else{
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
        0, 0, 1024, 512,
        dodai6, Color(1, 1, 1));
    }

    // �d�C
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1024, 512,
      dodai4, Color(1, 1, 1));

    // �^�C���{�[�h
    drawTextureBox(350, 125, 150, 125,
      0, 0, 1024, 1024,
      time_board, Color(1, 1, 1));

    // �o�׃{�[�h
    drawTextureBox(-330, 95, 270, 155,
      0, 0, 1024, 1024,
      syukka_board, Color(1, 1, 1));

    // �|�[�Y�@�\�ē��{�[�h
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1024, 512,
      pause_board, Color(1, 1, 1));
}

// �X�e�[�W���̃I�u�W�F�N�g�Ǘ�
void Square::Variation(int& i, int& stage_no){
  // �����ʒu�ɖ߂��āA�����_���ōēo�ꂳ����
  random_count = random.fromZeroToLast(4);                                        // random_count�ɂO�`�R�̒l�������_���ŗ^����
  Object[i] = { WIDTH / 2, -92, 0, 0, 80, 80, false, false, 0, 0, 0, 1, 0 }; // �I�u�W�F�N�g�̏�����

  switch (stage_no){
    // �X�e�[�W�P----------------------------------------------------------------
  case 0:
    switch (random_count){
    case 0:
      Object[i].points = 200;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1000;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 2000;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 300;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 1500;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 3000;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 500;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 2500;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 5000;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�Q----------------------------------------------------------------
  case 1:
    switch (random_count){
    case 0:
      Object[i].points = 200;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1000;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 2000;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 300;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 1500;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 3000;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 500;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 2500;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 5000;
      }
      break;

    default: 
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�R----------------------------------------------------------------
  case 2:
    switch (random_count){
    case 0:
      Object[i].points = 200;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1000;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 2000;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 300;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 1500;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 3000;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 500;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 2500;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 5000;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�S----------------------------------------------------------------
  case 3:
    switch (random_count){
    case 0:
      Object[i].points = 100;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1000;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 3500;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 500;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 2000;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 4500;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 300;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 5000;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 8900;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�T----------------------------------------------------------------
  case 4:
    switch (random_count){
    case 0:
      Object[i].points = 100;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1000;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 3000;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 300;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 1500;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 3000;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 800;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 3000;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 7600;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�U----------------------------------------------------------------
  case 5:
    switch (random_count){
    case 0:
      Object[i].points = 100;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1200;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 3300;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 300;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 1800;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 4500;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 500;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 5000;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 10000;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�V----------------------------------------------------------------
  case 6:
    switch (random_count){
    case 0:
      Object[i].points = 500;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 2000;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 10000;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 600;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 3000;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 9000;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 1000;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 5000;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 25000;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�W----------------------------------------------------------------
  case 7:
    switch (random_count){
    case 0:
      Object[i].points = 300;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 2000;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 3500;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 700;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 2800;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 6800;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 1000;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 3500;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 13000;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W�X----------------------------------------------------------------
  case 8:
    switch (random_count){
    case 0:
      Object[i].points = 300;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1500;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 5000;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 1000;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 3500;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 8500;
      }
      break;

    case 2: 
      Object[i].cut_y = 512;
      Object[i].points = 500;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 2800;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 7600;
      }
      break;

    default:
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

    // �X�e�[�W10----------------------------------------------------------------
  case 9:
    switch (random_count){
    case 0:
      Object[i].points = 400;
      if (recycle_point >= 10 && recycle_point < 40){
        Object[i].cut_x = 256;
        Object[i].points = 1600;
      }
      else if (recycle_point >= 40){
        Object[i].cut_x = 512;
        Object[i].points = 4000;
      }
      break;

    case 1:
      Object[i].cut_y = 256;
      Object[i].points = 300;
      if (recycle_point >= 20 && recycle_point < 50){
        Object[i].cut_x = 256;
        Object[i].points = 1500;
      }
      else if (recycle_point >= 50){
        Object[i].cut_x = 512;
        Object[i].points = 4000;
      }
      break;

    case 2:
      Object[i].cut_y = 512;
      Object[i].points = 1500;
      if (recycle_point >= 30 && recycle_point < 60){
        Object[i].cut_x = 256;
        Object[i].points = 5000;
      }
      else if (recycle_point >= 60){
        Object[i].cut_x = 512;
        Object[i].points = 9800;
      }
      break;

    default: 
      Object[i].cut_y = 768;
      Object[i].points = 0;
      Object[i].recycle = 1;
      Object[i].bad_point = 1;
    }
    break;

  }
}

// �|�[�Y���̃I�u�W�F�N�g�\��
void Square::Variation2(int& stage_no, int b, int recycle_point){
  switch (stage_no){
    // �X�e�[�W�P----------------------------------------------------------------
  case 0:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season1, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�Q----------------------------------------------------------------
  case 1:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season2, Color(1, 1, 1));

    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�R----------------------------------------------------------------
  case 2:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season3, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�S----------------------------------------------------------------
  case 3:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season4, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�T----------------------------------------------------------------
  case 4:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season5, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�U----------------------------------------------------------------
  case 5:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season6, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�V----------------------------------------------------------------
  case 6:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season7, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�W----------------------------------------------------------------
  case 7:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season8, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W�X----------------------------------------------------------------
  case 8:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season9, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;

    // �X�e�[�W10----------------------------------------------------------------
  case 9:
    drawTextureBox(-WIDTH / 2 + 171 + (186 * b), -30, 120, 120,
      Pause_Obj[b].cut_x, Pause_Obj[b].cut_y, 256, 256,
      season10, Color(1, 1, 1));
    switch (b){
    case 0:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 0;
      if (recycle_point >= 10 && recycle_point < 40){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 40){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 1:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 256;
      if (recycle_point >= 20 && recycle_point < 50){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 50){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    case 2:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 512;
      if (recycle_point >= 30 && recycle_point < 60){
        Pause_Obj[b].cut_x = 256;
      }
      else if (recycle_point >= 60){
        Pause_Obj[b].cut_x = 512;
      }
      break;

    default:
      Pause_Obj[b].cut_x = 0;
      Pause_Obj[b].cut_y = 768;
    }
    break;
  }
}

// �I�u�W�F�N�g��\������ׂ̊֐�
void Square::Draw(int& stage_no){
  for (i = 0; i < x; i++){
    if (Object[i].active){                            // active��true�̎������\������

      switch (stage_no){
        // �X�e�[�W�P---------------------------------------------------------------------
      case 0:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season1, Color(1, 1, 1));
        break;

        // �X�e�[�W�Q------------------------------------------------------------------------
      case 1:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season2, Color(1, 1, 1));
        break;

        // �X�e�[�W�R------------------------------------------------------------------------
      case 2:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season3, Color(1, 1, 1));
        break;

        // �X�e�[�W�S------------------------------------------------------------------------
      case 3:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season4, Color(1, 1, 1));
        break;

        // �X�e�[�W�T------------------------------------------------------------------------
      case 4:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season5, Color(1, 1, 1));
        break;

        // �X�e�[�W�U------------------------------------------------------------------------
      case 5:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season6, Color(1, 1, 1));
        break;

        // �X�e�[�W�V------------------------------------------------------------------------
      case 6:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season7, Color(1, 1, 1));
        break;

        // �X�e�[�W�W------------------------------------------------------------------------
      case 7:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season8, Color(1, 1, 1));
        break;

        // �X�e�[�W�X------------------------------------------------------------------------
      case 8:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season9, Color(1, 1, 1));
        break;

        // �X�e�[�W10------------------------------------------------------------------------
      case 9:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season10, Color(1, 1, 1));
        break;
      }

    }
  }
}

// �I�u�W�F�N�g�𓮂������߂̃^�C�}�[
void Square::Countdown(bool& main_quick){
  if (timer <= 60){
    if (!count_stop && !CDswitch && !end_switch){
      if (main_quick) timer += 4;
      else timer += 2;
    }
  }

  else{                              // �^�C�}�[��60���z������
    trigger = true;             // �g���K�[��true�ɂ��āA
    timer = 0;                    // �^�C�}�[���O�ɖ߂�
  }
}

// �l�p�𓮂����ׂ̊֐�
void Square::Update(AppEnv& app_env, int& stage_no, bool& main_quick, bool& main_double_recycle){
  mouse_pos = app_env.mousePosition(); // �}�E�X�̃|�W�V�������L��

  if (!count_stop && !CDswitch && !end_switch){                 // �ꎞ��~���I�t�Ȃ瓮��
    for (i = 0; i < x; i++){

      // �֐�"Countdown"��trigger��true�ɂȂ�����
      if (trigger){
        if (!Object[i].active){        // �܂�active��true����Ȃ����m��
          Object[i].active = true;  // true�ɂ���B
          trigger = false;              // trigger���ēxfalse�ɖ߂��āACountdown�ōēxtrue�ɂ�����
        }
      }

      // �N���b�N����Ă��Ȃ���Ԃ̃I�u�W�F�N�g�����ɗ����
      if (!Object[i].isHit){
        if (Object[i].active){
          if (!count_stop){
            if (main_quick) Object[i].x -= 6;
            else Object[i].x -= 3;
          }
        }
      }

      // Cllision.h�ɂ��铖���蔻����g�p�B�l�p�̒����N���b�N�o����������
      if (Hit(app_env, mouse_pos.x(), mouse_pos.y(),
                Object[i].x, Object[i].y,
                Object[i].width, Object[i].height)){
        Attack.play();
        Object[i].mem_x = Object[i].x; // �N���b�N���ꂽ����X���W���L��
        Object[i].isHit = true;
      }

      // �N���b�N���������ʒ����㕔�ɔ��ł���
      if (Object[i].isHit){
        Object[i].y += flip_MOVE;                  // ���ł������x�͌���12
        Object[i].x -= Object[i].mem_x / 13.7; // �L�����Ă�����X���W��30�Ŋ���A��ʂ̐^�񒆂֔�Ԃ悤�ɂ���
        Object[i].width -= 1;                          // �����ɉ����Əc�����k�߂�
        Object[i].height -= 1;
      }

      // Y���W��-92����71�܂Ŕ�񂾂�c
      if (Object[i].y > Center_Y){
        Shutter.play();
        if (main_double_recycle){ 
          recycle_point += Object[i].recycle * 2; 
        }
        else {
          recycle_point += Object[i].recycle;
        }
        Object[i].isHit = false;
        shutter_switch = true;

        Variation(i, stage_no); // �X�e�[�W���ɈႤ�I�u�W�F�N�g��\��
      }

      // �I�u�W�F�N�g�����ɗ��ꂫ������(�N���b�N���ꂸ�ɗ��ꂽ��)�ʒu��߂�
      if (Object[i].x < -WIDTH / 2 - Object[i].width){
        score += Object[i].points;
        bad_score += Object[i].bad_point;
        obj_score += Object[i].obj_point;
        if (score <= 0)  { score = 0; }
        if (bad_score <= 0) { bad_score = 0; }
        if (obj_score <= 0) { obj_score = 0; }
        Object[i].active = false;
        Object[i].x = WIDTH / 2;

        Variation(i, stage_no); // �X�e�[�W���ɈႤ�I�u�W�F�N�g��\��
      }
    }
  
  }
}

// �o�׌�����ʂɕ\��
void Square::disp_Score(){  
  // �P����
  drawTextureBox(-180, 105, 50, 60,
    0 + 102 * (obj_score % 10), 0, 102, 128, num, Color(1, 1, 1));

  // �Q����
  drawTextureBox(-180 - 50, 105, 50, 60,
      0 + 102 * (obj_score / 10 % 10), 0, 102, 128, num, Color(1, 1, 1));

   // �R����
  drawTextureBox(-180 - 100, 105, 50, 60,
      0 + 102 * (obj_score / 100 % 10), 0, 102, 128, num, Color(1, 1, 1));
}

// �|�[�Y������������ʂɕ\��
void Square::disp_Money(long long int& money){
  // �P���� 870 , 396
  drawTextureBox(270, -225, 45, 75,
    0 + 100 * (money % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �Q����
  drawTextureBox(270 - 35, -225, 45, 75,
    0 + 100 * (money / 10 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �R����
  drawTextureBox(270 - 70, -225, 45, 75,
    0 + 100 * (money / 100 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �J���}
  drawTextureBox(270 - 80, -225, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // �S����
  drawTextureBox(270 - 115, -225, 45, 75,
    0 + 100 * (money / 1000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �T����
  drawTextureBox(270 - 150, -225, 45, 75,
    0 + 100 * (money / 10000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �U����
  drawTextureBox(270 - 185, -225, 45, 75,
    0 + 100 * (money / 100000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �J���}
  drawTextureBox(270 - 195, -225, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // �V����
  drawTextureBox(270 - 230, -225, 45, 75,
    0 + 100 * (money / 1000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �W����
  drawTextureBox(270 - 265, -225, 45, 75,
    0 + 100 * (money / 10000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �X����
  drawTextureBox(270 - 300, -225, 45, 75,
    0 + 100 * (money / 100000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �J���}
  drawTextureBox(270 - 310, -225, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // 10����
  drawTextureBox(270 - 345, -225, 45, 75,
    0 + 100 * (money / 1000000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));
}

// ���T�C�N���|�C���g�̕\��
void Square::recycle_Score(){
  // �P����
  drawTextureBox(10, 23, 15, 30,
    0 + 102 * (recycle_point % 10), 0, 102, 128, num, Color(0, 1, 1));

  // �Q����
  drawTextureBox(10 - 15, 23, 15, 30,
    0 + 102 * (recycle_point / 10 % 10), 0, 102, 128, num, Color(0, 1, 1));

  // �R����
  drawTextureBox(10 - 30, 23, 15, 30,
    0 + 102 * (recycle_point / 100 % 10), 0, 102, 128, num, Color(0, 1, 1));
}

// �x���g�R���x�A�̊W
void Square::Board(){
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1024, 512,
    dodai3, Color(1, 1, 1));

  // ���T�C�N���_�N�g�̊W�i�������j
  if (shutter_switch){
    drawTextureBox(-22, 120 - shutter / 2, 52, shutter / 2,
      0, 0, 128, 0 + shutter,
      dodai7, Color(1, 1, 1));

    // �V���b�^�[����n�߂�B
    if (shutter <= 120 && !shutter_UD){
      shutter += 24;
    }

    // 10�t���[���o������J�X�C�b�`���I���ɂ��āc�B
    if (shutter >= 120){
      shutter_UD = true;
    }

    // �V���b�^�[���J���n�߂�B
    if (shutter >= 0 && shutter_UD){
      shutter -= 12;
      if (shutter <= 0){
        shutter = 0;
        shutter_UD = false;
        shutter_switch = false;
      }
    }

  }
}

// �ꎞ��~�@�\
void Square::Pause(AppEnv& app_env,
                                int& game_mode, int& stage_no,
                                long long int& main_money){
 // �E�N���b�N�������̃X�C�b�`�̏�Ԃ𔻒�
  if (app_env.isPushButton(Mouse::RIGHT)){
    if (time_limit > 0){
      if (!CDswitch){
        Stop.play();
        count_stop = true;
      }
    }
  }

  if (count_stop){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1024, 512,
      pause1, Color(1, 1, 1));

    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1024, 512,
      pause4, Color(1, 1, 1));

    // �ꎞ��~���ɏ�������\��
    disp_Money(main_money);

    // �|�C���^���w�ĊJ�x�̘g���Ȃ�
    if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -400, -140, 398, 95)){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
        0, 0, 1024, 512,
        pause2, Color(1, 1, 1));
      if (app_env.isPushButton(Mouse::LEFT)){
        Stop.play();
        count_stop = false;
      }
    }

    // �|�C���^���w�^�C�g���x�̘g���Ȃ�
    if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), 2, -140, 398, 95)){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
        0, 0, 1024, 512,
        pause3, Color(1, 1, 1));
      if (app_env.isPushButton(Mouse::LEFT)){
        // �^�C�g���ɖ߂�����ϐ���������
        game_mode = TITLE;
        trigger = false;    // �I�u�W�F�N�g���P�������n�߂�悤�ɂ���ׂ̃X�C�b�`
        timer = 0;           // trigger��true�ɂ���ׂ̃^�C�}�[
        score = 0;          // �Q�[���Ƃ��Ă̓��_
        recycle_point = 0; // �n�Y���A�C�e���ׂ̈̓_��
        count_stop = false; // �ꎞ��~�p�̃X�C�b�`
        time_limit = 3600; // �������Ԃ͊e�X�e�[�W�P��
        slide = 0;
        light_switch = false;
        Game_Bgm.stop();
        end_timer = 3 * 60;
        end_switch = false;
        bad_score = 0;
        obj_score = 0;
        CDtimer = 4 * 60;
        CDswitch = true;

        for (int i = 0; i < x; i++){
          Variation(i, stage_no);
        }
      }
    }

    // �{�҂ɉe����^���Ȃ��摜�\�����[�v
    for (int b = 0; b < 4; b++){
      Variation2(stage_no, b, recycle_point);
    }

  }
}

// �������Ԃ̕\���E����
void Square::Limit(AppEnv& app_env, int& game_mode, int& stage_no,
                              int& main_score, int& main_bad_score,
                              int& main_total_score, int& main_obj_score,
                              bool& main_double_recycle, bool& main_quick){
  int time=time_limit/60;
  if (app_env.isPushKey('T')){
    time_limit = 60;
  }
  // �P����
  drawTextureBox(WIDTH/2 - 80, HEIGHT/2 - 122, 40, 50,
    0 + 102 * (time % 10), 0, 102, 128, num, Color(0, 0, 0));
  // �Q����
  drawTextureBox(WIDTH/2 - 130, HEIGHT/2 - 122, 40, 50,
    0 + 102 * (time / 10 % 10), 0, 102, 128, num, Color(0, 0, 0));

  // �P���o�߂���ƒ�~
  if (!count_stop && !CDswitch){
    if (time_limit > 0){
      time_limit--;
      Time_Up.gain(0);
      Time_Up.play();
    }
    else{
      Game_Bgm.stop();
      Time_Up.gain(0.6);
      end_switch = true;
      end_timer--;
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
          WIDTH, HEIGHT,
          0, 0, 1024, 512,
          count_end, Color(1, 1, 1));

        if (end_timer == 0){
          // ��x���C���֐����̕ϐ��֐��l���L��������
          main_score = score;
          main_bad_score = bad_score;
          main_total_score = score - (bad_score * 1000);
          main_obj_score = obj_score;

          // �S�Ă̕ϐ������Z�b�g
          count_stop = true;
          recycle_point = 0;
          time_limit = 60 * 60;
          CDtimer = 4 * 60;
          CDswitch = true;
          end_timer = 3 * 60;
          end_switch = false;
          score = 0;
          bad_score = 0;
          obj_score = 0;
          main_double_recycle = false;
          main_quick = false;
          game_mode = RESULT;
          if (stage_no < 9){
            stage_no += 1;
          }
          else{
            stage_no = 0;
          }
          Object[i].x = -WIDTH / 2 - Object[i].width;
          for (int i = 0; i < x; i++){
            Variation(i, stage_no);
          }
        }
    }
  }

}

// �Q�[���J�n�O�̃J�E���g�_�E��
void Square::Count_Down(){
  if (CDswitch){
    if (CDtimer == 239){
      Countdown_Se.gain(0.3);
      Countdown_Se.play();
    }
    CDtimer--;

    drawFillBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      color256(0, 0, 0, 128));

    if (CDtimer <= 4 * 60 && CDtimer > 3 * 60){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
        WIDTH, HEIGHT,
        0, 0, 1024, 512,
        count_3, Color(1, 1, 1));
    }

    if (CDtimer <= 3 * 60 && CDtimer > 2 * 60){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
        WIDTH, HEIGHT,
        0, 0, 1024, 512,
        count_2, Color(1, 1, 1));
    }

    if (CDtimer <= 2 * 60 && CDtimer > 1 * 60){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
        WIDTH, HEIGHT,
        0, 0, 1024, 512,
        count_1, Color(1, 1, 1));
    }

    if (CDtimer <= 1 * 60 && CDtimer > 0 * 60){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
        WIDTH, HEIGHT,
        0, 0, 1024, 512,
        count_start, Color(1, 1, 1));
    }

    if (CDtimer <= 0){
      Countdown_Se.stop();
      CDswitch = false;
    }

  }
}