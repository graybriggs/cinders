

#include "render.h"

void render_init(SDL_Window* window) {
	Uint32 rendererFlags = SDL_RENDERER_ACCELERATED;
	renderer = SDL_CreateRenderer(window, -1, rendererFlags);
}

void render_begin_frame() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
	SDL_RenderClear(renderer);

}

void render_end_frame() {

	SDL_RenderPresent(renderer);
}

void render_cleanup() {
	SDL_DestroyRenderer(renderer);
}