
#define _CRT_SECURE_NO_WARNINGS // for strcpy

#include <SDL.h>

#include "platform_sdl.h"
#include "system.h"

static SDL_Window* window = NULL;
static window_info win_info = { 0 };
static bool app_done = false;
static SDL_Event event;

void platform_window_setup(window_info* win_info, uint32_t w, uint32_t h, const char* win_name) {

	strcpy(win_info->window_name, win_name);

	window = SDL_CreateWindow(
		win_info->window_name,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1200, 800,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) {
		exit(1);
	}
}

void platform_init() {

	app_done = false;

	srand((unsigned int)time(NULL));
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	platform_window_setup(&win_info, 1024, 768, "Particle demo");
}

void platform_pump_events() {

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT)
			app_done = true;
	}

	// nothing yet
}

void platform_run() {

	platform_init();
	system_init();

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

SDL_Window* platform_get_window() {
	return window;
}