#pragma once

#include <SDL.h>

#include "cinders.h"
#include "types.h"


void render_init(SDL_Window* windows);
void render_begin_frame();
void render_end_frame();
void render_push_cinder(cinder cinder);
void render_cleanup();


