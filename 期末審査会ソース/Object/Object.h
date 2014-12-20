#pragma once
#include "../common.h"
#include "../lib/random.hpp"
#include <ctime>

struct obj{
  float x; // �����W
  float y; // �����W
  float width; // �I�u�W�F�N�g�̉���
  float height; // �I�u�W�F�N�g�̏c��
  bool isHit; // �N���b�N����
  bool active; // �\������
  float mem_x; // �N���b�N���ꂽ�ʒu��ۑ�����ׂ̔�
  Color col; // �����̃I�u�W�F�N�g��p�ӂ���ׂ̔�(����摜�f�[�^�ɕύX�\��)
  int points; // ���̃I�u�W�F�N�g�������_
  int recycle;
};

class Square{
private:
  Random random;
  obj Object[20];
  Vec2f mouse_pos;

  int i;
  const int   x = 20; // �I�u�W�F�N�g��p�ӂ��鐔
  const int Center_X = 0; // �N���b�N�����I�u�W�F�N�g�����ł����ʒuX
  const int Center_Y = 200; // �N���b�N�����I�u�W�F�N�g�����ł����ʒuY

  int slide_MOVE; // ���ɗ���鑬�x(�N���b�N���Ă��Ȃ����)
  int flip_MOVE;   // �N���b�N������ɔ��ł������x
  
  int random_count; // �����_���̐��l������ׂ̕ϐ�

  bool trigger;         // �I�u�W�F�N�g���P�������n�߂�悤�ɂ���ׂ̃X�C�b�`
  float timer;           // �g���K�[��true�ɂ���ׂ̃^�C�}�[
  float time_count; // �^�C�}�[�Ɂ{���Ă�������

  int score;             // �Q�[���Ƃ��Ă̓��_
  int recycle_point; // ����̃I�u�W�F�N�g���N���b�N�������̐��l

  bool count_stop; // �ꎞ��~�p

  int time_limit; // ��������

  int stage_No;

public:
  Square(); // �R���X�g���N�^�̌Ăяo���p

  void Draw();                   // �l�p��\������ׂ̊֐�
  void Countdown();         // �^�C�}�[���J�E���g����ׂ̊֐�
  void Update(AppEnv&); // �l�p�𓮂����ׂ̊֐�

  void disp_Score(Texture&);   // �X�R�A��\������ׂ̊֐�
  int sub_Score();       // ���Z�����X�R�A�֐�
  void recycle_Score(Texture&);  // ����̃I�u�W�F�N�g���N���b�N�������ɉ��Z�����X�R�A�֐�
  void board(Texture&); // ���T�C�N���W���̕\��
  void Pause(AppEnv&); // �ꎞ��~�@�\
  void Limit(Texture&); // �������ԕ\���E����
};