#pragma once
#include "../common.h"

class Season{
private:
  bool next;
  float timer; // 暗転カウントダウン用

  bool clear_switch;
  double clear;

  bool BGM_switch;

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
  Texture next_curtain;
  Texture click_next;


public:
  Season();
  Media Season_Bgm;

  void Draw_Background(int&);
  void Start_Game(AppEnv&, int&);
};