#ifndef _DISPLAY_H
#define _DISPLAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <lvgl.h>
#include <esp_system.h>

#define LV_TICK_PERIOD_MS 1

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

void initDisplay();

void initLvgl();


#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
