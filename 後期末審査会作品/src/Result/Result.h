#pragma once
#include "../common.h"

class Result{
private:
  Vec2f mouse_pos;
  // �摜�̌Ăяo��--------------------------------------------------------------------------
  Texture num_stamp; // ��ӕ��t�H���g�̐���
  Texture comma_stamp; // ��ӕ��t�H���g�̃J���}
  Texture result1;  // ���U���g���(�f�t�H���g)
  Texture result2;  // ���U���g���(���I����)
  Texture result3;  // ���U���g���(�E�I����)
  Texture frame_1;  // ���U���g���(��Ӄt���[���P)
  Texture frame_2;  // ���U���g���(��Ӄt���[���Q)
  Texture frame_3;  // ���U���g���(��Ӄt���[���R)


  bool next;
  int timer; // �Ó]�J�E���g�_�E���p

public:
  // �R���X�g���N�^
  Result();
  // �r�d�̌Ăяo��-------------------------------------------------------------------------
  Media Wadaiko1;
  Media Wadaiko2;

  int score;
  int obj_score;
  int bad_score;
  int total_score;
  int result_timer; // �X�R�A�\���Ɏ��ԍ�������ׂ̃^�C�}�[

  // �_�Ǝl�p�̓����蔻��
  bool Inside(AppEnv&, float, float, float, float, float, float);

  // ���U���g��ʔw�i�\��
  void disp_Result(AppEnv&, bool&, int&);

  // �Ó]
  void Black_Out(int&, long long int&);

  // �X�R�A��\������ׂ̊֐�
  void disp_Score(int&, int&, int&, int&);
};
