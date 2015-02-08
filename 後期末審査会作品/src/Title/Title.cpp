#pragma once
#include "Title.h"

// �R���X�g���N�^
Title::Title() :
title_background("res/png/title.png"),
title1("res/png/title1.png"),
title2("res/png/title2.png"),
start_end1("res/png/start_end1.png"),
start_end2("res/png/start_end2.png"),
start_end3("res/png/start_end3.png"),
Catalog("res/png/catalog.png"),

Title_Bgm("res/wav/title.wav"),
Choice_Se("res/se/Choice.wav"),
Enter_Se("res/se/Enter.wav")
{
  next = false;
  timer = 0;
  spin = 0.3;
  R = 0.5;
  G = 0.5;
  B = 0.25;
  color_switch = false;
  Choice_switch = false;
  Enter_switch = false;
}

// �}�E�X�̓����蔻��
bool Title::Inside(AppEnv& app_env,
                            float mouse_x, float mouse_y,
                            float x, float y,
                            float width, float height){
  if (mouse_x >= x && mouse_x <= x + width &&
    mouse_y >= y && mouse_y <= y + height){
    return true;
  }
  return false;
}

// �^�C�g����ʂ̉摜�\��
void Title::Disp_Title(AppEnv& app_env, int& game_mode){
  // BGM�Đ�
  if (!Title_Bgm.isPlaying()){
    Title_Bgm.gain(0.2);
    Title_Bgm.play();
    Title_Bgm.looping(true);
  }

  // SE�Đ�
  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -113, -134, 276, 97)){
    if (!Choice_switch){
      Choice_Se.gain(0.4);
      Choice_Se.play();
    }
  }
  else if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -113, -234, 276, 97)){
    if (!Choice_switch){
      Choice_Se.gain(0.4);
      Choice_Se.play();
    }
  }
  else {
    Choice_Se.stop();
  }

  mouse_pos = app_env.mousePosition(); // �}�E�X�̃|�W�V�������L��
  drawFillBox(-500, -250, WIDTH, HEIGHT, Color(1, 1, 1));// ���w�i���ɕ`��

  if (R >= 1.00){
    color_switch = true; 
  }
  if (R <= 0.5) {
    color_switch = false; 
  }
  if (color_switch) {
    R -= 0.01;
    G -= 0.01;
    B -= 0.005;
  }
  else{
    R += 0.01;
    G += 0.01;
    B += 0.005;
  }

  // ���w�i�̏�ɍH��ꖇ�G
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
    WIDTH, HEIGHT,
    0, 0, 256, 160,
    title_background, Color(1, 1, 1));

  // �^�C�g�����S�P
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
    WIDTH, HEIGHT,
    0, 0, 1000, 500,
    title1, Color(R,G,B));

  // �^�C�g�����S�Q(�wRe:�x����)
  drawTextureBox(-356, 150,
    WIDTH, HEIGHT,
    0, 0, 1000, 500,
    title2, Color(1, 1, 1), spin, Vec2f(1, 1), Vec2f(132,415));
  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -486, 94, 259, 132)){
    spin += 0.03;
  }

  // �}�E�X�|�C���^���w�����`�Ɓx�̘g���Ȃ�
  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -100, -134, 250, 84) || next){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      start_end2, Color(1, 1, 1));
    Choice_switch = true;
    if (app_env.isPushButton(Mouse::LEFT)){
      next = true;
    }
  }

  // �}�E�X�|�C���^���w�I���x�̘g���Ȃ�
  else if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), -100, -221, 250, 84) && !next){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      start_end3, Color(1, 1, 1));
    Choice_switch = true;
    if (app_env.isPushButton(Mouse::LEFT)){
      game_mode = -1;
    }
  }

  // �ǂ���̘g�ɂ��}�E�X�|�C���^�������Ă��Ȃ����
  else{
    Choice_switch = false;
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      start_end1, Color(1, 1, 1));
  }
}

// �Ó]���ăX�e�[�W���\����
void Title::Black_Out(int& game_mode){
  if (next){
    // ���艹�Đ�
    if (!Enter_switch){
      Enter_Se.gain(0.5);
      Enter_Se.play();
    }
    timer += 2;
    Enter_switch = true;

    drawFillBox(-WIDTH/2, -HEIGHT/2,
      WIDTH, HEIGHT,
      color256(0,0,0,timer));
  }
  if (timer == 256){
    Title_Bgm.stop();
    game_mode = SEASON;
    spin = 0.3;
    next = false;
    timer = 0;
    Choice_switch = false;
    Enter_switch = false;
  }
}

void Title::Draw_Catalog(AppEnv& app_env, bool& main_catalog, int& game_mode){
  if (main_catalog){
    drawTextureBox(300, -250, 200, 200,
      0, 0, 480, 375,
      Catalog, Color(1,1,1));
  }
  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(), 300, -250, 200, 200) && main_catalog){
    if (app_env.isPushButton(Mouse::LEFT)){
      Enter_Se.play();
      game_mode = CATALOG;
    }
  }
}