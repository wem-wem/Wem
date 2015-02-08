#pragma once
#include "Object.h"
#include "../Collision.h"

// コンストラクタ
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

// アイテム画像------------------------------------------------
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

// ＢＧＭ・ＳＥ------------------------------------------------
Game_Bgm("res/wav/game.wav"),
Attack("res/se/Attack.wav"),
Choice("res/se/Choice.wav"),
Enter("res/se/Enter.wav"),
Time_Up("res/se/Time_Up.wav"),
Countdown_Se("res/se/Countdown.wav"),
Shutter("res/se/Shutter.wav"),
Stop("res/se/Stop.wav")
{
  random.setSeed(u_int(time(nullptr))); // 何かしらの数字で初期化

  // ↓渡辺先生からの教え↓
  //const char* texname[] = {"","","",};
  //for (int texIndex = 0; texIndex < TEX_NUM; texIndex++)
  //{
  //  texList[texIndex] = new Texture(texname[texIndex]);
  //}

  flip_MOVE = 12; // 上に吹き飛ぶ速度

  trigger = false;    // オブジェクトが１つずつ動き始めるようにする為のスイッチ
  timer = 0;           // triggerをtrueにする為のタイマー

  score = 0;          // ゲームとしての得点
  bad_score = 0;  // ゲームとしての減点
  obj_score = 0;   // 右から左へ流れたアイテムの合計個数
  recycle_point = 0; // ハズレアイテムの為の点数

  money = 0;

  count_stop = false; // 一時停止用のスイッチ

  time_limit = 60 * 60; // 制限時間は各ステージ１分

  // 開始前のカウントダウン--------------------------------------------------
  CDtimer = 4 * 60;
  CDswitch = true;

  // 背景表示の切り替え用-----------------------------------------------------
  slide = 0;
  light_switch = false;
  shutter = 0;
  shutter_switch = false;
  shutter_UD = false;

  // 終了時の画面切り替え用--------------------------------------------------
  end_timer = 3 * 60;
  end_switch = false;
}

// 背景表示用の関数
void Square::Background(bool& main_quick){
  // BGM再生
  if (!CDswitch){
    if (!Game_Bgm.isPlaying()){
      Game_Bgm.gain(0.2);
      Game_Bgm.play();
      Game_Bgm.looping(true);
    }
  }

  // 壁紙
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1024, 512,
    wallpaper, Color(1, 1, 1));

  if (!count_stop && !CDswitch && !end_switch){
    if (main_quick) slide += 12;
    else slide += 6;
    if (slide >= 1002) slide = 0;
  }

  // リサイクル標識
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1000, 500,
    board, Color(1, 1, 1));
  drawTextureBox(-WIDTH/2 + 40, 40, 85,85,
    0, 0, 256,256,
    hazure, Color(1,1,1));

  // ベルトコンベア
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1024, 512,
    dodai1, Color(1, 1, 1));

    drawTextureBox(-WIDTH/2 + 54, -214, 893, 73,
      0+slide, 0, 1024, 128,
      dodai2, Color(1, 1, 1));

    // リサイクルダクト
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

    // 電気
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1024, 512,
      dodai4, Color(1, 1, 1));

    // タイムボード
    drawTextureBox(350, 125, 150, 125,
      0, 0, 1024, 1024,
      time_board, Color(1, 1, 1));

    // 出荷ボード
    drawTextureBox(-330, 95, 270, 155,
      0, 0, 1024, 1024,
      syukka_board, Color(1, 1, 1));

    // ポーズ機能案内ボード
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1024, 512,
      pause_board, Color(1, 1, 1));
}

