#pragma once
#include "Catalog.h"

Catalog::Catalog() :
before("res/item/catalog2.png"),
next("res/item/catalog3.png"),
back_log("res/item/catalog4.png"),
next_page("res/wav/next.wav"),
before_page("res/wav/before.wav")
{
  // テクスチャの呼び出し先をchar型で書き込む
  const char* texname[] = { 
    "res/item/catalog/Page[0].png", "res/item/catalog/Page[1].png",
    "res/item/catalog/Page[2].png", "res/item/catalog/Page[3].png",
    "res/item/catalog/Page[4].png", "res/item/catalog/Page[5].png",
    "res/item/catalog/Page[6].png", "res/item/catalog/Page[7].png",
    "res/item/catalog/Page[8].png", "res/item/catalog/Page[9].png", 

    "res/item/catalog/Page[10].png", "res/item/catalog/Page[11].png",
    "res/item/catalog/Page[12].png", "res/item/catalog/Page[13].png",
    "res/item/catalog/Page[14].png", "res/item/catalog/Page[15].png",
    "res/item/catalog/Page[16].png", "res/item/catalog/Page[17].png",
    "res/item/catalog/Page[18].png", "res/item/catalog/Page[19].png",

    "res/item/catalog/Page[20].png", "res/item/catalog/Page[21].png",
    "res/item/catalog/Page[22].png", "res/item/catalog/Page[23].png",
    "res/item/catalog/Page[24].png", "res/item/catalog/Page[25].png",
    "res/item/catalog/Page[26].png", "res/item/catalog/Page[27].png",
    "res/item/catalog/Page[28].png", "res/item/catalog/Page[29].png",

    "res/item/catalog/Page[30].png", "res/item/catalog/Page[31].png",
    "res/item/catalog/Page[32].png", "res/item/catalog/Page[33].png",
    "res/item/catalog/Page[34].png", "res/item/catalog/Page[35].png",
    "res/item/catalog/Page[36].png", "res/item/catalog/Page[37].png",
    "res/item/catalog/Page[38].png", "res/item/catalog/Page[39].png",
  
    "res/item/catalog/Page[40].png", "res/item/catalog/Page[41].png",
    "res/item/catalog/Page[42].png", "res/item/catalog/Page[43].png",
    "res/item/catalog/Page[44].png", "res/item/catalog/Page[45].png",
    "res/item/catalog/Page[46].png", "res/item/catalog/Page[47].png",
    "res/item/catalog/Page[48].png", "res/item/catalog/Page[49].png",
 
    "res/item/catalog/Page[50].png", "res/item/catalog/Page[51].png",
    "res/item/catalog/Page[52].png", "res/item/catalog/Page[53].png",
    "res/item/catalog/Page[54].png", "res/item/catalog/Page[55].png",
    "res/item/catalog/Page[56].png", "res/item/catalog/Page[57].png",
    "res/item/catalog/Page[58].png", "res/item/catalog/Page[59].png",
  
    "res/item/catalog/Page[60].png", "res/item/catalog/Page[61].png",
    "res/item/catalog/Page[62].png", "res/item/catalog/Page[63].png",
    "res/item/catalog/Page[64].png", "res/item/catalog/Page[65].png",
    "res/item/catalog/Page[66].png", "res/item/catalog/Page[67].png",
    "res/item/catalog/Page[68].png", "res/item/catalog/Page[69].png",
 
    "res/item/catalog/Page[70].png", "res/item/catalog/Page[71].png",
    "res/item/catalog/Page[72].png", "res/item/catalog/Page[73].png",
    "res/item/catalog/Page[74].png", "res/item/catalog/Page[75].png",
    "res/item/catalog/Page[76].png", "res/item/catalog/Page[77].png",
    "res/item/catalog/Page[78].png", "res/item/catalog/Page[79].png",
  
    "res/item/catalog/Page[80].png", "res/item/catalog/Page[81].png",
    "res/item/catalog/Page[82].png", "res/item/catalog/Page[83].png",
    "res/item/catalog/Page[84].png", "res/item/catalog/Page[85].png",
    "res/item/catalog/Page[86].png", "res/item/catalog/Page[87].png",
    "res/item/catalog/Page[88].png", "res/item/catalog/Page[89].png",
  
    "res/item/catalog/Page[90].png"
  };

  // 画像をfor文で全て呼び出す
  for (int texIndex = 0; texIndex < TEX_NUM; texIndex++)
  {
    // 画像の名前はPage_List[0~90]を宣言させ、
    // その画像はどこから呼び出すかを、newの先で宣言。(たぶん)
    Page_List[texIndex] = new Texture(texname[texIndex]);
  }
  page_no = 0;
  clear = 1;
  clear_switch = true;
}

// 枠の内側に入ったかどうかの判定
bool Catalog::Inside(AppEnv& app_env,
  float mouse_x, float mouse_y,
  float x, float y,
  float width, float height){
  if (mouse_x >= x && mouse_x <= x + width &&
    mouse_y >= y && mouse_y <= y + height){
    return true;
  }
  return false;
}

void Catalog::Draw_Catalog(AppEnv& app_env){
  mouse_pos = app_env.mousePosition();

    drawTextureBox(-WIDTH/2, -HEIGHT/2, WIDTH, HEIGHT,
      0, 0, 1000, 500,
      *Page_List[page_no], Color(1,1,1));
}

void Catalog::Catalog_Update(AppEnv& app_env, int& game_mode){
  // 『右クリックでタイトルへ戻る』表示
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2,
    WIDTH, HEIGHT,
    0, 0, 1000, 500,
    back_log, Color(1, 1, 1,clear));

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

  // 『前』の枠内なら
  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(),
                 -429, -167, 99, 99)){
      if (page_no > 0){
        // 『前』の枠内を強調した画像を表示
        drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
          0, 0, 1000, 500,
          before, Color(1, 1, 1));
        if (app_env.isPushButton(Mouse::LEFT)){
          before_page.gain(0.6);
        before_page.play();
        page_no -= 1;
      }
    }
  }

  // 『次』の枠内なら
  if (Inside(app_env, mouse_pos.x(), mouse_pos.y(),
                 330, -167, 99, 99)){
      if (page_no < Page90){
        // 『次』の枠内を強調した画像を表示
        drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
          0, 0, 1000, 500,
          next, Color(1, 1, 1));
        if (app_env.isPushButton(Mouse::LEFT)){
          next_page.gain(0.6);
        next_page.play();
        page_no += 1;
      }
    }
  }

  if (app_env.isPushButton(Mouse::RIGHT)){
    game_mode = TITLE;
  }

}