
#define _CRT_SECURE_NO_WARNINGS // for strcpy

#include <SDL.h>

#include "platform_sdl.h"
#include "system.h"

void platform_window_setup(window_info* win_info, uint32_t w, uint32_t h, const char* win_name) {

	strcpy(win_info->window_name, win_name);

	SDL_Window* window = window = SDL_CreateWindow(
		"Particles",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1200, 800,
		SDL_WINDOW_SHOWN
	);

}

void platform_init() {

	app_done = false;

	srand((unsigned int)time(NULL));
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	platform_window_setup(&win_info, 1024, 7698, "Particle demo");
}

void platform_pump_events() {
	// nothing yet
}

void platform_run() {

	
	platform_init();


	while (!app_done) {

		platform_pump_events();
		// platform_prepare_frame(); // nothing
		system_update();
		// platform_end_frame(); // nothing
	}

	system_cleanup();
	platform_cleanup();
}

void platform_cleanup() {

	SDL_DestroyWindow(window);
	SDL_Quit();
}

Uint32 platform_get_ticks() {
	return SDL_GetTicks();
}