// ステージ毎のオブジェクト管理
void Square::Variation(int& i, int& stage_no){
  // 初期位置に戻して、ランダムで再登場させる
  random_count = random.fromZeroToLast(4);                                        // random_countに０～３の値をランダムで与える
  Object[i] = { WIDTH / 2, -92, 0, 0, 80, 80, false, false, 0, 0, 0, 1, 0 }; // オブジェクトの初期化

  switch (stage_no){
    // ステージ１----------------------------------------------------------------
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

    // ステージ２----------------------------------------------------------------
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

    // ステージ３----------------------------------------------------------------
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

    // ステージ４----------------------------------------------------------------
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

    // ステージ５----------------------------------------------------------------
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

    // ステージ６----------------------------------------------------------------
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

    // ステージ７----------------------------------------------------------------
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

    // ステージ８----------------------------------------------------------------
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

    // ステージ９----------------------------------------------------------------
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

    // ステージ10----------------------------------------------------------------
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

// ポーズ中のオブジェクト表示
void Square::Variation2(int& stage_no, int b, int recycle_point){
  switch (stage_no){
    // ステージ１----------------------------------------------------------------
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

    // ステージ２----------------------------------------------------------------
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

    // ステージ３----------------------------------------------------------------
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

    // ステージ４----------------------------------------------------------------
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

    // ステージ５----------------------------------------------------------------
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

    // ステージ６----------------------------------------------------------------
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

    // ステージ７----------------------------------------------------------------
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

    // ステージ８----------------------------------------------------------------
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

    // ステージ９----------------------------------------------------------------
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

    // ステージ10----------------------------------------------------------------
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

// オブジェクトを表示する為の関数
void Square::Draw(int& stage_no){
  for (i = 0; i < x; i++){
    if (Object[i].active){                            // activeがtrueの時だけ表示する

      switch (stage_no){
        // ステージ１---------------------------------------------------------------------
      case 0:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season1, Color(1, 1, 1));
        break;

        // ステージ２------------------------------------------------------------------------
      case 1:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season2, Color(1, 1, 1));
        break;

        // ステージ３------------------------------------------------------------------------
      case 2:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season3, Color(1, 1, 1));
        break;

        // ステージ４------------------------------------------------------------------------
      case 3:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season4, Color(1, 1, 1));
        break;

        // ステージ５------------------------------------------------------------------------
      case 4:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season5, Color(1, 1, 1));
        break;

        // ステージ６------------------------------------------------------------------------
      case 5:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season6, Color(1, 1, 1));
        break;

        // ステージ７------------------------------------------------------------------------
      case 6:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season7, Color(1, 1, 1));
        break;

        // ステージ８------------------------------------------------------------------------
      case 7:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season8, Color(1, 1, 1));
        break;

        // ステージ９------------------------------------------------------------------------
      case 8:
          drawTextureBox(Object[i].x, Object[i].y,
            Object[i].width, Object[i].height,
            Object[i].cut_x, Object[i].cut_y, 256, 256,
            season9, Color(1, 1, 1));
        break;

        // ステージ10------------------------------------------------------------------------
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

// オブジェクトを動かすためのタイマー
void Square::Countdown(bool& main_quick){
  if (timer <= 60){
    if (!count_stop && !CDswitch && !end_switch){
      if (main_quick) timer += 4;
      else timer += 2;
    }
  }

  else{                              // タイマーが60を越えたら
    trigger = true;             // トリガーをtrueにして、
    timer = 0;                    // タイマーを０に戻す
  }
}

