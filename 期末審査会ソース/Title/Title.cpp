#pragma once
#include "Title.h"

void disp_Title(Texture& title){
  drawTextureBox(-500, -250,
    1000, 500,
    0, 0, 1024, 512,
    title, Color(1, 1, 1));
}