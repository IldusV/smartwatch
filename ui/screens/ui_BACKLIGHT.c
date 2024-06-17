// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "../ui.h"

void ui_BACKLIGHT_screen_init(void)
{
ui_BACKLIGHT = lv_obj_create(NULL);
lv_obj_clear_flag( ui_BACKLIGHT, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Image9 = lv_img_create(ui_BACKLIGHT);
lv_img_set_src(ui_Image9, &ui_img_7_png);
lv_obj_set_width( ui_Image9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image9, -1 );
lv_obj_set_y( ui_Image9, 0 );
lv_obj_set_align( ui_Image9, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image9, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image9, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Slider1 = lv_slider_create(ui_BACKLIGHT);
lv_slider_set_value( ui_Slider1, 0, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Slider1)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Slider1, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_Slider1, 150);
lv_obj_set_height( ui_Slider1, 15);
lv_obj_set_x( ui_Slider1, 0 );
lv_obj_set_y( ui_Slider1, -21 );
lv_obj_set_align( ui_Slider1, LV_ALIGN_CENTER );


ui_Slider2 = lv_slider_create(ui_BACKLIGHT);
lv_slider_set_range(ui_Slider2, 5,60);
lv_slider_set_value( ui_Slider2, 0, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Slider2)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Slider2, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_Slider2, 150);
lv_obj_set_height( ui_Slider2, 15);
lv_obj_set_x( ui_Slider2, 0 );
lv_obj_set_y( ui_Slider2, 47 );
lv_obj_set_align( ui_Slider2, LV_ALIGN_CENTER );


ui_Label4 = lv_label_create(ui_BACKLIGHT);
lv_obj_set_width( ui_Label4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label4, 0 );
lv_obj_set_y( ui_Label4, -40 );
lv_obj_set_align( ui_Label4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label4,"BRIGHTNESS");

ui_Label5 = lv_label_create(ui_BACKLIGHT);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label5, 0 );
lv_obj_set_y( ui_Label5, 28 );
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"TIMEOUT");

ui_Panel5 = lv_obj_create(ui_BACKLIGHT);
lv_obj_set_width( ui_Panel5, 61);
lv_obj_set_height( ui_Panel5, 38);
lv_obj_set_x( ui_Panel5, 0 );
lv_obj_set_y( ui_Panel5, -100 );
lv_obj_set_align( ui_Panel5, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel5, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Panel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_Panel5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_Panel5, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Image7 = lv_img_create(ui_Panel5);
lv_img_set_src(ui_Image7, &ui_img_arrow_png);
lv_obj_set_width( ui_Image7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Image7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Image7, 0 );
lv_obj_set_y( ui_Image7, -10 );
lv_obj_set_align( ui_Image7, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Image7, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Image7, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Label9 = lv_label_create(ui_Panel5);
lv_obj_set_width( ui_Label9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label9, 0 );
lv_obj_set_y( ui_Label9, 9 );
lv_obj_set_align( ui_Label9, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label9,"back");

ui_Label7 = lv_label_create(ui_BACKLIGHT);
lv_obj_set_width( ui_Label7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label7, 0 );
lv_obj_set_y( ui_Label7, -5 );
lv_obj_set_align( ui_Label7, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label7,"0");

ui_Label10 = lv_label_create(ui_BACKLIGHT);
lv_obj_set_width( ui_Label10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label10, 0 );
lv_obj_set_y( ui_Label10, 64 );
lv_obj_set_align( ui_Label10, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label10,"5");
lv_obj_set_style_text_font(ui_Label10, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_Image7, ui_event_Image7, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_Panel5, ui_event_Panel5, LV_EVENT_ALL, NULL);

}
