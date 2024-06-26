// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_MENU_screen_init(void)
{
ui_MENU = lv_obj_create(NULL);
lv_obj_clear_flag( ui_MENU, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_bgmenu = lv_img_create(ui_MENU);
lv_img_set_src(ui_bgmenu, &ui_img_7_png);
lv_obj_set_width( ui_bgmenu, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_bgmenu, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_bgmenu, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_bgmenu, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_bgmenu, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Panel1 = lv_obj_create(ui_MENU);
lv_obj_set_width( ui_Panel1, 71);
lv_obj_set_height( ui_Panel1, 72);
lv_obj_set_x( ui_Panel1, -53 );
lv_obj_set_y( ui_Panel1, -29 );
lv_obj_set_align( ui_Panel1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel1, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xFFFFFF), LV_PART_SCROLLBAR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel1, 0, LV_PART_SCROLLBAR| LV_STATE_DEFAULT);

ui_Image3 = lv_img_create(ui_Panel1);
lv_img_set_src(ui_Image3, &ui_img_gear_png);
lv_obj_set_width( ui_Image3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image3, -6 );
lv_obj_set_y( ui_Image3, -14 );
lv_obj_set_align( ui_Image3, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_Image3, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_img_recolor(ui_Image3, lv_color_hex(0xFFFFFF), LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_img_recolor_opa(ui_Image3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label12 = lv_label_create(ui_Panel1);
lv_obj_set_width( ui_Label12, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label12, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label12, 0 );
lv_obj_set_y( ui_Label12, 9 );
lv_obj_set_align( ui_Label12, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_Label12,"SETTINGS");

ui_Label11 = lv_label_create(ui_MENU);
lv_obj_set_width( ui_Label11, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label11, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label11, 0 );
lv_obj_set_y( ui_Label11, 15 );
lv_obj_set_align( ui_Label11, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label11,"MENU");
lv_obj_set_style_text_letter_space(ui_Label11, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_line_space(ui_Label11, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Label11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label11, &lv_font_montserrat_18, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_bgmenu, ui_event_bgmenu, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Panel1, ui_event_Panel1, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_MENU, ui_event_MENU, LV_EVENT_ALL, NULL);

}
