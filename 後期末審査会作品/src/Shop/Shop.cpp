#pragma once
#include "Shop.h"

Shop::Shop():
back_ground1("res/png/shop_background1.png"),
back_ground2("res/png/shop_background2.png"),
Item1("res/png/double_recycle.png"),
Item2("res/png/quick.png"),
Item3("res/png/catalog.png"),
Item1_txt("res/png/Item1_txt.png"), 
Item2_txt("res/png/Item2_txt.png"), 
Item3_txt("res/png/Item3_txt.png"),
sold_out_board("res/png/sold_out_board.png"),
shortage("res/png/shortage.png"),
num_chihaya("res/png/number_chihaya.png"),
comma("res/png/comma.png"),

Shop_Bgm("res/wav/shop.wav"),
Item_Get("res/se/Item_Get.wav"),
Bad_Choice("res/se/Bad_Choice.wav")
{
  i = 0;
  next = false;
  timer = 0;

  // �A�C�e�����̏����l
  Item[0] = {100000, false};
  Item[1] = { 100000, false };
  Item[2] = { 1000000000, false };
}

// �g�̓����ɓ��������ǂ����̔���
bool Shop::Inside(AppEnv& app_env,
  float mouse_x, float mouse_y,
  float x, float y,
  float width, float height){
  if (mouse_x >= x && mouse_x <= x + width &&
    mouse_y >= y && mouse_y <= y + height){
    return true;
  }
  return false;
}

// �w�i�\��
void Shop::Disp_Background(AppEnv& app_env){
  // BGM�Đ�
  if (!Shop_Bgm.isPlaying()){
    Shop_Bgm.gain(0.1);
    Shop_Bgm.play();
    Shop_Bgm.looping(true);
  }

  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(),
    -WIDTH/2, -HEIGHT/2, 397, 97) || next){
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      back_ground2, Color(1, 1, 1));
    if (app_env.isPushButton(Mouse::LEFT)){
      next = true;
    }
  }
  else {
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      back_ground1, Color(1, 1, 1));
  }

}

// �A�C�e���̕\��
void Shop::Draw_Item(AppEnv& app_env, long long int& main_money,
                                     bool& main_double_recycle, bool& main_quick,
                                     bool& main_catalog){
  mouse_pos = app_env.mousePosition();

  // ���T�C�N�������A�b�v
  drawTextureBox(-305, 25, 110, 110,
    0, 0, 250, 240,
    Item1, Color(1, 1, 1));

  // �R���x�A�ғ����x�A�b�v
  drawTextureBox(-55, 25, 110, 110,
    0, 0, 500, 427,
    Item2, Color(1, 1, 1));

  // ���Y�ژ^
  drawTextureBox(195, 25, 110, 110,
    0, 0, 480, 375,
    Item3, Color(1, 1, 1));

  for (i = 0; i < item_x; i++){

    // �A�C�e���̘g���Ȃ�A���ꂼ��̐������\��
    if (Inside(app_env, mouse_pos.x(), mouse_pos.y(),
      -305+(250*i), 25,
      110, 110)){
      if (i == 0){
        drawTextureBox(-WIDTH/2, -HEIGHT/2, WIDTH, HEIGHT,
          0, 0, 1000, 500,
          Item1_txt, Color(1, 1, 1));
      }
      if (i == 1){
        drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
          0, 0, 1000, 500,
          Item2_txt, Color(1, 1, 1));
      }
      if (i == 2){
        drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
          0, 0, 1000, 500,
          Item3_txt, Color(1, 1, 1));
      }

      // �N���b�N������
      if (app_env.isPushButton(Mouse::LEFT)){
        // ������������Ă��āA�����Ă��Ȃ��A�C�e�����N���b�N�����ꍇ
        if (!Item[i].sold_out && Item[i].price <= main_money){
          Item[i].sold_out = true;
          Item_Get.play();
          main_money -= Item[i].price;
          // ����ꂽ�A�C�e�����ɃX�C�b�`���I���ɂ���
          if (i == 0) main_double_recycle = true;
          if (i == 1) main_quick = true;
          if (i == 2) main_catalog = true;
        }

        // ������������Ă��Ȃ��A�܂��͊��ɔ������A�C�e�����N���b�N�����ꍇ
        else if (Item[i].sold_out ||
          !Item[i].sold_out && Item[i].price > main_money){
          Bad_Choice.pitch(1.5);
          Bad_Choice.gain(0.3);
          Bad_Choice.play();
        }
      }

    }

    // �w��������w����؂�x��\��
    if (Item[i].sold_out){
      drawTextureBox(-305 + (250 * i), 25, 110, 110,
        0, 0, 128, 128, sold_out_board, Color(1, 1, 1));
    }

    // ���������s�����Ă�����w���z�s���x��\��
    if (!Item[i].sold_out && Item[i].price > main_money){
      drawTextureBox(-305 + (250 * i), 25, 110, 110,
        0, 0, 128, 128, shortage, Color(1, 1, 1));
    }

  }
}

// �������̕\��
void Shop::Disp_Money(long long int& main_money){
  // �P���� 870 , 396
  drawTextureBox(400, -235, 45, 75,
    0 + 100 * (main_money % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �Q����
  drawTextureBox(400 - 35, -235, 45, 75,
    0 + 100 * (main_money / 10 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �R����
  drawTextureBox(400 - 70, -235, 45, 75,
    0 + 100 * (main_money / 100 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �J���}
  drawTextureBox(400 - 80, -235, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // �S����
  drawTextureBox(400 - 115, -235, 45, 75,
    0 + 100 * (main_money / 1000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �T����
  drawTextureBox(400 - 150, -235, 45, 75,
    0 + 100 * (main_money / 10000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �U����
  drawTextureBox(400 - 185, -235, 45, 75,
    0 + 100 * (main_money / 100000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �J���}
  drawTextureBox(400 - 195, -235, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // �V����
  drawTextureBox(400 - 230, -235, 45, 75,
    0 + 100 * (main_money / 1000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �W����
  drawTextureBox(400 - 265, -235, 45, 75,
    0 + 100 * (main_money / 10000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �X����
  drawTextureBox(400 - 300, -235, 45, 75,
    0 + 100 * (main_money / 100000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));

  // �J���}
  drawTextureBox(400 - 310, -235, 16, 16,
    0, 0, 16, 16, comma, Color(0, 0, 0));

  // 10����
  drawTextureBox(400 - 345, -235, 45, 75,
    0 + 100 * (main_money / 1000000000 % 10), 0, 100, 128, num_chihaya, Color(0, 0, 0));
}

// �Ó]
void Shop::Next_Stage(int& game_mode){
  if (next){
    timer += 2;
    drawFillBox(-WIDTH / 2, -HEIGHT / 2,
      WIDTH, HEIGHT,
      color256(0, 0, 0, timer));
  }

  if (timer == 256){
    Shop_Bgm.stop();
    game_mode = SEASON;
    next = false;
    timer = 0;
    for (i = 0; i < item_x; i++){
      Item[i].sold_out = false;
    }
  }

}
