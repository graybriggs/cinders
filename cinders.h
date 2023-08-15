#pragma once

#include <SDL.h>

#include <stdint.h>
#include <math.h>

#include "types.h"


typedef struct {

	vec2 pos;
	vec2 vel;
	uint32_t lifetime;
	uint32_t color;
	uint32_t color_counter;
	uint32_t color_threshold;
	uint32_t gravity_counter;
	uint32_t gravity_threshold;

	uint32_t current_color;
} cinder;

#define CINDER_WIDTH 2
#define CINDER_HEIGHT 2
#define MAX_CINDERS 512



void cinder_init();
void cinder_reset(uint32_t index);
void cinder_init_all();
void cinder_reset_all();
void cinder_move_x(float amount);
void cinder_move_y(float amount);
void cinder_move(vec2 a);

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

//void cinder_move(Cinders& cinders, double dt);
//void cinder_draw(SDL_Renderer* renderer, Cinders& cinders);


/*

struct Cinder {
	float x;
	float y;
	float vel_x;
	float vel_y;
	int lifetime;
	int color;
	//SDL_Color color;
	// tracks when color will change
	int color_counter;  
	int color_threshold;
	// tracks when gravity will be applied
	int gravity_counter; 
	int gravity_threshhold;

	int current_color;
};

constexpr int MAX_CINDERS = 512;


typedef std::array<Cinder, MAX_CINDERS> Cinders;
//Cinders cinders;


void cinder_init(Cinder& cinder);
void init_all_cinders(Cinders& cinders);

void move_x(float amount);
void move_y(float amount);
void rotate_left(Cinders& cinders);
void rotate_right();
void toggle_gravity();
void increase_lifetime();
void decrease_lifetime();
//void increase_gravity();
//void decrease_gravity();

void move_cinders(Cinders& cinders, double dt);
void draw_cinders(SDL_Renderer* renderer, Cinders& cinders);


float degrees_to_radians(float angle);

*/