#ifndef SCREEN_BASE_H
#define SCREEN_BASE_H

#include "utilities.h"
#include "lcd.h"

void init_screen_base(void) ;
void refresh_screen_base(void);
void load_module_base(void);
bool process_record_screen_base(uint16_t keycode, keyrecord_t *record);

void update_dilemma_status(void);
void housekeeping_task_screen_base(void);
void mouse_info_sync_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data);

#endif