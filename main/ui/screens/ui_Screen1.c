// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0xBABABA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_btnClickMe = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_btnClickMe, 240);
    lv_obj_set_height(ui_btnClickMe, 50);
    lv_obj_set_x(ui_btnClickMe, -3);
    lv_obj_set_y(ui_btnClickMe, 3);
    lv_obj_set_align(ui_btnClickMe, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_btnClickMe, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_btnClickMe, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label1 = lv_label_create(ui_btnClickMe);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, 1);
    lv_obj_set_y(ui_Label1, 0);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "Click Me");

    ui_lbText = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_lbText, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_lbText, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_lbText, -12);
    lv_obj_set_y(ui_lbText, -66);
    lv_obj_set_align(ui_lbText, LV_ALIGN_CENTER);

}
