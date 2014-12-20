#pragma once

// �_�Ǝl�p�̓����蔻�� + �N���b�N����
bool Hit(AppEnv& app_env, float mouse_x, float mouse_y, float x, float y, float width, float height){
  if (mouse_x >= x && mouse_x <= x + width &&
    mouse_y >= y && mouse_y <= y + height){
    if (app_env.isPushButton(Mouse::LEFT)){
      return true;
    }
  }
  return false;
}

