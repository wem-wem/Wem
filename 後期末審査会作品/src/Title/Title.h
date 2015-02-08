#pragma once
#include "../common.h"

class Title{
private:
  Vec2f mouse_pos;

  bool next;
  int timer; // 暗転カウントダウン用

  double spin;// 『Re:』回転用

  double R,G,B;
  bool color_switch;

  bool Choice_switch;
  bool Enter_switch;

  // 画像の呼び出し---------------------------------------------------------------------------
  Texture title_background;        // タイトル画面(仮)
  Texture title1;          // タイトル文字１
  Texture title2;          // タイトル文字２
  Texture start_end1; // タイトル選択画像
  Texture start_end2; // タイトル選択画像
  Texture start_end3; // タイトル選択画像
  Texture Catalog;

  // 音の呼び出し-----------------------------------------------------------------------------
  Media Choice_Se;
  Media Enter_Se;

public:
  // コンストラクタ
  Title();

  Media Title_Bgm;

  // 点と四角の当たり判定
  bool Inside(AppEnv&, float, float, float, float, float, float);

  // タイトル画面の背景表示
  void Disp_Title(AppEnv&, int&);

  // カタログの表示
  void Draw_Catalog(AppEnv&, bool&, int&);

  // 暗転
  void Black_Out(int&);
};