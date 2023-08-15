#pragma once

#include <SDL.h>

#include "types.h"


void render_init(SDL_Window* windows);
void render_begin_frame();
void render_end_frame();
void render_push_cinder(vec2 u, cinder_color c);
void render_cleanup();


