
#include <SDL.h>

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#include "cinders.h"

static cinder cinders[MAX_CINDERS];

static int ORIGIN_X = 600;
static int ORIGIN_Y = 800;

static bool gravity = true;
static uint32_t gravity_value = 1;

static uint32_t lifetime_step = 250;
static uint32_t lifetime = 10000;

static float angle = 90.0f;

void cinder_init() {
	// nothing
}

void cinder_reset(uint32_t index) {
	cinders[index].pos.x = (float)ORIGIN_X - 5 + rand() % 15;
	cinders[index].pos.y = (float)ORIGIN_Y - 2 + rand() % 10;

	cinders[index].vel.x = (-2 + rand() % 5) * 1.0f;
	//cinders[i].vel.x *= -std::cos(degrees_to_radians(angle));

	cinders[index].vel.y = (-7 + rand() % 5) * 1.0f;
	//cinders[i].vel.y *= std::sin(degrees_to_radians(angle));

	cinders[index].color = rand() % 6;
	//cinders[i].color = SDL_Color(255, 0, 0);

	cinders[index].lifetime = 20 + rand() % lifetime;
	//cinders[i].lifetime = 60;

	cinders[index].color_counter = 0;

	cinders[index].gravity_counter = 0;

	// how long it will take cinder to cool
	cinders[index].color_threshold = 4 + rand() % 8;
	// how long it will take for gravity to take effect.
	cinders[index].gravity_threshold = 1 + rand() % 1500;
}

void cinder_init_all() {

	for (uint32_t i = 0; i < MAX_CINDERS; ++i) {

		cinders[i].pos.x = (float)ORIGIN_X - 5 + rand() % 15;
		cinders[i].pos.y = (float)ORIGIN_Y - 2 + rand() % 10;

		cinders[i].vel.x = (-2 + rand() % 5) * 1.0f;
		//cinders[i].vel.x *= -std::cos(degrees_to_radians(angle));

		cinders[i].vel.y = (-7 + rand() % 5) * 1.0f;
		//cinders[i].vel.y *= std::sin(degrees_to_radians(angle));

		cinders[i].color = rand() % 6;
		//cinders[i].color = SDL_Color(255, 0, 0);

		cinders[i].lifetime = 20 + rand() % lifetime;
		//cinders[i].lifetime = 60;

		cinders[i].color_counter = 0;

		cinders[i].gravity_counter = 0;

		// how long it will take cinder to cool
		cinders[i].color_threshold = 4 + rand() % 8;
		// how long it will take for gravity to take effect.
		cinders[i].gravity_threshold = 1 + rand() % 1500;
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

void cinder_gravity_toggle() {
	gravity = !gravity;
}


void cinder_update(float dt) {

	for (int i = 0; i < MAX_CINDERS; ++i) {

		cinders[i].pos.x += cinders[i].vel.x * dt;
		cinders[i].pos.y += cinders[i].vel.y * dt;

		// apply gravity

		if (gravity) {
			cinders[i].gravity_counter++;

			if (cinders[i].gravity_counter >= cinders[i].gravity_threshold) {
				cinders[i].vel.y++;

				cinders[i].gravity_counter = 0;
			}
		}

		cinders[i].lifetime--;

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


/*


int ORIGIN_X = 600;
int ORIGIN_Y = 800;

bool gravity = true;
int gravity_value = 1;

constexpr unsigned int lifetime_step = 250;
unsigned int lifetime = 10000;

float angle = 90.0f;

constexpr float PI = 3.14159265;



void init_cinder(Cinder& cinder) {
	
	cinder.x = ORIGIN_X - 5 + rand() % 15;
	cinder.y = ORIGIN_Y - 2 + rand() % 10;

	cinder.vel_x = (-2 + rand() % 5) * 1.0f;
	//cinder.vel_x *= -std::cos(degrees_to_radians(angle));

	cinder.vel_y = (-7 + rand() % 5) * 1.0f;
	//cinder.vel_y *= std::sin(degrees_to_radians(angle));

	cinder.color = rand() % 6;
	//cinders[i].color = SDL_Color(255, 0, 0);

	cinder.lifetime = 20 + rand() % lifetime;
	//cinders[i].lifetime = 60;

	cinder.color_counter = 0;

	cinder.gravity_counter = 0;

	// how long it will take cinder to cool
	cinder.color_threshold = 4 + rand() % 8;
	// how long it will take for gravity to take effect.
	cinder.gravity_threshhold = 1 + rand() % 1500;

}

void init_all_cinders(Cinders& cinders) {

	for (int i = 0; i < cinders.size(); ++i) {
		init_cinder(cinders[i]);
	}
}

void reset_cinder(Cinder& cinder) {

	init_cinder(cinder);
}

void rotate_left(Cinders& cinders) {

	
	for (int i = 0; i < cinders.size(); ++i) {
		cinders[i].vel_x *= -std::cos(degrees_to_radians(angle));
		cinders[i].vel_y *= std::sin(degrees_to_radians(angle));
	}

	angle -= 2.0f;
	if (angle < 0.0f)
		angle = 360.0f;
}

void rotate_right() {
	angle += 2.0f;
	if (angle > 360.0f)
		angle = 0.0f;
}

void move_x(float amount) {
	ORIGIN_X += amount;
}
void move_y(float amount) {
	ORIGIN_Y += amount;
}

void increase_lifetime() {
	lifetime += lifetime_step;
}

void decrease_lifetime() {
	lifetime -= lifetime_step;

	if (lifetime < 1)
		lifetime += lifetime_step;
}

void toggle_gravity() {
	gravity = !gravity;
}

void move_cinders(Cinders& cinders, double dt) {

	for (int i = 0; i < cinders.size(); ++i) {

		cinders[i].x += cinders[i].vel_x * dt;
		cinders[i].y += cinders[i].vel_y * dt;

		// apply gravity

		if (gravity) {
			cinders[i].gravity_counter++;

			if (cinders[i].gravity_counter >= cinders[i].gravity_threshhold) {
				cinders[i].vel_y++;

				cinders[i].gravity_counter = 0;
			}
		}

		cinders[i].lifetime--;

		if (cinders[i].lifetime <= 0) {
			reset_cinder(cinders[i]);
		}
		
		else if (cinders[i].x <= 0 || cinders[i].x > 1200) {
			reset_cinder(cinders[i]);
		}
		
		else if (cinders[i].y > 800) {
			reset_cinder(cinders[i]);
		}

	}
}

void draw_cinders(SDL_Renderer* renderer, Cinders& cinders) {

	for (int i = 0; i < cinders.size(); ++i) {

		switch (cinders[i].color) {
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

		if (cinders[i].y >= 0 && cinders[i].y < 800) {
			SDL_Rect r = {
				.x = static_cast<int>(cinders[i].x),
				.y = static_cast<int>(cinders[i].y),
				.w = 2,
				.h = 2
			};
			SDL_RenderFillRect(renderer, &r);
		}
	}
}

float degrees_to_radians(float angle) {
	// C++20 has std::numbers::pi
	return angle * PI / 180;
}


*/