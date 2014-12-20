#pragma once
#include "Object.h"
#include "../Collision.h"

// コンストラクタ
Square::Square(){
  random.setSeed(u_int(time(nullptr))); // 何かしらの数字で初期化

  slide_MOVE = 3; // 横に流れる速度
  flip_MOVE = 12; // 上に吹き飛ぶ速度

  trigger = false;    // オブジェクトが１つずつ動き始めるようにする為のスイッチ
  timer = 0;           // triggerをtrueにする為のタイマー
  time_count = 3; // 毎フレームtimerに加算する数

  score = 0;          // ゲームとしての得点
  recycle_point = 0; // ハズレアイテムの為の点数

  count_stop = false; // 一時停止用のスイッチ

  time_limit = 3600; // 制限時間は各ステージ１分

  stage_No = 0;

  // 四角の色をランダムで決める為のループ文
  for (i = 0; i < x; i++){
    random_count = random.fromZeroToLast(4);                                        // random_countに０～３の値をランダムで与える
    Object[i] = { WIDTH / 2, -100, 50, 50, false, false, 0, Color(1, 1, 1), 1, 1}; // オブジェクトの初期化
    switch (random_count){
    case 0: Object[i].col = Color(1, 1, 0);
                Object[i].points = 2;
                Object[i].recycle = 0;
                break;
    case 1: Object[i].col = Color(1, 0, 1);
                Object[i].points = 3;
                Object[i].recycle = 0;
                break;
    case 2: Object[i].col = Color(0, 1, 1);
                Object[i].points = 5;
                Object[i].recycle = 0;
                break;
    default:Object[i].points = -10; // case3の時は初期化した時に入っている白色の四角を表示
    }
  }
}

// 四角を表示する為の関数
void Square::Draw(){
  for (i = 0; i < x; i++){
    if (Object[i].active){                            // activeがtrueの時だけ表示する
      drawFillBox(Object[i].x, Object[i].y,
        Object[i].width, Object[i].height,
        Object[i].col);
    }
  }
}

// オブジェクトを動かすためのタイマー
void Square::Countdown(){
  if (timer <= 60){
    if (!count_stop){
      timer += time_count;  // タイマーの数値をカウントの分だけ増やし続ける
    }
  }

  else{                              // タイマーが60を越えたら
    trigger = true;             // トリガーをtrueにして、
    timer = 0;                    // タイマーを０に戻す
  }
}

