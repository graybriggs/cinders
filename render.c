

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

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
	SDL_RenderClear(renderer);
}

void render_push_cinder(vec2 u, cinder_color col) {

		switch (col) {
		case YELLOW:
			SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
			break;
		case RED:
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			break;
		case PURPLE:
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
			break;
		case GREEN:
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			break;
		case WHITE:
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			break;
		}
		
		if (u.y >= 0 && u.y < 800) {
			SDL_Rect r = {
				.x = (Uint32)u.x,
				.y = (Uint32)u.y,
				.w = 2,
				.h = 2
			};
			SDL_RenderFillRect(renderer, &r);
		}
}

void render_end_frame() {

	SDL_RenderPresent(renderer);
}

void render_cleanup() {
	SDL_DestroyRenderer(renderer);
}