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
 const int item_width = 150;           // アイテムの横幅
 const int item_height = 150;          // アイテムの縦幅
 const int item_x = 3;             // アイテムの種類

 void Disp_Background(AppEnv&);      // アイテム購入画面の背景表示
 void Draw_Item(AppEnv&, long long int&, bool&, bool&, bool&); // アイテムの表示
 void Disp_Money(long long int&);       // 所持金の表示
 void Next_Stage(int&);              // 次のステージへ進行
 bool Inside(AppEnv&, float, float, float, float, float, float);
};