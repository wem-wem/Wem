#pragma once
#include "../common.h"

class Result{
private:
  Vec2f mouse_pos;
  // 画像の呼び出し--------------------------------------------------------------------------
  Texture num_stamp; // 印鑑風フォントの数字
  Texture comma_stamp; // 印鑑風フォントのカンマ
  Texture result1;  // リザルト画面(デフォルト)
  Texture result2;  // リザルト画面(左選択時)
  Texture result3;  // リザルト画面(右選択時)
  Texture frame_1;  // リザルト画面(印鑑フレーム１)
  Texture frame_2;  // リザルト画面(印鑑フレーム２)
  Texture frame_3;  // リザルト画面(印鑑フレーム３)


  bool next;
  int timer; // 暗転カウントダウン用

public:
  // コンストラクタ
  Result();
  // ＳＥの呼び出し-------------------------------------------------------------------------
  Media Wadaiko1;
  Media Wadaiko2;

  int score;
  int obj_score;
  int bad_score;
  int total_score;
  int result_timer; // スコア表示に時間差をつける為のタイマー

  // 点と四角の当たり判定
  bool Inside(AppEnv&, float, float, float, float, float, float);

  // リザルト画面背景表示
  void disp_Result(AppEnv&, bool&, int&);

  // 暗転
  void Black_Out(int&, long long int&);

  // スコアを表示する為の関数
  void disp_Score(int&, int&, int&, int&);
};
