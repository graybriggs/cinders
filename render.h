#pragma once

#include <SDL.h>



void render_init(SDL_Window* windows);
void render_begin_frame();
void render_end_frame();
void render_cleanup();
