#pragma once

#include <algorithm>
#include <array>
#include <cstdlib>
#include <vector>

#include <SDL.h>

struct Cinder {
	float x;
	float y;
	float vel_x;
	float vel_y;
	int lifetime;
	SDL_Color color;
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


void init_cinder(Cinder& cinder);
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


float angle_to_radians(float angle);