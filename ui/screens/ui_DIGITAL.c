// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_DIGITAL_screen_init(void)
{
ui_DIGITAL = lv_obj_create(NULL);
lv_obj_clear_flag( ui_DIGITAL, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image6 = lv_img_create(ui_DIGITAL);
lv_img_set_src(ui_Image6, &ui_img_9_png);
lv_obj_set_width( ui_Image6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Image6, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image6, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image6, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image2 = lv_img_create(ui_DIGITAL);
lv_img_set_src(ui_Image2, &ui_img_step_png);
lv_obj_set_width( ui_Image2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image2, 49 );
lv_obj_set_y( ui_Image2, 60 );
lv_obj_set_align( ui_Image2, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label1 = lv_label_create(ui_DIGITAL);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, 15 );
lv_obj_set_y( ui_Label1, 75 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"1066");

ui_Label2 = lv_label_create(ui_DIGITAL);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2, 2 );
lv_obj_set_y( ui_Label2, 82 );
lv_obj_set_align( ui_Label2, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_Label2,"01 45");
lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xf4d03f), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label2, &ui_font_Cadisone, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label3 = lv_label_create(ui_DIGITAL);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label3, 9 );
lv_obj_set_y( ui_Label3, 56 );
lv_obj_set_align( ui_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label3,"STEPS");

ui_secdot = lv_img_create(ui_DIGITAL);
lv_img_set_src(ui_secdot, &ui_img_sec_dot_png);
lv_obj_set_width( ui_secdot, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_secdot, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_secdot, 0 );
lv_obj_set_y( ui_secdot, -107 );
lv_obj_set_align( ui_secdot, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_secdot, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_secdot, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_pivot(ui_secdot,4,111);

lv_obj_add_event_cb(ui_DIGITAL, ui_event_DIGITAL, LV_EVENT_ALL, NULL);

}
