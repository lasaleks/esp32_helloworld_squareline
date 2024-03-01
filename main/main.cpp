/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "devices/wt32sc01plus.h"
#include "ui/ui.h"
#include "display.h"

SemaphoreHandle_t xGuiSemaphore;

void ui_reset() {
 lv_label_set_text(ui_lbText, "");
}

void ui_event_click_me(lv_event_t * e);

extern "C" void app_main(void)
{
  printf("Hello world!\n");
  xGuiSemaphore = xSemaphoreCreateMutex();
  //--
  initDisplay();
  initLvgl();

  ui_init();
  ui_reset();

  lv_obj_add_event_cb(ui_btnClickMe, ui_event_click_me, LV_EVENT_CLICKED, NULL);

  while (1) {
      //Delay 1 tick (assumes FreeRTOS tick is 10ms
      vTaskDelay(pdMS_TO_TICKS(10));

      //Try to take the semaphore, call lvgl related function on success 
      if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
          lv_task_handler();
          xSemaphoreGive(xGuiSemaphore);
      }
  }

  vTaskDelete(NULL);
}

///////////////////// FUNCTIONS ////////////////////
void ui_event_click_me(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    //lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        printf("Hello world!\n");
        lv_label_set_text(ui_lbText, "Hello World");
    }
}
