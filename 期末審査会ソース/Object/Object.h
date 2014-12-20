#pragma once
#include "../common.h"
#include "../lib/random.hpp"
#include <ctime>

struct obj{
  float x; // ｘ座標
  float y; // ｙ座標
  float width; // オブジェクトの横幅
  float height; // オブジェクトの縦幅
  bool isHit; // クリック判定
  bool active; // 表示判定
  float mem_x; // クリックされた位置を保存する為の箱
  Color col; // 複数のオブジェクトを用意する為の箱(後程画像データに変更予定)
  int points; // そのオブジェクトが持つ得点
  int recycle;
};

class Square{
private:
  Random random;
  obj Object[20];
  Vec2f mouse_pos;

  int i;
  const int   x = 20; // オブジェクトを用意する数
  const int Center_X = 0; // クリックしたオブジェクトが飛んでいく位置X
  const int Center_Y = 200; // クリックしたオブジェクトが飛んでいく位置Y

  int slide_MOVE; // 横に流れる速度(クリックしていない状態)
  int flip_MOVE;   // クリックした後に飛んでいく速度
  
  int random_count; // ランダムの数値を入れる為の変数

  bool trigger;         // オブジェクトが１つずつ動き始めるようにする為のスイッチ
  float timer;           // トリガーをtrueにする為のタイマー
  float time_count; // タイマーに＋していく数字

  int score;             // ゲームとしての得点
  int recycle_point; // 特定のオブジェクトをクリックした時の数値

  bool count_stop; // 一時停止用

  int time_limit; // 制限時間

  int stage_No;

public:
  Square(); // コンストラクタの呼び出し用

  void Draw();                   // 四角を表示する為の関数
  void Countdown();         // タイマーをカウントする為の関数
  void Update(AppEnv&); // 四角を動かす為の関数

  void disp_Score(Texture&);   // スコアを表示する為の関数
  int sub_Score();       // 減算されるスコア関数
  void recycle_Score(Texture&);  // 特定のオブジェクトをクリックした時に加算されるスコア関数
  void board(Texture&); // リサイクル標識の表示
  void Pause(AppEnv&); // 一時停止機能
  void Limit(Texture&); // 制限時間表示・処理
};