
#include <ctime>

#include <SDL.h>

//#include "particle.h"
//#include "particle_manager.h"

#include "cinders.h"

int main(int argc, char* args[]) {
	srand(time(nullptr));
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	SDL_Window* window = window = SDL_CreateWindow(
		"Particles",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1200, 800,
		SDL_WINDOW_SHOWN
	);

	Uint32 rendererFlags = SDL_RENDERER_ACCELERATED;
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	bool done = false;
	SDL_Event event;


	const float fps = 60.0f;
	const float dt = 1.0f / fps; // fixed timestep of 1/60th of a second
	float accumulator = 0.0f;
	float frameStart = SDL_GetTicks();

	//init_cinders();

	Cinders cinders;
	init_all_cinders(cinders);

	int col = 0;
	float xpos = 600.0f;

	while (!done) {
		const float currentTime = static_cast<float>(SDL_GetTicks());
		accumulator += currentTime - frameStart;
		frameStart = currentTime;

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				done = true;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					done = true;
				}

				if (event.key.keysym.sym == SDLK_SPACE) {
					//pm.go();
					col++;
				}
				
				if (event.key.keysym.sym == SDLK_LEFT)
					move_x(-20);
				else if (event.key.keysym.sym == SDLK_RIGHT)
					move_x(20);
				else if (event.key.keysym.sym == SDLK_UP)
					move_y(-20);
				else if (event.key.keysym.sym == SDLK_DOWN)
					move_y(20);

				if (event.key.keysym.sym == SDLK_g) {
					toggle_gravity();
				}
				else if (event.key.keysym.sym == SDLK_t) {
					//decrease_gravity();
				}
				else if (event.key.keysym.sym == SDLK_y) {
					//increase_gravity();
				}
				else if (event.key.keysym.sym == SDLK_z) {
					// rotate anti-clockwise
					rotate_left(cinders);
				}
				else if (event.key.keysym.sym == SDLK_x) {
					// rotate clockwise
					rotate_right();
				}
			}
		}

		if (accumulator > 0.2f)
			accumulator = 0.2f;

		while (accumulator > dt) {
			//pm.logic(dt);
			move_cinders(cinders, dt);
			accumulator -= dt;
		}


		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black
		SDL_RenderClear(renderer);

		switch (col) {
		case 0:
			SDL_SetRenderDrawColor(renderer, 25, 0, 255, 255);
			break;
		case 1:
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			break;
		case 2:
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
			break;
		case 3:
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			break;
		case 4:
			SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
			break;
		case 5:
			SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
			break;
		case 6:
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			break;
		}

		if (col > 6)
			col = 0;

		draw_cinders(renderer, cinders);
		
		//pm.render(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//p.render(renderer);

		SDL_RenderPresent(renderer);
	}
	SDL_Quit();

	return 0;
}