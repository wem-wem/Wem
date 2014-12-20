#pragma once

// ƒŠƒUƒ‹ƒg‰æ–Ê”wŒi•\¦
void disp_Result(Texture& result){
  drawTextureBox(-500, -250,
    500, 250,
    0,0, 1024, 512,
    result, Color(1,1,1));
}