// 四角を動かす為の関数
void Square::Update(AppEnv& app_env, int& stage_no, bool& main_quick, bool& main_double_recycle){
  mouse_pos = app_env.mousePosition(); // マウスのポジションを記憶

  if (!count_stop && !CDswitch && !end_switch){                 // 一時停止がオフなら動く
    for (i = 0; i < x; i++){

      // 関数"Countdown"でtriggerがtrueになったら
      if (trigger){
        if (!Object[i].active){        // まだactiveがtrueじゃないモノを
          Object[i].active = true;  // trueにする。
          trigger = false;              // triggerを再度falseに戻して、Countdownで再度trueにさせる
        }
      }

      // クリックされていない状態のオブジェクトが左に流れる
      if (!Object[i].isHit){
        if (Object[i].active){
          if (!count_stop){
            if (main_quick) Object[i].x -= 6;
            else Object[i].x -= 3;
          }
        }
      }

      // Cllision.hにある当たり判定を使用。四角の中をクリック出来たか判定
      if (Hit(app_env, mouse_pos.x(), mouse_pos.y(),
                Object[i].x, Object[i].y,
                Object[i].width, Object[i].height)){
        Attack.play();
        Object[i].mem_x = Object[i].x; // クリックされた時のX座標を記憶
        Object[i].isHit = true;
      }

      // クリックをしたら画面中央上部に飛んでいく
      if (Object[i].isHit){
        Object[i].y += flip_MOVE;                  // 飛んでいく速度は現在12
        Object[i].x -= Object[i].mem_x / 13.7; // 記憶しておいたX座標を30で割り、画面の真ん中へ飛ぶようにする
        Object[i].width -= 1;                          // 同時に横幅と縦幅を縮める
        Object[i].height -= 1;
      }

      // Y座標が-92から71まで飛んだら…
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

        Variation(i, stage_no); // ステージ毎に違うオブジェクトを表示
      }

      // オブジェクトが左に流れきったら(クリックされずに流れたら)位置を戻す
      if (Object[i].x < -WIDTH / 2 - Object[i].width){
        score += Object[i].points;
        bad_score += Object[i].bad_point;
        obj_score += Object[i].obj_point;
        if (score <= 0)  { score = 0; }
        if (bad_score <= 0) { bad_score = 0; }
        if (obj_score <= 0) { obj_score = 0; }
        Object[i].active = false;
        Object[i].x = WIDTH / 2;

        Variation(i, stage_no); // ステージ毎に違うオブジェクトを表示
      }
    }
  
  }
}

// 出荷個数を画面に表示
void Square::disp_Score(){  
  // １桁目
  drawTextureBox(-180, 105, 50, 60,
    0 + 102 * (obj_score % 10), 0, 102, 128, num, Color(1, 1, 1));

  // ２桁目
  drawTextureBox(-180 - 50, 105, 50, 60,
      0 + 102 * (obj_score / 10 % 10), 0, 102, 128, num, Color(1, 1, 1));

   // ３桁目
  drawTextureBox(-180 - 100, 105, 50, 60,
      0 + 102 * (obj_score / 100 % 10), 0, 102, 128, num, Color(1, 1, 1));
}

