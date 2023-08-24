
#include <SDL.h>

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#include "cinders.h"

////////////////
#include "input.h"

////////////////

static cinder cinders[CINDERS_MAX];

static float ORIGIN_X = 600;
static float ORIGIN_Y = 800;

static bool gravity = true;
static uint32_t gravity_value = 1;

static uint32_t lifetime_step = 1;
static uint32_t lifetime = 99000;

static uint32_t particles_spread = 5;

static float angle = 0.0f;
#define PI 3.14159265
#define DEG2RAD(a)(a * (PI / 180))

void cinder_init() {
	// nothing
}

void cinder_reset(uint32_t index) {
	cinders[index].pos.x = (float)ORIGIN_X - 5 + rand() % 8;
	cinders[index].pos.y = (float)ORIGIN_Y - 2 + rand() % 5;
	cinders[index].width = 2;
	cinders[index].height = 2;

	//int velx = (-3 + rand() % 5) * 1.0f;
	int velx = (-3 + rand() % 8) * 1.0f;
	int vely = (-7 + rand() % 5) * 1.01f;

	float ca = (float)cos(DEG2RAD(angle));
	float sa = (float)sin(DEG2RAD(angle));
	cinders[index].vel.x = ca * velx - sa * vely;
	cinders[index].vel.y = sa * velx + ca * vely;

	//cinders[index].color = RED;
	cinders[index].color = rand() % 6;
	cinders[index].lifetime = 20 + rand() % lifetime;

	cinders[index].color_counter = 0;
	cinders[index].color_threshold = 4 + rand() % 8;

	cinders[index].gravity_counter = 0;
	// how long it will take for gravity to take effect.
	cinders[index].gravity_threshold = 1 + rand() % 1500;
}

void cinder_init_all() {

	for (uint32_t i = 0; i < CINDERS_MAX; ++i) {
		cinder_reset(i);
	}
}

void cinder_reset_all() {

	cinder_init_all();
}

void cinder_move_x(float amount) {
	ORIGIN_X += amount;
}

void cinder_move_y(float amount) {
	ORIGIN_Y += amount;
}

void cinder_move(vec2 a) {
	ORIGIN_X += a.x;
	ORIGIN_Y += a.y;
}

void cinder_rotate_clockwise() {

	angle += 0.1f;
	if (angle > 360 - 1)
		angle = 0;
}

void cinder_rotate_counter_clockwise() {

	angle -= 0.1f;
	if (angle < 0)
		angle = 360 - 1;
}

void cinder_gravity_toggle() {
	gravity = !gravity;
}

void cinder_handle_input() {
	if (input_state_button(INPUT_KEY_LEFT)) {
		cinder_move_x(-0.1);
	}
	else if (input_state_button(INPUT_KEY_RIGHT)) {
		cinder_move_x(0.1);
	}
	else if (input_state_button(INPUT_KEY_UP)) {
		cinder_move_y(-0.1);
	}
	else if (input_state_button(INPUT_KEY_DOWN)) {
		cinder_move_y(0.1);
	}
	else if (input_state_button(INPUT_KEY_G)) {
		//cinder_gravity_toggle();
		gravity = false;
	}
	else if (input_state_button(INPUT_KEY_H)) {
		//cinder_gravity_toggle();
		gravity = true;
	}
	else if (input_state_button(INPUT_KEY_X)) {
		cinder_rotate_clockwise();
	}
	else if (input_state_button(INPUT_KEY_Z)) {
		cinder_rotate_counter_clockwise();
	}
}

void cinder_update(float dt) {

	cinder_handle_input();

	for (int i = 0; i < CINDERS_MAX; ++i) {

		cinders[i].pos.x += cinders[i].vel.x * dt;
		cinders[i].pos.y += cinders[i].vel.y * dt;

		// apply gravity

		if (gravity) {
			cinders[i].gravity_counter++;

			if (cinders[i].gravity_counter >= cinders[i].gravity_threshold) {
				cinders[i].vel.y += 0.8f;

				cinders[i].gravity_counter = 0;
			}
		}

		cinders[i].lifetime -= lifetime_step;

		if (cinders[i].lifetime <= 0) {
			cinder_reset(i);
		}

		else if (cinders[i].pos.x <= 0 || cinders[i].pos.x > 1200) {
			cinder_reset(i);
		}

		else if (cinders[i].pos.y > 800) {
			cinder_reset(i);
		}

	}
}

cinder cinder_get(uint32_t index) {
	return cinders[index];
}
