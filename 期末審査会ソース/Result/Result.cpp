#pragma once
#include "Result.h"

// ���U���g��ʔw�i�\��
void disp_Result(Texture& result){
  drawTextureBox(-500, -250,
    1000, 500,
    0, 0, 1024, 512,
    result, Color(1, 1, 1));
}