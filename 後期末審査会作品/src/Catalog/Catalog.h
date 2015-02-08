#pragma once
#include "../common.h"

class Catalog{
private:
  Vec2f mouse_pos;
  int page_no;
  float clear;
  bool clear_switch;

  enum{
    Page0, Page1, Page2, Page3, Page4,
    Page5, Page6, Page7, Page8, Page9,

    Page10, Page11, Page12, Page13, Page14,
    Page15, Page16, Page17, Page18, Page19,
    
    Page20, Page21, Page22, Page23, Page24,
    Page25, Page26, Page27, Page28, Page29,
    
    Page30, Page31, Page32, Page33, Page34,
    Page35, Page36, Page37, Page38, Page39,
  
    Page40, Page41, Page42, Page43, Page44,
    Page45, Page46, Page47, Page48, Page49,
  
    Page50, Page51, Page52, Page53, Page54,
    Page55, Page56, Page57, Page58, Page59,

    Page60, Page61, Page62, Page63, Page64,
    Page65, Page66, Page67, Page68, Page69,

    Page70, Page71, Page72, Page73, Page74,
    Page75, Page76, Page77, Page78, Page79,

    Page80, Page81, Page82, Page83, Page84,
    Page85, Page86, Page87, Page88, Page89,

    Page90, TEX_NUM    /*TEX_NUM ��for���̃��[�v�����p*/
  };
  Texture* Page_List[TEX_NUM];
  Texture before;
  Texture next;
  Texture back_log;

  Media next_page;
  Media before_page;

public:
  Catalog();
  void Draw_Catalog(AppEnv&);
  void Catalog_Update(AppEnv&, int&);
  bool Inside(AppEnv&, float, float, float, float, float, float);
};