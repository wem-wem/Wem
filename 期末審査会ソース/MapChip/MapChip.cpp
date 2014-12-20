#include "MapChip.h"

int hoge[10][20] = {
  { 0, 0, 2, 0, 1, 1, 0, 2, 1, 0, 3, 0, 1, 1, 2, 2, 0, 0},
  { 0, 1, 0, 0, 1, 1, 2, 2, 2, 0, 0, 0, 3, 1, 0, 2, 1, 0},
  { 0, 0, 0, 3, 1, 2, 0, 0, 2, 1, 3, 3, 1, 1, 1, 0, 0, 0},
  { 0, 0, 2, 0, 1, 1, 0, 2, 1, 0, 3, 0, 1, 1, 2, 2, 0, 0 },
  { 0, 1, 0, 0, 1, 1, 2, 2, 2, 0, 0, 0, 3, 1, 0, 2, 1, 0 },
  { 0, 0, 0, 3, 1, 2, 0, 0, 2, 1, 3, 3, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 2, 0, 1, 1, 0, 2, 1, 0, 3, 0, 1, 1, 2, 2, 0, 0 },
  { 0, 1, 0, 0, 1, 1, 2, 2, 2, 0, 0, 0, 3, 1, 0, 2, 1, 0 },
  { 0, 0, 0, 3, 1, 2, 0, 0, 2, 1, 3, 3, 1, 1, 1, 0, 0, 0 },
  { 0, 0, 2, 0, 1, 1, 0, 2, 1, 0, 3, 0, 1, 1, 2, 2, 0, 0 },
};
void drawMapChip(){
  for (int y = 0; y < 10; y++){
    for (int x = 0; x < 20; x++){
      switch (hoge[y][x]){
      case 0:
        drawFillBox(-WIDTH / 2 + WIDTH / 20 * x, HEIGHT / 2 - HEIGHT / 10 * (y + 1), WIDTH / 20, HEIGHT / 10, Color(1, 1, 1));
        break;
      
      case 1:
        drawFillBox(-WIDTH / 2 + WIDTH / 20 * x, HEIGHT / 2 - HEIGHT / 10 * (y + 1), WIDTH / 20, HEIGHT / 10, Color(1, 0, 0));
        break;

      case 2:
        drawFillBox(-WIDTH / 2 + WIDTH / 20 * x, HEIGHT / 2 - HEIGHT / 10 * (y + 1), WIDTH / 20, HEIGHT / 10, Color(0, 1, 0));
        break;

      default:
        drawFillBox(-WIDTH / 2 + WIDTH/20 * x, HEIGHT / 2 - HEIGHT / 10 * (y + 1), WIDTH / 20, HEIGHT / 10, Color(0.5, 0.5, 0.5));
        break;
      }
    }
  }
}