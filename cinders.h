#pragma once

#include <SDL.h>

#include <stdint.h>
#include <math.h>

#include "types.h"


typedef struct {

	vec2 pos;
	vec2 vel;
	uint32_t lifetime;
	cinder_color color;
	uint32_t color_counter;
	uint32_t color_threshold;
	uint32_t gravity_counter;
	uint32_t gravity_threshold;

	uint32_t current_color;
} cinder;

#define CINDER_WIDTH 2
#define CINDER_HEIGHT 2
#define CINDERS_MAX 512



void cinder_init();
void cinder_reset(uint32_t index);
void cinder_init_all();
void cinder_reset_all();
void cinder_move_x(float amount);
void cinder_move_y(float amount);
void cinder_move(vec2 a);
void cinder_rotate_clockwise();
void cinder_rotate_counter_clockwise();
void cinder_gravity_toggle();
void cinder_handle_input();

//void cinder_rotate_left();
//void cinder_rotate_right();
//void cinder_toggle_gravity();
//void cinder_increase_lifetime();
//void cinder_decrease_lifetime();

void cinder_update(float dt);
void cinder_render();

cinder cinder_get(uint32_t index);
//void cinder_increase_gravity();
//void cinder_decrease_gravity();

