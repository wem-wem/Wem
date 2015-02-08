#pragma once
#include "Result.h"

Result::Result():
num_stamp("res/png/number_stamp.png"),
comma_stamp("res/png/comma_stamp.png"),
result1("res/png/result1.png"),
result2("res/png/result2.png"),
result3("res/png/result3.png"),
frame_1("res/png/frame_1.png"),
frame_2("res/png/frame_2.png"),
frame_3("res/png/frame_3.png"),

Wadaiko1("res/se/Wadaiko1.wav"),
Wadaiko2("res/se/Wadaiko2.wav")
{
  score = 0;
  obj_score = 0;
  bad_score = 0;
  total_score = 0;

  next = false;            // リザルト画面から次の画面へ切り替えるスイッチ
  timer = 0;                // 暗転用タイマー

  result_timer = 120;  // リザルト画面演出用タイマー
}

// マウスと四角範囲の判定
bool Result::Inside(AppEnv& app_env, 
                               float mouse_x, float mouse_y,
                               float x, float y,
                               float width, float height){
  if (mouse_x >= x && mouse_x <= x + width &&
    mouse_y >= y && mouse_y <= y + height){
    return true;
  }
  return false;
}

// リザルト画面背景表示
void Result::disp_Result(AppEnv& app_env,
                                        bool& count_stop, int& game_mode){
  mouse_pos = app_env.mousePosition(); // マウスのポジションを記憶

  // マウスポインタが『次の生産体制へ』の枠内なら
  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -495, -244, 493, 93) || next){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      result2, Color(1, 1, 1));
    if (app_env.isPushButton(Mouse::LEFT)){
      next = true;
    }
  }

  // マウスポインタが『今日はココまで！』の枠内なら
  else if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), 3, -244, 492, 93)){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      result3, Color(1, 1, 1));
    if (app_env.isPushButton(Mouse::LEFT)){
      game_mode = TITLE;
    }
  }

  // どちらの枠にもマウスポインタが入っていなければ
  else{
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 1000, 500,
      result1, Color(1, 1, 1));
    count_stop = false;
  }
}

// 『出荷数』『異物混入』『売上総額』の表示
void Result::disp_Score(int& main_score, int& main_bad_score,
                                       int& main_total_score, int& main_obj_score){
  score = main_score;
  obj_score = main_obj_score;
  bad_score = main_bad_score;
  total_score = main_total_score;

  if (result_timer >= 0){
    result_timer--;
  }

  if (result_timer == 100 || result_timer == 50){
    Wadaiko1.gain(2);
    Wadaiko1.play();
  }
  if (result_timer == 0){
    Wadaiko2.gain(2);
    Wadaiko2.play();
  }

  // 出荷数----------------------------------------------------------
  if (result_timer < 100){
    // １桁目
    drawTextureBox(300, 95, 100, 65,
      0 + 100 * (obj_score % 10), 0, 100, 128, num_stamp, Color(0, 0, 0));

    // ２桁目
    drawTextureBox(300 - 100, 95, 100, 65,
      0 + 100 * (obj_score / 10 % 10), 0, 100, 128, num_stamp, Color(0, 0, 0));

    // ３桁目
    drawTextureBox(300 - 200, 95, 100, 65,
      0 + 100 * (obj_score / 100 % 10), 0, 100, 128, num_stamp, Color(0, 0, 0));

    // 印鑑フレーム１
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 1000, 500,
      frame_1, Color(1, 1, 1));
  }

  // ハズレアイテムが流れた個数----------------------------------------------------------
  if (result_timer < 50){
    // １桁目
    drawTextureBox(300, 16, 100, 65,
      0 + 100 * (bad_score % 10), 0, 100, 128, num_stamp, Color(0, 0, 0));

    // ２桁目
    drawTextureBox(300 - 100, 16, 100, 65,
      0 + 100 * (bad_score / 10 % 10), 0, 100, 128, num_stamp, Color(0, 0, 0));

    // 印鑑フレーム２
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 1000, 500,
      frame_2, Color(1, 1, 1));
  }

  // 売上総額-------------------------------------------------------------------------------
  if (result_timer < 0){
    // １桁目 870 , 396
    drawTextureBox(320, -146, 50, 130,
      0 + 100 * (total_score % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // ２桁目
    drawTextureBox(320 - 50, -146, 50, 130,
      0 + 100 * (total_score / 10 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // ３桁目
    drawTextureBox(320 - 100, -146, 50, 130,
      0 + 100 * (total_score / 100 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // カンマ
    drawTextureBox(325 - 110, -136, 50, 50,
      0, 0, 16, 16, comma_stamp, Color(1, 0, 0));

    // ４桁目
    drawTextureBox(320 - 150, -146, 50, 130,
      0 + 100 * (total_score / 1000 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // ５桁目
    drawTextureBox(320 - 200, -146, 50, 130,
      0 + 100 * (total_score / 10000 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // ６桁目
    drawTextureBox(320 - 250, -146, 50, 130,
      0 + 100 * (total_score / 100000 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // カンマ
    drawTextureBox(325 - 260, -136, 50, 50,
      0, 0, 16, 16, comma_stamp, Color(1, 0, 0));

    // ７桁目
    drawTextureBox(320 - 300, -146, 50, 130,
      0 + 100 * (total_score / 1000000 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // ８桁目
    drawTextureBox(320 - 350, -146, 50, 130,
      0 + 100 * (total_score / 10000000 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // ９桁目
    drawTextureBox(320 - 400, -146, 50, 130,
      0 + 100 * (total_score / 100000000 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // カンマ
    drawTextureBox(325 - 410, -136, 50, 50,
      0, 0, 16, 16, comma_stamp, Color(1, 0, 0));

    // 10桁目
    drawTextureBox(320 - 450, -146, 50, 130,
      0 + 100 * (total_score / 1000000000 % 10), 0, 100, 128, num_stamp, Color(1, 0, 0));

    // 印鑑フレーム３
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 1000, 500,
      frame_3, Color(1, 1, 1));
  }
}

// 暗転
void Result::Black_Out(int& game_mode, long long int& main_money){
  if (next){
    timer += 2;

    drawFillBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      color256(0, 0, 0, timer));
  }
  if (timer == 256){
    main_money += total_score; // mainの変数"money"にスコアを保存して、加算していく
    game_mode = SHOP;
    next = false;
    timer = 0;
    result_timer = 120;
  }
}
