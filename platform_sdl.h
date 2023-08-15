#pragma once

#include <SDL.h>

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>


typedef struct {
	char window_name[64];
	uint32_t width;
	uint32_t height;
} window_info;


void platform_window_setup(window_info* win_info, uint32_t w, uint32_t h, const char* win_name);
void platform_init();
// void platform_video_init();
void platform_pump_events();
// void platform_prepare_frame();
// void platform_end_frame();
void platform_run();
void platform_cleanup();

Uint32 platform_get_ticks();
SDL_Window* platform_get_window();