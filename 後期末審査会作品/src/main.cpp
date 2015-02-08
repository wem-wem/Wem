#include "common.h"
#include "Result/Result.h"
#include "Title/Title.h"
#include "Shop/Shop.h"
#include "Season/Season.h"
#include "Catalog/Catalog.h"

// アプリウインドウの準備
AppEnv app_env(Window::WIDTH, Window::HEIGHT,
  false, false);

int main() {  
  // 変数の宣言--------------------------------------------------------------------------------
  int game_mode = 0; // タイトル・本編・リザルト・ショップの切り替え

  int stage_no = 0;      // ステージ切り替え用

  int score = 0;            // 各クラス間での数値のやり取りを
  int bad_score = 0;    // メインのグローバル変数で扱う。
  int total_score = 0;
  int obj_score = 0;

  /*************************************************/
  /* int型の限界値だと表示しきれないため、long long int型を使用 */
  /************************************************/
  long long int money = 0;  // プレイヤーの所持金(ステージ毎の"total_score"を加算していく)

  // アイテム購入スイッチ-----------------------------------------------------------------------
  bool double_recycle = false;
  bool quick = false;
  bool catalog_switch = false;

  // クラスの宣言--------------------------------------------------------------------------------
  Square square;
  Title title;
  Result result;
  Shop shop;
  Season season;
  Catalog catalog;

  while (app_env.isOpen()) {
    square.Update(app_env, stage_no, quick, double_recycle); // オブジェクトの位置情報などをループの頭で更新

    // 描画準備
    app_env.setupDraw();

    // 簡易コマンド
    // タイトルへ(他ＢＧＭ停止)
    if (app_env.isPushKey('A')){
      game_mode = TITLE;
      title.Title_Bgm.play();
      season.Season_Bgm.stop();
      square.Game_Bgm.stop();
      square.Countdown_Se.stop();
      square.Time_Up.stop();
      result.Wadaiko1.stop();
      result.Wadaiko2.stop();
      shop.Shop_Bgm.stop();
    }

    // ステージ名の表示(他ＢＧＭ停止)
    if (app_env.isPushKey('S')){
      game_mode = SEASON;
      season.Season_Bgm.play();
      title.Title_Bgm.stop();
      square.Game_Bgm.stop();
      square.Countdown_Se.stop();
      square.Time_Up.stop();
      result.Wadaiko1.stop();
      result.Wadaiko2.stop();
      shop.Shop_Bgm.stop();
    }

    // ゲーム本編へ(他ＢＧＭ停止)
    if (app_env.isPushKey('D')){
      game_mode = GAME;
      square.CDtimer = 4 * 60;
      square.Countdown_Se.play();
      title.Title_Bgm.stop();
      season.Season_Bgm.stop();
      result.Wadaiko1.stop();
      result.Wadaiko2.stop();
      shop.Shop_Bgm.stop();
    }

    // リザルト画面へ(他ＢＧＭ停止)
    if (app_env.isPushKey('F')){
      game_mode = RESULT; 
      result.result_timer = 2 * 60;
      title.Title_Bgm.stop();
      season.Season_Bgm.stop();
      square.Game_Bgm.stop();
      square.Countdown_Se.stop();
      square.Time_Up.stop();
      shop.Shop_Bgm.stop();
    }

    // ショップ画面へ(他ＢＧＭ停止)
    if (app_env.isPushKey('G')){
      game_mode = SHOP;
      shop.Shop_Bgm.play();
      title.Title_Bgm.stop();
      season.Season_Bgm.stop();
      square.Game_Bgm.stop();
      square.Countdown_Se.stop();
      square.Time_Up.stop();
      result.Wadaiko1.stop();
      result.Wadaiko2.stop();
    }

    // ステージ切り替え
    {
      if (app_env.isPushKey('[')){
        if (stage_no < 9){
          stage_no += 1;
        }
        else if (stage_no == 9){
          stage_no = 0;
        }
      }

      if (app_env.isPushKey(']')){
        if (stage_no > 0){
          stage_no -= 1;
        }
        else if (stage_no == 0){
          stage_no = 9;
        }
      }

    }

    // 所持金の増加と、桁あふれ防止
    if (app_env.isPushKey('M')){
      money += 1000000000; 
    }
    if (money >= 10000000000){
      money = 9999999999;
    }

    if (app_env.isPushKey('C')){
      catalog_switch = true;
    }

    switch (game_mode){
      // ゲーム終了----------------------------------------------------------------------------
    case -1:
      return 0;

      // タイトル画面----------------------------------------------------------------------------
    case TITLE:
      title.Disp_Title(app_env, game_mode);
      title.Draw_Catalog(app_env, catalog_switch, game_mode);
      title.Black_Out(game_mode);
      break;

      // ステージ(シーズン)表示----------------------------------------------------------------------------
    case SEASON:
      season.Draw_Background(stage_no);
      season.Start_Game(app_env, game_mode);
      break;

      // ゲーム本編----------------------------------------------------------------------------
    case GAME:
      square.Background(quick);      // 背景
      square.Countdown(quick);       // オブジェクトが出てくるタイミングを調整
      square.Draw(stage_no);                         // オブジェクトを表示
      square.disp_Score();                // スコア表示用
      square.recycle_Score();           // リサイクルポイント表示用
      square.Limit(app_env, game_mode, stage_no, score,      // 制限時間の表示・処理
                           bad_score, total_score, obj_score,
                           double_recycle, quick);
      square.Board();                       // コンベアの蓋を表示
      square.Pause(app_env, game_mode, stage_no, money);   // ポーズ機能
      square.Count_Down();            // ゲーム開始前のカウントダウン
      break;

      // リザルト画面----------------------------------------------------------------------------
    case RESULT:
      result.disp_Result(app_env, square.count_stop, game_mode);
      result.disp_Score(score, bad_score, total_score, obj_score);
      result.Black_Out(game_mode, money);
      break;

      // ショップ画面----------------------------------------------------------------------------
    case SHOP:
      shop.Disp_Background(app_env);
      shop.Draw_Item(app_env, money, double_recycle, quick, catalog_switch);
      shop.Disp_Money(money);
      shop.Next_Stage(game_mode);
      break;

      // 生産目録画面----------------------------------------------------------------------------
    case CATALOG:
      catalog.Draw_Catalog(app_env);
      catalog.Catalog_Update(app_env, game_mode);
      break;
    }
    // 画面更新
    app_env.update();
  }
}
