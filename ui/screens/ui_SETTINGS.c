// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_SETTINGS_screen_init(void)
{
ui_SETTINGS = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SETTINGS, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image8 = lv_img_create(ui_SETTINGS);
lv_img_set_src(ui_Image8, &ui_img_7_png);
lv_obj_set_width( ui_Image8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Image8, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image8, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image8, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel4 = lv_obj_create(ui_SETTINGS);
lv_obj_set_width( ui_Panel4, 61);
lv_obj_set_height( ui_Panel4, 38);
lv_obj_set_x( ui_Panel4, 0 );
lv_obj_set_y( ui_Panel4, -100 );
lv_obj_set_align( ui_Panel4, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel4, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image5 = lv_img_create(ui_Panel4);
lv_img_set_src(ui_Image5, &ui_img_arrow_png);
lv_obj_set_width( ui_Image5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image5, 0 );
lv_obj_set_y( ui_Image5, -10 );
lv_obj_set_align( ui_Image5, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image5, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label8 = lv_label_create(ui_Panel4);
lv_obj_set_width( ui_Label8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label8, 0 );
lv_obj_set_y( ui_Label8, 9 );
lv_obj_set_align( ui_Label8, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label8,"back");

ui_SETTBACKLIGHT = lv_obj_create(ui_SETTINGS);
lv_obj_set_width( ui_SETTBACKLIGHT, 90);
lv_obj_set_height( ui_SETTBACKLIGHT, 72);
lv_obj_set_x( ui_SETTBACKLIGHT, -54 );
lv_obj_set_y( ui_SETTBACKLIGHT, -34 );
lv_obj_set_align( ui_SETTBACKLIGHT, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SETTBACKLIGHT, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SETTBACKLIGHT, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SETTBACKLIGHT, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_SETTBACKLIGHT, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_SETTBACKLIGHT, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image4 = lv_img_create(ui_SETTBACKLIGHT);
lv_img_set_src(ui_Image4, &ui_img_backl1_png);
lv_obj_set_width( ui_Image4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image4, 0 );
lv_obj_set_y( ui_Image4, -11 );
lv_obj_set_align( ui_Image4, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image4, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image4, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_Image4,220);
lv_obj_set_style_img_recolor(ui_Image4, lv_color_hex(0xFFFFFF), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_Image4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label6 = lv_label_create(ui_SETTBACKLIGHT);
lv_obj_set_width( ui_Label6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label6, 0 );
lv_obj_set_y( ui_Label6, 25 );
lv_obj_set_align( ui_Label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label6,"BACKLIGHT");
lv_obj_set_style_border_color(ui_Label6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Label6, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SETTCLOCK = lv_obj_create(ui_SETTINGS);
lv_obj_set_width( ui_SETTCLOCK, 100);
lv_obj_set_height( ui_SETTCLOCK, 74);
lv_obj_set_x( ui_SETTCLOCK, 51 );
lv_obj_set_y( ui_SETTCLOCK, -37 );
lv_obj_set_align( ui_SETTCLOCK, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_SETTCLOCK, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SETTCLOCK, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SETTCLOCK, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_SETTCLOCK, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_SETTCLOCK, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_SETTCLOCK, lv_color_hex(0xFFFFFF), LV_PART_SCROLLBAR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SETTCLOCK, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_SETTCLOCK, lv_color_hex(0x000000), LV_PART_SCROLLBAR | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_SETTCLOCK, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Label13 = lv_label_create(ui_SETTCLOCK);
lv_obj_set_width( ui_Label13, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label13, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label13, 0 );
lv_obj_set_y( ui_Label13, 14 );
lv_obj_set_align( ui_Label13, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_Label13,"TIME");

ui_CLOCK = lv_img_create(ui_SETTCLOCK);
lv_img_set_src(ui_CLOCK, &ui_img_clock_png);
lv_obj_set_width( ui_CLOCK, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_CLOCK, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_CLOCK, 0 );
lv_obj_set_y( ui_CLOCK, -2 );
lv_obj_set_align( ui_CLOCK, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_CLOCK, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_CLOCK, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_CLOCK, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_CLOCK, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor(ui_CLOCK, lv_color_hex(0xFFFFFF), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_CLOCK, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_Panel4, ui_event_Panel4, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_SETTBACKLIGHT, ui_event_SETTBACKLIGHT, LV_EVENT_ALL, NULL);

}