// ポーズ中所持金を画面に表示
void Square::disp_Money(long long int& money){
  // １桁目 870 , 396
  drawTextureBox(270, -225, 45, 75,
    0 + 100 * (money % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // ２桁目
  drawTextureBox(270 - 35, -225, 45, 75,
    0 + 100 * (money / 10 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // ３桁目
  drawTextureBox(270 - 70, -225, 45, 75,
    0 + 100 * (money / 100 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // カンマ
  drawTextureBox(270 - 80, -225, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // ４桁目
  drawTextureBox(270 - 115, -225, 45, 75,
    0 + 100 * (money / 1000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // ５桁目
  drawTextureBox(270 - 150, -225, 45, 75,
    0 + 100 * (money / 10000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // ６桁目
  drawTextureBox(270 - 185, -225, 45, 75,
    0 + 100 * (money / 100000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // カンマ
  drawTextureBox(270 - 195, -225, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // ７桁目
  drawTextureBox(270 - 230, -225, 45, 75,
    0 + 100 * (money / 1000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // ８桁目
  drawTextureBox(270 - 265, -225, 45, 75,
    0 + 100 * (money / 10000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // ９桁目
  drawTextureBox(270 - 300, -225, 45, 75,
    0 + 100 * (money / 100000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // カンマ
  drawTextureBox(270 - 310, -225, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // 10桁目
  drawTextureBox(270 - 345, -225, 45, 75,
    0 + 100 * (money / 1000000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));
}

// リサイクルポイントの表示
void Square::recycle_Score(){
  // １桁目
  drawTextureBox(10, 23, 15, 30,
    0 + 102 * (recycle_point % 10), 0, 102, 128, num, Color(0, 1, 1));

  // ２桁目
  drawTextureBox(10 - 15, 23, 15, 30,
    0 + 102 * (recycle_point / 10 % 10), 0, 102, 128, num, Color(0, 1, 1));

  // ３桁目
  drawTextureBox(10 - 30, 23, 15, 30,
    0 + 102 * (recycle_point / 100 % 10), 0, 102, 128, num, Color(0, 1, 1));
}

// ベルトコンベアの蓋
void Square::Board(){
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
    0, 0, 1024, 512,
    dodai3, Color(1, 1, 1));

  // リサイクルダクトの蓋（未完成）
  if (shutter_switch){
    drawTextureBox(-22, 120 - shutter / 2, 52, shutter / 2,
      0, 0, 128, 0 + shutter,
      dodai7, Color(1, 1, 1));

    // シャッターを閉じ始める。
    if (shutter <= 120 && !shutter_UD){
      shutter += 24;
    }

    // 10フレーム経ったら開閉スイッチをオンにして…。
    if (shutter >= 120){
      shutter_UD = true;
    }

    // シャッターを開け始める。
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

// 一時停止機能
void Square::Pause(AppEnv& app_env,
                                int& game_mode, int& stage_no,
                                long long int& main_money){
 // 右クリックした時のスイッチの状態を判定
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

    // 一時停止中に所持金を表示
    disp_Money(main_money);

    // ポインタが『再開』の枠内なら
    if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -400, -140, 398, 95)){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
        0, 0, 1024, 512,
        pause2, Color(1, 1, 1));
      if (app_env.isPushButton(Mouse::LEFT)){
        Stop.play();
        count_stop = false;
      }
    }

    // ポインタが『タイトル』の枠内なら
    if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), 2, -140, 398, 95)){
      drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
        0, 0, 1024, 512,
        pause3, Color(1, 1, 1));
      if (app_env.isPushButton(Mouse::LEFT)){
        // タイトルに戻ったら変数を初期化
        game_mode = TITLE;
        trigger = false;    // オブジェクトが１つずつ動き始めるようにする為のスイッチ
        timer = 0;           // triggerをtrueにする為のタイマー
        score = 0;          // ゲームとしての得点
        recycle_point = 0; // ハズレアイテムの為の点数
        count_stop = false; // 一時停止用のスイッチ
        time_limit = 3600; // 制限時間は各ステージ１分
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

    // 本編に影響を与えない画像表示ループ
    for (int b = 0; b < 4; b++){
      Variation2(stage_no, b, recycle_point);
    }

  }
}

// 制限時間の表示・処理
void Square::Limit(AppEnv& app_env, int& game_mode, int& stage_no,
                              int& main_score, int& main_bad_score,
                              int& main_total_score, int& main_obj_score,
                              bool& main_double_recycle, bool& main_quick){
  int time=time_limit/60;
  if (app_env.isPushKey('T')){
    time_limit = 60;
  }
  // １桁目
  drawTextureBox(WIDTH/2 - 80, HEIGHT/2 - 122, 40, 50,
    0 + 102 * (time % 10), 0, 102, 128, num, Color(0, 0, 0));
  // ２桁目
  drawTextureBox(WIDTH/2 - 130, HEIGHT/2 - 122, 40, 50,
    0 + 102 * (time / 10 % 10), 0, 102, 128, num, Color(0, 0, 0));

  // １分経過すると停止
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
          // 一度メイン関数内の変数へ数値を記憶させる
          main_score = score;
          main_bad_score = bad_score;
          main_total_score = score - (bad_score * 1000);
          main_obj_score = obj_score;

          // 全ての変数をリセット
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

// ゲーム開始前のカウントダウン
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