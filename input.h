#pragma once

#include <stdbool.h>

typedef enum {
	INPUT_KEY_LEFT,
	INPUT_KEY_RIGHT,
	INPUT_KEY_UP,
	INPUT_KEY_DOWN,
	INPUT_KEY_G,

	INPUT_BUTTON_MAX
} button_t;


void input_init();
void input_set_button_state(button_t button, float state);
void input_set_button_pressed(button_t button);
void input_set_button_released(button_t button);
bool input_state(button_t button);
void input_clear_all_inputs();
const char* input_button_name(button_t button);