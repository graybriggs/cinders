

#include "render.h"

static SDL_Renderer* renderer;

void render_init(SDL_Window* window) {
	Uint32 renderer_flags = SDL_RENDERER_ACCELERATED;
	renderer = SDL_CreateRenderer(window, -1, renderer_flags);
	if (renderer == NULL) {
		exit(1);
	}
}

void render_begin_frame() {

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Black
	SDL_RenderClear(renderer);
}

void render_end_frame() {

	SDL_RenderPresent(renderer);
}

void render_cleanup() {
	SDL_DestroyRenderer(renderer);
}