#pragma once

// リザルト画面背景表示
void disp_Result(Texture& result){
  drawTextureBox(-500, -250,
    500, 250,
    0,0, 1024, 512,
    result, Color(1,1,1));
}