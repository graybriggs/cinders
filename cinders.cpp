
#include <cmath>
#include <numbers>
#include <SDL.h>

#include "cinders.h"

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
	cinder.vel_y = (-7 + rand() % 5) * 1.0f;

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
		cinders[i].vel_x--;
		cinders[i].vel_y--;
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
		if (cinders[i].y >= 0 && cinders[i].y < 800) {
			SDL_Rect r;
			r.x = cinders[i].x;
			r.y = cinders[i].y;
			r.w = 2;
			r.h = 2;
			SDL_RenderFillRect(renderer, &r);
		}
	}
}

float angle_to_radians(float angle) {
	// C++20 has std::numbers::pi
	return angle * PI / 180;
}