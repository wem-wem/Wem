#pragma once
#include "Season.h"

Season::Season() :
season1("res/wall_paper/season1.png"),
season2("res/wall_paper/season2.png"),
season3("res/wall_paper/season3.png"),
season4("res/wall_paper/season4.png"),
season5("res/wall_paper/season5.png"),
season6("res/wall_paper/season6.png"),
season7("res/wall_paper/season7.png"),
season8("res/wall_paper/season8.png"),
season9("res/wall_paper/season9.png"),
season10("res/wall_paper/season10.png"),
next_curtain("res/wall_paper/next_curtain.png"),
click_next("res/wall_paper/click_next.png"),
Season_Bgm("res/wav/season.wav")
{
  next = false;
  timer = 0;

  clear_switch = true;
  clear = 1;

  BGM_switch = false;
}

// ステージ名表示
void Season::Draw_Background(int& stage_no){
  if (!BGM_switch){
    Season_Bgm.gain(0.1);
    Season_Bgm.play();
    BGM_switch = true;
  }
    if (stage_no == 0){
    drawTextureBox(-WIDTH/2, -HEIGHT/2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season1, Color(1,1,1));
  }

  else if (stage_no == 1){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season2, Color(1, 1, 1));
  }

  else if (stage_no == 2){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season3, Color(1, 1, 1));
  }

  else if (stage_no == 3){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season4, Color(1, 1, 1));
  }

  else if (stage_no == 4){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season5, Color(1, 1, 1));
  }

  else if (stage_no == 5){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season6, Color(1, 1, 1));
  }

  else if (stage_no == 6){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season7, Color(1, 1, 1));
  }

  else if (stage_no == 7){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season8, Color(1, 1, 1));
  }

  else if (stage_no == 8){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season9, Color(1, 1, 1));
  }

  else if (stage_no == 9){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      0, 0, 960, 648,
      season10, Color(1, 1, 1));
  }

  // 『クリックしたら本編へ』表示
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
    WIDTH, HEIGHT,
    0, 0, 1000, 500,
    click_next, Color(1, 1, 1,clear));

  if (clear == 1){
    clear_switch = true;
  }
  if (clear <= 0.02){
    clear_switch = false;
  }

  if (!clear_switch){
    clear += 0.02;
  }
  else{
    clear -= 0.02;
  }
  
  // 暗転用カーテン
  drawTextureBox(WIDTH - (33 * timer), -HEIGHT/2, 1500, HEIGHT,
    0, 0, 1000, 500,
    next_curtain, Color(1, 1, 1));

}

void Season::Start_Game(AppEnv& app_env, int& game_mode){
  // クリックでゲーム本編へ
  if (app_env.isPushButton(Mouse::LEFT)){
    next = true;
  }

  if (next){
    timer++;
  }

  if (timer == 60){
    Season_Bgm.stop();
    game_mode = GAME;
    timer = 0;
    next = false;
    BGM_switch = false;
  }

}
