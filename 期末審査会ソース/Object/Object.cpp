#pragma once
#include "Object.h"
#include "../Collision.h"

// �R���X�g���N�^
Square::Square(){
  random.setSeed(u_int(time(nullptr))); // ��������̐����ŏ�����

  slide_MOVE = 3; // ���ɗ���鑬�x
  flip_MOVE = 12; // ��ɐ�����ԑ��x

  trigger = false;    // �I�u�W�F�N�g���P�������n�߂�悤�ɂ���ׂ̃X�C�b�`
  timer = 0;           // trigger��true�ɂ���ׂ̃^�C�}�[
  time_count = 3; // ���t���[��timer�ɉ��Z���鐔

  score = 0;          // �Q�[���Ƃ��Ă̓��_
  recycle_point = 0; // �n�Y���A�C�e���ׂ̈̓_��

  count_stop = false; // �ꎞ��~�p�̃X�C�b�`

  time_limit = 3600; // �������Ԃ͊e�X�e�[�W�P��

  stage_No = 0;

  // �l�p�̐F�������_���Ō��߂�ׂ̃��[�v��
  for (i = 0; i < x; i++){
    random_count = random.fromZeroToLast(4);                                        // random_count�ɂO�`�R�̒l�������_���ŗ^����
    Object[i] = { WIDTH / 2, -100, 50, 50, false, false, 0, Color(1, 1, 1), 1, 1}; // �I�u�W�F�N�g�̏�����
    switch (random_count){
    case 0: Object[i].col = Color(1, 1, 0);
                Object[i].points = 2;
                Object[i].recycle = 0;
                break;
    case 1: Object[i].col = Color(1, 0, 1);
                Object[i].points = 3;
                Object[i].recycle = 0;
                break;
    case 2: Object[i].col = Color(0, 1, 1);
                Object[i].points = 5;
                Object[i].recycle = 0;
                break;
    default:Object[i].points = -10; // case3�̎��͏������������ɓ����Ă��锒�F�̎l�p��\��
    }
  }
}

// �l�p��\������ׂ̊֐�
void Square::Draw(){
  for (i = 0; i < x; i++){
    if (Object[i].active){                            // active��true�̎������\������
      drawFillBox(Object[i].x, Object[i].y,
        Object[i].width, Object[i].height,
        Object[i].col);
    }
  }
}

// �I�u�W�F�N�g�𓮂������߂̃^�C�}�[
void Square::Countdown(){
  if (timer <= 60){
    if (!count_stop){
      timer += time_count;  // �^�C�}�[�̐��l���J�E���g�̕��������₵������
    }
  }

  else{                              // �^�C�}�[��60���z������
    trigger = true;             // �g���K�[��true�ɂ��āA
    timer = 0;                    // �^�C�}�[���O�ɖ߂�
  }
}

