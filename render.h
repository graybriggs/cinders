#pragma once

#include <SDL.h>

static SDL_Renderer* renderer;

void render_init(SDL_Window* window);
void render_begin_frame();
void render_end_frame();
void render_cleanup();