// 四角を動かす為の関数
void Square::Update(AppEnv& app_env){
  mouse_pos = app_env.mousePosition(); // マウスのポジションを記憶

  if (!count_stop){                 // 一時停止がオフなら動く
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
            Object[i].x -= slide_MOVE;
          }
        }
      }

      // Cllision.hにある当たり判定を使用。四角の中をクリック出来たか判定
      if (Hit(app_env, mouse_pos.x(), mouse_pos.y(), Object[i].x, Object[i].y, Object[i].width, Object[i].height)){
        Object[i].mem_x = Object[i].x; // クリックされた時のX座標を記憶
        Object[i].isHit = true;
      }

      // クリックをしたら画面中央上部に飛んでいく
      if (Object[i].isHit){
        Object[i].y += flip_MOVE;                  // 飛んでいく速度は現在10
        Object[i].x -= Object[i].mem_x / 30; // 記憶しておいたX座標を30で割り、画面の真ん中へ飛ぶようにする
        Object[i].width -= 1;                          // 同時に横幅と縦幅を縮める
        Object[i].height -= 1;
      }

      // Y座標が-100から200まで(300)飛んだら…
      if (Object[i].y >= Center_Y){
        recycle_point += Object[i].recycle;
        Object[i].isHit = false;

        // 初期位置に戻して、ランダムカラーで再登場させる
        random_count = random.fromZeroToLast(4);                                        // random_countに０～３の値をランダムで与える
        Object[i] = { WIDTH / 2, -100, 50, 50, false, false, 0, Color(1, 1, 1), 1, 1 }; // オブジェクトの初期化
        switch (random_count){
        case 0: Object[i].col = Color(1, 1, 0);
          Object[i].points = 2;
          Object[i].recycle = 0;
          break;
        case 1: Object[i].col = Color(1, 0, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        case 2: Object[i].col = Color(0, 1, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        default:Object[i].points = -10; // case3の時は初期化した時に入っている白色の四角を表示
        }
      }

      // オブジェクトが左に流れきったら(クリックされずに流れたら)位置を戻す
      if (Object[i].x < -WIDTH / 2 - Object[i].width){
        score += Object[i].points;
        if (score <= 0)  { score = 0; }
        Object[i].active = false;
        Object[i].x = WIDTH / 2;

        // 次に出てくる時に色が変わるよう、再度カラー変更
        random_count = random.fromZeroToLast(4);                                        // random_countに０～３の値をランダムで与える
        Object[i] = { WIDTH / 2, -100, 50, 50, false, false, 0, Color(1, 1, 1), 1, 1 }; // オブジェクトの初期化
        switch (random_count){
        case 0: Object[i].col = Color(1, 1, 0);
          Object[i].points = 2;
          Object[i].recycle = 0;
          break;
        case 1: Object[i].col = Color(1, 0, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        case 2: Object[i].col = Color(0, 1, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        default:Object[i].points = -10; // case3の時は初期化した時に入っている白色の四角を表示
        }
      }
    }

  }
}

// スコアを画面に表示
void Square::disp_Score(Texture& num){  
  // １桁目
  drawTextureBox(-250, 200, 40, 50,
    0 + 102 * (score % 10), 0, 102, 128, num, Color(1, 1, 1));

  // ２桁目
    drawTextureBox(-250 - 40, 200, 40, 50,
      0 + 102 * (score / 10 % 10), 0, 102, 128, num, Color(1, 1, 1));

   // ３桁目
    drawTextureBox(-250 - 80, 200, 40, 50,
      0 + 102 * (score / 100 % 10), 0, 102, 128, num, Color(1, 1, 1));

    // ４桁目
    drawTextureBox(-250 - 120, 200, 40, 50,
      0 + 102 * (score / 1000 % 10), 0, 102, 128, num, Color(1, 1, 1));

    // ５桁目
    drawTextureBox(-250 - 160, 200, 40, 50,
      0 + 102 * (score / 10000 % 10), 0, 102, 128, num, Color(1, 1, 1));

    // ６桁目
    drawTextureBox(-250 - 200, 200, 40, 50,
      0 + 102 * (score / 100000 % 10), 0, 102, 128, num, Color(1, 1, 1));
}

// リサイクルポイントの表示
void Square::recycle_Score(Texture& num){
  // １桁目
  drawTextureBox(0, 200, 40, 50,
    0 + 102 * (recycle_point % 10), 0, 102, 128, num, Color(0, 1, 1));

  // ２桁目
  drawTextureBox(0 - 40, 200, 40, 50,
    0 + 102 * (recycle_point / 10 % 10), 0, 102, 128, num, Color(0, 1, 1));

  // ３桁目
  drawTextureBox(0 - 80, 200, 40, 50,
    0 + 102 * (recycle_point / 100 % 10), 0, 102, 128, num, Color(0, 1, 1));
}

// リサイクル標識の表示
void Square::board(Texture& board){
  drawTextureBox(-100, 0, 200, 200,
    0, 0, 400, 400, board, Color(1, 1, 1));
  drawFillBox(-20, 80, 40, 40, Color(1, 1, 1));
}

// 一時停止機能
void Square::Pause(AppEnv& app_env){
 // エンターを押した時のスイッチの状態を判定
  if (app_env.isPushKey(GLFW_KEY_ENTER)){
    if (time_limit > 0){
      if (!count_stop){
        count_stop = true;
      }
      else{
        count_stop = false;
      }
    }
  }
}

// 制限時間の表示・処理
void Square::Limit(Texture& num){
  int time=time_limit/60;
  // １桁目
  drawTextureBox(WIDTH/2 - 50, HEIGHT/2 - 50, 40, 50,
    0 + 102 * (time % 10), 0, 102, 128, num, Color(1, 1, 0));
  // ２桁目
  drawTextureBox(WIDTH/2 - 100, HEIGHT/2 - 50, 40, 50,
    0 + 102 * (time / 10 % 10), 0, 102, 128, num, Color(1, 1, 0));

  // １分経過すると停止
  if (!count_stop){
    if (time_limit > 0){
      time_limit--;
    }
    else{
      count_stop = true;
    }
  }
}