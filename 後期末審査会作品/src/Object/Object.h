#pragma once
#include "../common.h"
#include "../lib/random.hpp"
#include <ctime>

struct obj{
  float x; // �����W
  float y; // �����W
  float cut_x; // �؂���J�n�ʒu
  float cut_y; // �؂���J�n�ʒu
  float width; // �I�u�W�F�N�g�̉���
  float height; // �I�u�W�F�N�g�̏c��
  bool isHit; // �N���b�N����
  bool active; // �\������
  float mem_x; // �N���b�N���ꂽ�ʒu��ۑ�����ׂ̔�
  int points; // ���̃I�u�W�F�N�g�������_
  int recycle; // ���̃I�u�W�F�N�g�������T�C�N���|�C���g
  int obj_point; // ���ꂽ�A�C�e���̌��v���p
  int bad_point; // �n�Y���A�C�e��������؂����ۂɑ�����|�C���g
};

class Square{
private:
  // �摜�̌Ăяo��---------------------------------------------------------------------------

  // ���n�Ӑ搶����̋�����
  //enum {
  //  tex_num,
  //  num_chihaya,
  //  TEX_NUM,
  //};
  //Texture* texList[TEX_NUM];

  Texture num; // ����
  Texture num_chihaya; // ����
  Texture comma; // �J���}
  Texture board; // ���T�C�N���W��
  Texture pause_board; // �d���f����
  Texture count_1;            // �{�҃J�E���g�_�E��
  Texture count_2;            // �{�҃J�E���g�_�E��
  Texture count_3;            // �{�҃J�E���g�_�E��
  Texture count_start;  // �{�҃J�E���g�_�E��
  Texture count_end;    // �{�ҏI�����摜
  Texture wallpaper; // �{�Ҕw�i
  Texture time_board;
  Texture syukka_board;
  Texture dodai1; // �{�҃p�[�c
  Texture dodai2; // �{�҃p�[�c
  Texture dodai3; // �{�҃p�[�c
  Texture dodai4; // �{�҃p�[�c
  Texture dodai5; // �{�҃p�[�c
  Texture dodai6; // �{�҃p�[�c
  Texture dodai7; // �{�҃p�[�c
  Texture pause1; // �|�[�Y��ʗp
  Texture pause2; // �|�[�Y��ʗp
  Texture pause3; // �|�[�Y��ʗp
  Texture pause4; // �|�[�Y��ʗp

  // �A�C�e��---------------------------------------------------------------------------------
  Texture season1;
  Texture season2;
  Texture season3;
  Texture season4;
  Texture season5;
  Texture season6;
  Texture season7;
  Texture season8;
  Texture season9;
  Texture season10;
  Texture hazure;

  // ���̓ǂݍ���-----------------------------------------------
  Media Attack;
  Media Choice;
  Media Enter;
  Media Shutter;
  Media Stop;

    Random random;
  obj Object[25];
  obj Pause_Obj[4];
  Vec2f mouse_pos;

  int i;
  const int   x = 25; // �I�u�W�F�N�g��p�ӂ��鐔
  const int Center_Y = 71; // �N���b�N�����I�u�W�F�N�g�����ł����ʒuY

  int flip_MOVE;   // �N���b�N������ɔ��ł������x
  
  int random_count; // �����_���̐��l������ׂ̕ϐ�

  bool trigger;         // �I�u�W�F�N�g���P�������n�߂�悤�ɂ���ׂ̃X�C�b�`
  float timer;           // �g���K�[��true�ɂ���ׂ̃^�C�}�[

  int time_limit; // ��������

  float slide;              // �x���g�R���x�A�̖����X���C�h������
  bool light_switch;  // �w�i�؂�ւ��p�X�C�b�`�Q
  float shutter;
  bool shutter_switch; // �V���b�^�[�̕\���p
  bool shutter_UD; // �V���b�^�[�̊J�p

  bool CDswitch;  // �Q�[���J�n�O�̃J�E���g�_�E���X�C�b�`

  int end_timer;
  bool end_switch;

public:
  Square(); // �R���X�g���N�^�̌Ăяo���p

  Media Game_Bgm;
  Media Time_Up;
  Media Countdown_Se;
  int CDtimer;       // �Q�[���J�n�O�̃J�E���g�_�E���^�C�}�[

  bool count_stop; // �ꎞ��~�p

  int score;             // �Q�[���Ƃ��Ă̓��_
  int recycle_point; // ����̃I�u�W�F�N�g���N���b�N�������̐��l
  int obj_score;      // ����؂����I�u�W�F�N�g�̌��̗݌v
  int bad_score;     // �o�b�h�|�C���g�̗݌v(�n�Y���A�C�e���̗��ꂽ��)
  int money;

  void Background(bool&);   // �X�e�[�W�̔w�i
  void Variation(int&, int&);       // �X�e�[�W���̃I�u�W�F�N�g�Ǘ�
  void Variation2(int&, int, int);
  void Draw(int&);                   // �l�p��\������ׂ̊֐�
  void Countdown(bool&);         // �^�C�}�[���J�E���g����ׂ̊֐�
  void Update(AppEnv&, int&, bool&, bool&); // �l�p�𓮂����ׂ̊֐�

  void disp_Score();   // �o�׌���\������ׂ̊֐�
  void disp_Money(long long int&);   // ��������\������ׂ̊֐�
  void recycle_Score();  // ����̃I�u�W�F�N�g���N���b�N�������ɉ��Z�����X�R�A�֐�
  void Board(); // ���T�C�N���W���̕\��
  void Pause(AppEnv&, int&, int&, long long int&); // �ꎞ��~�@�\
  void Limit(AppEnv&, int&, int&, int&, int&, int&, int&, bool&, bool&); // �������ԕ\���E����
  void Count_Down();  // �Q�[���J�n�O�̃J�E���g�_�E��
};