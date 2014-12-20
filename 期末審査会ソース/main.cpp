#include "common.h"

// アプリウインドウの準備
AppEnv app_env(Window::WIDTH, Window::HEIGHT,
  false, false);

int main() {
  // 画像の呼び出し
  Texture num("res/png/number.png"); // 数字
  Texture board("res/png/board.png"); // リサイクル標識
  Texture title("res/png/title.png");        // タイトル画面(仮)
  Texture result("res/png/result.png");  // リザルト画面(仮)

  int game_mode = 0;

  // クラスの宣言
  Square square;

  while (app_env.isOpen()) {

    square.Update(app_env); // オブジェクトの位置情報などをループの頭で更新
    // 描画準備
    app_env.setupDraw();

    // 簡易コマンド
    if (app_env.isPushKey('A')) game_mode = 0;
    if (app_env.isPushKey('S')) game_mode = 1;
    if (app_env.isPushKey('D')) game_mode = 2;

    switch (game_mode){
    case 0:
      disp_Title(title);
      break;

    case 1:
      square.board(board);      // リサイクル標識の表示
      square.Countdown();       // オブジェクトが出てくるタイミングを調整
      square.Draw();                 // オブジェクトを表示
      square.disp_Score(num); // スコア表示用
      square.recycle_Score(num); // リサイクルポイント表示用
      square.Pause(app_env);   // ポーズ機能
      square.Limit(num);           // 制限時間の表示・処理
      //    drawMapChip();
      break;

    case 2:
      disp_Result(result);
      break;

    }
    // 画面更新
    app_env.update();
  }
}
