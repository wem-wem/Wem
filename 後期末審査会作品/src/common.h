#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/font.hpp"
#include "Object/Object.h"
#include <fstream>
#include <iostream>
using namespace std;

// アプリのウインドウサイズ
enum Window {
  WIDTH = 1000,
  HEIGHT = 500
};


// ゲームモードの切り替え
enum{
  TITLE,
  SEASON,
  GAME,
  RESULT,
  SHOP,
  CATALOG
};