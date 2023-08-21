#pragma once

#include <stdbool.h>

typedef enum {
	INPUT_KEY_LEFT = 0,
	INPUT_KEY_RIGHT = 1,
	INPUT_KEY_UP = 2,
	INPUT_KEY_DOWN = 3,
	INPUT_KEY_G = 4,
	INPUT_KEY_X = 5,
	INPUT_KEY_Z = 6,

	INPUT_BUTTON_MAX
} button_t;


void input_init();
void input_set_button_state(button_t button, float state);
void input_set_button_pressed(button_t button);
void input_set_button_released(button_t button);
bool input_state_button(button_t button);
void input_clear_all_inputs();
const char* input_button_name(button_t button);