// �l�p�𓮂����ׂ̊֐�
void Square::Update(AppEnv& app_env){
  mouse_pos = app_env.mousePosition(); // �}�E�X�̃|�W�V�������L��

  if (!count_stop){                 // �ꎞ��~���I�t�Ȃ瓮��
    for (i = 0; i < x; i++){
      // �֐�"Countdown"��trigger��true�ɂȂ�����
      if (trigger){
        if (!Object[i].active){        // �܂�active��true����Ȃ����m��
          Object[i].active = true;  // true�ɂ���B
          trigger = false;              // trigger���ēxfalse�ɖ߂��āACountdown�ōēxtrue�ɂ�����
        }
      }

      // �N���b�N����Ă��Ȃ���Ԃ̃I�u�W�F�N�g�����ɗ����
      if (!Object[i].isHit){
        if (Object[i].active){
          if (!count_stop){
            Object[i].x -= slide_MOVE;
          }
        }
      }

      // Cllision.h�ɂ��铖���蔻����g�p�B�l�p�̒����N���b�N�o����������
      if (Hit(app_env, mouse_pos.x(), mouse_pos.y(), Object[i].x, Object[i].y, Object[i].width, Object[i].height)){
        Object[i].mem_x = Object[i].x; // �N���b�N���ꂽ����X���W���L��
        Object[i].isHit = true;
      }

      // �N���b�N���������ʒ����㕔�ɔ��ł���
      if (Object[i].isHit){
        Object[i].y += flip_MOVE;                  // ���ł������x�͌���10
        Object[i].x -= Object[i].mem_x / 30; // �L�����Ă�����X���W��30�Ŋ���A��ʂ̐^�񒆂֔�Ԃ悤�ɂ���
        Object[i].width -= 1;                          // �����ɉ����Əc�����k�߂�
        Object[i].height -= 1;
      }

      // Y���W��-100����200�܂�(300)��񂾂�c
      if (Object[i].y >= Center_Y){
        recycle_point += Object[i].recycle;
        Object[i].isHit = false;

        // �����ʒu�ɖ߂��āA�����_���J���[�ōēo�ꂳ����
        random_count = random.fromZeroToLast(4);                                        // random_count�ɂO�`�R�̒l�������_���ŗ^����
        Object[i] = { WIDTH / 2, -100, 50, 50, false, false, 0, Color(1, 1, 1), 1, 1 }; // �I�u�W�F�N�g�̏�����
        switch (random_count){
        case 0: Object[i].col = Color(1, 1, 0);
          Object[i].points = 2;
          Object[i].recycle = 0;
          break;
        case 1: Object[i].col = Color(1, 0, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        case 2: Object[i].col = Color(0, 1, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        default:Object[i].points = -10; // case3�̎��͏������������ɓ����Ă��锒�F�̎l�p��\��
        }
      }

      // �I�u�W�F�N�g�����ɗ��ꂫ������(�N���b�N���ꂸ�ɗ��ꂽ��)�ʒu��߂�
      if (Object[i].x < -WIDTH / 2 - Object[i].width){
        score += Object[i].points;
        if (score <= 0)  { score = 0; }
        Object[i].active = false;
        Object[i].x = WIDTH / 2;

        // ���ɏo�Ă��鎞�ɐF���ς��悤�A�ēx�J���[�ύX
        random_count = random.fromZeroToLast(4);                                        // random_count�ɂO�`�R�̒l�������_���ŗ^����
        Object[i] = { WIDTH / 2, -100, 50, 50, false, false, 0, Color(1, 1, 1), 1, 1 }; // �I�u�W�F�N�g�̏�����
        switch (random_count){
        case 0: Object[i].col = Color(1, 1, 0);
          Object[i].points = 2;
          Object[i].recycle = 0;
          break;
        case 1: Object[i].col = Color(1, 0, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        case 2: Object[i].col = Color(0, 1, 1);
          Object[i].points = 3;
          Object[i].recycle = 0;
          break;
        default:Object[i].points = -10; // case3�̎��͏������������ɓ����Ă��锒�F�̎l�p��\��
        }
      }
    }

  }
}

// �X�R�A����ʂɕ\��
void Square::disp_Score(Texture& num){  
  // �P����
  drawTextureBox(-250, 200, 40, 50,
    0 + 102 * (score % 10), 0, 102, 128, num, Color(1, 1, 1));

  // �Q����
    drawTextureBox(-250 - 40, 200, 40, 50,
      0 + 102 * (score / 10 % 10), 0, 102, 128, num, Color(1, 1, 1));

   // �R����
    drawTextureBox(-250 - 80, 200, 40, 50,
      0 + 102 * (score / 100 % 10), 0, 102, 128, num, Color(1, 1, 1));

    // �S����
    drawTextureBox(-250 - 120, 200, 40, 50,
      0 + 102 * (score / 1000 % 10), 0, 102, 128, num, Color(1, 1, 1));

    // �T����
    drawTextureBox(-250 - 160, 200, 40, 50,
      0 + 102 * (score / 10000 % 10), 0, 102, 128, num, Color(1, 1, 1));

    // �U����
    drawTextureBox(-250 - 200, 200, 40, 50,
      0 + 102 * (score / 100000 % 10), 0, 102, 128, num, Color(1, 1, 1));
}

// ���T�C�N���|�C���g�̕\��
void Square::recycle_Score(Texture& num){
  // �P����
  drawTextureBox(0, 200, 40, 50,
    0 + 102 * (recycle_point % 10), 0, 102, 128, num, Color(0, 1, 1));

  // �Q����
  drawTextureBox(0 - 40, 200, 40, 50,
    0 + 102 * (recycle_point / 10 % 10), 0, 102, 128, num, Color(0, 1, 1));

  // �R����
  drawTextureBox(0 - 80, 200, 40, 50,
    0 + 102 * (recycle_point / 100 % 10), 0, 102, 128, num, Color(0, 1, 1));
}

// ���T�C�N���W���̕\��
void Square::board(Texture& board){
  drawTextureBox(-100, 0, 200, 200,
    0, 0, 400, 400, board, Color(1, 1, 1));
  drawFillBox(-20, 80, 40, 40, Color(1, 1, 1));
}

// �ꎞ��~�@�\
void Square::Pause(AppEnv& app_env){
 // �G���^�[�����������̃X�C�b�`�̏�Ԃ𔻒�
  if (app_env.isPushKey(GLFW_KEY_ENTER)){
    if (time_limit > 0){
      if (!count_stop){
        count_stop = true;
      }
      else{
        count_stop = false;
      }
    }
  }
}

// �������Ԃ̕\���E����
void Square::Limit(Texture& num){
  int time=time_limit/60;
  // �P����
  drawTextureBox(WIDTH/2 - 50, HEIGHT/2 - 50, 40, 50,
    0 + 102 * (time % 10), 0, 102, 128, num, Color(1, 1, 0));
  // �Q����
  drawTextureBox(WIDTH/2 - 100, HEIGHT/2 - 50, 40, 50,
    0 + 102 * (time / 10 % 10), 0, 102, 128, num, Color(1, 1, 0));

  // �P���o�߂���ƒ�~
  if (!count_stop){
    if (time_limit > 0){
      time_limit--;
    }
    else{
      count_stop = true;
    }
  }
}