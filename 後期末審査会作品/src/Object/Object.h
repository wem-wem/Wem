#pragma once
#include "../common.h"
#include "../lib/random.hpp"
#include <ctime>

struct obj{
  float x; // ｘ座標
  float y; // ｙ座標
  float cut_x; // 切り取り開始位置
  float cut_y; // 切り取り開始位置
  float width; // オブジェクトの横幅
  float height; // オブジェクトの縦幅
  bool isHit; // クリック判定
  bool active; // 表示判定
  float mem_x; // クリックされた位置を保存する為の箱
  int points; // そのオブジェクトが持つ得点
  int recycle; // そのオブジェクトが持つリサイクルポイント
  int obj_point; // 流れたアイテムの個数計測用
  int bad_point; // ハズレアイテムが流れ切った際に増えるポイント
};

class Square{
private:
  // 画像の呼び出し---------------------------------------------------------------------------

  // ↓渡辺先生からの教え↓
  //enum {
  //  tex_num,
  //  num_chihaya,
  //  TEX_NUM,
  //};
  //Texture* texList[TEX_NUM];

  Texture num; // 数字
  Texture num_chihaya; // 数字
  Texture comma; // カンマ
  Texture board; // リサイクル標識
  Texture pause_board; // 電光掲示板
  Texture count_1;            // 本編カウントダウン
  Texture count_2;            // 本編カウントダウン
  Texture count_3;            // 本編カウントダウン
  Texture count_start;  // 本編カウントダウン
  Texture count_end;    // 本編終了時画像
  Texture wallpaper; // 本編背景
  Texture time_board;
  Texture syukka_board;
  Texture dodai1; // 本編パーツ
  Texture dodai2; // 本編パーツ
  Texture dodai3; // 本編パーツ
  Texture dodai4; // 本編パーツ
  Texture dodai5; // 本編パーツ
  Texture dodai6; // 本編パーツ
  Texture dodai7; // 本編パーツ
  Texture pause1; // ポーズ画面用
  Texture pause2; // ポーズ画面用
  Texture pause3; // ポーズ画面用
  Texture pause4; // ポーズ画面用

  // アイテム---------------------------------------------------------------------------------
  Texture season1;
  Texture season2;
  Texture season3;
  Texture season4;
  Texture season5;
  Texture season6;
  Texture season7;
  Texture season8;
  Texture season9;
  Texture season10;
  Texture hazure;

  // 音の読み込み-----------------------------------------------
  Media Attack;
  Media Choice;
  Media Enter;
  Media Shutter;
  Media Stop;

    Random random;
  obj Object[25];
  obj Pause_Obj[4];
  Vec2f mouse_pos;

  int i;
  const int   x = 25; // オブジェクトを用意する数
  const int Center_Y = 71; // クリックしたオブジェクトが飛んでいく位置Y

  int flip_MOVE;   // クリックした後に飛んでいく速度
  
  int random_count; // ランダムの数値を入れる為の変数

  bool trigger;         // オブジェクトが１つずつ動き始めるようにする為のスイッチ
  float timer;           // トリガーをtrueにする為のタイマー

  int time_limit; // 制限時間

  float slide;              // ベルトコンベアの矢印をスライドさせる
  bool light_switch;  // 背景切り替え用スイッチ２
  float shutter;
  bool shutter_switch; // シャッターの表示用
  bool shutter_UD; // シャッターの開閉用

  bool CDswitch;  // ゲーム開始前のカウントダウンスイッチ

  int end_timer;
  bool end_switch;

public:
  Square(); // コンストラクタの呼び出し用

  Media Game_Bgm;
  Media Time_Up;
  Media Countdown_Se;
  int CDtimer;       // ゲーム開始前のカウントダウンタイマー

  bool count_stop; // 一時停止用

  int score;             // ゲームとしての得点
  int recycle_point; // 特定のオブジェクトをクリックした時の数値
  int obj_score;      // 流れ切ったオブジェクトの個数の累計
  int bad_score;     // バッドポイントの累計(ハズレアイテムの流れた個数)
  int money;

  void Background(bool&);   // ステージの背景
  void Variation(int&, int&);       // ステージ毎のオブジェクト管理
  void Variation2(int&, int, int);
  void Draw(int&);                   // 四角を表示する為の関数
  void Countdown(bool&);         // タイマーをカウントする為の関数
  void Update(AppEnv&, int&, bool&, bool&); // 四角を動かす為の関数

  void disp_Score();   // 出荷個数を表示する為の関数
  void disp_Money(long long int&);   // 所持金を表示する為の関数
  void recycle_Score();  // 特定のオブジェクトをクリックした時に加算されるスコア関数
  void Board(); // リサイクル標識の表示
  void Pause(AppEnv&, int&, int&, long long int&); // 一時停止機能
  void Limit(AppEnv&, int&, int&, int&, int&, int&, int&, bool&, bool&); // 制限時間表示・処理
  void Count_Down();  // ゲーム開始前のカウントダウン
};