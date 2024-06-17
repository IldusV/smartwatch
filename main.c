#include "lvgl/lvgl.h"
//#include "lvgl/demos/lv_demos.h"
//#include "lv_demos/lv_demo.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
//#include "lv_drv_conf.h"
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>
#include "lv_conf.h"
#define DISP_BUF_SIZE (240 * 240)


void *tick_thread(void *data)
{
	(void) data;	// Suppress warnings.

	// Call lv_tick_inc() periodically to inform LVGL about how much time has elapsed.
	while (1)
	{
		usleep(5000);
//		lv_tick_inc(5);
	}
}

/*Image declare*/
LV_IMG_DECLARE(tux);

// void lv_show_img(lv_obj_t * img,const lv_img_dsc_t img_dat){
//     lv_obj_clean(img);
//     lv_img_set_src(img, &img_dat);
//     lv_obj_center(img);
// }

int main(void)
{
    pthread_t lvTickThread;
	int rc;
    
    LV_LOG_USER("entered main()\n");
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = 240;
    disp_drv.ver_res    = 240;
    lv_disp_drv_register(&disp_drv);

    evdev_init();
    static lv_indev_drv_t indev_drv_1;
    lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
    indev_drv_1.type = LV_INDEV_TYPE_POINTER;

    // /*This function will be called periodically (by the library) to get the mouse position and state*/
    indev_drv_1.read_cb = evdev_read;
    lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

    /*Set a cursor for the mouse*/
    // LV_IMG_DECLARE(mouse_cursor_icon)
    //lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
    // lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
    //lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/
    backl_init();
    // lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x2080bb), 0);
    /*Create a Demo*/
    //lv_demo_widgets();
    //lv_example_spinner_1();
    //lv_example_btn_1();
    //lv_example_meter_1();
    //lv_example_slider_1();
    ui_init();
    backl_set(80);
    //lv_example_img_4();
	//lv_example_bmp_1();
    //rc = pthread_create(&lvTickThread, NULL, tick_thread, NULL);
    /*Handle LitlevGL tasks (tickless mode)*/
    //lv_example_tileview_1();
    //lv_example_animimg_1();
    //lv_example_calendar_1();
    //lv_example_btnmatrix_1();
    //lv_example_scroll_6();
    /*Show an image*/
    //lv_obj_t *scr = lv_disp_get_scr_act(NULL);
    //lv_obj_t *img = lv_img_create(scr);
    // //lv_show_img(img,background_gorilla_r);
    // lv_obj_clean(img);
    // lv_img_set_src(img, &tux);
    // //lv_obj_center(img);
    // lv_obj_center(img);
    // lv_example_label_2();

    while(1) {
        lv_timer_handler();
        usleep(1000);
    }

    return 0;
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
