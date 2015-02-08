#pragma once
#include "../common.h"

struct item {
  int price;
  bool sold_out;
};

class Shop{
private:
  Vec2f mouse_pos;
  bool next;
  int timer;

  Texture back_ground1;
  Texture back_ground2;
  Texture Item1;
  Texture Item2;
  Texture Item3;
  Texture Item1_txt;
  Texture Item2_txt;
  Texture Item3_txt;
  Texture sold_out_board;
  Texture shortage;
  Texture num_chihaya;
  Texture comma;

  Media Item_Get;
  Media Bad_Choice;

public:
  Shop();
  Media Shop_Bgm;
  item Item[3];
 int i;
 const int item_width = 150;           // �A�C�e���̉���
 const int item_height = 150;          // �A�C�e���̏c��
 const int item_x = 3;             // �A�C�e���̎��

 void Disp_Background(AppEnv&);      // �A�C�e���w����ʂ̔w�i�\��
 void Draw_Item(AppEnv&, long long int&, bool&, bool&, bool&); // �A�C�e���̕\��
 void Disp_Money(long long int&);       // �������̕\��
 void Next_Stage(int&);              // ���̃X�e�[�W�֐i�s
 bool Inside(AppEnv&, float, float, float, float, float, float);
};