#pragma once

// �^�C�g����ʂ̔w�i�\��
void disp_Title(Texture& title){
  drawTextureBox(-500, -250,
    500, 250,
    0, 0, 1024, 512,
    title, Color(1, 1, 1));
}