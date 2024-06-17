// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.0
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl/lvgl.h"

#include "ui_helpers.h"
#include "components/ui_comp.h"
#include "components/ui_comp_hook.h"
#include "ui_events.h"

void min_Animation( lv_obj_t *TargetObject, int delay);
void hour_Animation( lv_obj_t *TargetObject, int delay);
void sec_Animation( lv_obj_t *TargetObject, int delay);
void opac_Animation( lv_obj_t *TargetObject, int delay);
void sec_dot_Animation( lv_obj_t *TargetObject, int delay);
// SCREEN: ui_ANALOG
void ui_ANALOG_screen_init(void);
void ui_event_ANALOG( lv_event_t * e);
extern lv_obj_t *ui_ANALOG;
extern lv_obj_t *ui_Backg;
extern lv_obj_t *ui_Date;
extern lv_obj_t *ui_weather_group_1;
extern lv_obj_t *ui_Image1;
extern lv_obj_t *ui_Temp;
void ui_event_hour_group( lv_event_t * e);
extern lv_obj_t *ui_hour_group;
extern lv_obj_t *ui_hour;
extern lv_obj_t *ui_minute;
extern lv_obj_t *ui_sec;
// SCREEN: ui_DIGITAL
void ui_DIGITAL_screen_init(void);
void ui_event_DIGITAL( lv_event_t * e);
extern lv_obj_t *ui_DIGITAL;
extern lv_obj_t *ui_Image6;
extern lv_obj_t *ui_Image2;
extern lv_obj_t *ui_Label1;
extern lv_obj_t *ui_Label2;
extern lv_obj_t *ui_Label3;
extern lv_obj_t *ui_secdot;
// SCREEN: ui_MENU
void ui_MENU_screen_init(void);
void ui_event_MENU( lv_event_t * e);
extern lv_obj_t *ui_MENU;
void ui_event_bgmenu( lv_event_t * e);
extern lv_obj_t *ui_bgmenu;
void ui_event_Panel1( lv_event_t * e);
extern lv_obj_t *ui_Panel1;
extern lv_obj_t *ui_Image3;
extern lv_obj_t *ui_Label12;
extern lv_obj_t *ui_Label11;
// SCREEN: ui_SETTINGS
void ui_SETTINGS_screen_init(void);
extern lv_obj_t *ui_SETTINGS;
extern lv_obj_t *ui_Image8;
void ui_event_Panel4( lv_event_t * e);
extern lv_obj_t *ui_Panel4;
extern lv_obj_t *ui_Image5;
extern lv_obj_t *ui_Label8;
void ui_event_SETTBACKLIGHT( lv_event_t * e);
extern lv_obj_t *ui_SETTBACKLIGHT;
extern lv_obj_t *ui_Image4;
extern lv_obj_t *ui_Label6;
extern lv_obj_t *ui_SETTCLOCK;
extern lv_obj_t *ui_Label13;
extern lv_obj_t *ui_CLOCK;
// SCREEN: ui_BACKLIGHT
void ui_BACKLIGHT_screen_init(void);
extern lv_obj_t *ui_BACKLIGHT;
extern lv_obj_t *ui_Image9;
extern lv_obj_t *ui_Slider1;
extern lv_obj_t *ui_Slider2;
extern lv_obj_t *ui_Label4;
extern lv_obj_t *ui_Label5;
void ui_event_Panel5( lv_event_t * e);
extern lv_obj_t *ui_Panel5;
void ui_event_Image7( lv_event_t * e);
extern lv_obj_t *ui_Image7;
extern lv_obj_t *ui_Label9;
extern lv_obj_t *ui_Label7;
extern lv_obj_t *ui_Label10;
void ui_event____initial_actions0( lv_event_t * e);
extern lv_obj_t *ui____initial_actions0;


LV_IMG_DECLARE( ui_img_8_png);   // assets/8.png
LV_IMG_DECLARE( ui_img_weather_png);   // assets/weather.png
LV_IMG_DECLARE( ui_img_clockwise_hour_re_png);   // assets/clockwise_hour_re.png
LV_IMG_DECLARE( ui_img_clockwise_min_png);   // assets/clockwise_min.png
LV_IMG_DECLARE( ui_img_clockwise_sec_png);   // assets/clockwise_sec.png
LV_IMG_DECLARE( ui_img_9_png);   // assets/9.png
LV_IMG_DECLARE( ui_img_step_png);   // assets/step.png
LV_IMG_DECLARE( ui_img_sec_dot_png);   // assets/sec_dot.png
LV_IMG_DECLARE( ui_img_7_png);   // assets/7.png
LV_IMG_DECLARE( ui_img_gear_png);   // assets/gear.png
LV_IMG_DECLARE( ui_img_arrow_png);   // assets/arrow.png
LV_IMG_DECLARE( ui_img_backl1_png);   // assets/backl1.png
LV_IMG_DECLARE( ui_img_clock_png);   // assets/clock.png
LV_IMG_DECLARE( ui_img_1_png);   // assets/1.png
LV_IMG_DECLARE( ui_img_2_png);   // assets/2.png
LV_IMG_DECLARE( ui_img_3_png);   // assets/3.png
LV_IMG_DECLARE( ui_img_4_png);   // assets/4.png
LV_IMG_DECLARE( ui_img_5_png);   // assets/5.png
LV_IMG_DECLARE( ui_img_6_png);   // assets/6.png
LV_IMG_DECLARE( ui_img_bg3_png);   // assets/bg3.png
LV_IMG_DECLARE( ui_img_sm_5afad9686fe48_png);   // assets/sm_5afad9686fe48.png


LV_FONT_DECLARE( ui_font_Cadisone);
LV_FONT_DECLARE( ui_font_RobotoRegular);


void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif