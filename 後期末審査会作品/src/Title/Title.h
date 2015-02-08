#pragma once
#include "../common.h"

class Title{
private:
  Vec2f mouse_pos;

  bool next;
  int timer; // �Ó]�J�E���g�_�E���p

  double spin;// �wRe:�x��]�p

  double R,G,B;
  bool color_switch;

  bool Choice_switch;
  bool Enter_switch;

  // �摜�̌Ăяo��---------------------------------------------------------------------------
  Texture title_background;        // �^�C�g�����(��)
  Texture title1;          // �^�C�g�������P
  Texture title2;          // �^�C�g�������Q
  Texture start_end1; // �^�C�g���I���摜
  Texture start_end2; // �^�C�g���I���摜
  Texture start_end3; // �^�C�g���I���摜
  Texture Catalog;

  // ���̌Ăяo��-----------------------------------------------------------------------------
  Media Choice_Se;
  Media Enter_Se;

public:
  // �R���X�g���N�^
  Title();

  Media Title_Bgm;

  // �_�Ǝl�p�̓����蔻��
  bool Inside(AppEnv&, float, float, float, float, float, float);

  // �^�C�g����ʂ̔w�i�\��
  void Disp_Title(AppEnv&, int&);

  // �J�^���O�̕\��
  void Draw_Catalog(AppEnv&, bool&, int&);

  // �Ó]
  void Black_Out(int&);
};