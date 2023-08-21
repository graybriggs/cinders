
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "input.h"

static const char* button_names[] = {

	[INPUT_KEY_UP] = "UP",
	[INPUT_KEY_DOWN] = "DOWN",
	[INPUT_KEY_LEFT] = "LEFT",
	[INPUT_KEY_RIGHT] = "RIGHT",
	[INPUT_KEY_G] = "G",
	[INPUT_KEY_X] = "X",
	[INPUT_KEY_Z] = "Y"
};



static bool key_bindings[INPUT_BUTTON_MAX];


void input_init() {
	input_clear_all_inputs();
}

void input_set_button_state(button_t button, float state) {
	key_bindings[button];
}

void input_set_button_pressed(button_t button) {

	/*
	if (button < 0 || button > INPUT_BUTTON_MAX) {
		printf("Invaid button press\n");
		return;
	}
	*/

	key_bindings[button] = true;
}

void input_set_button_released(button_t button) {

	//if (button < 0 || button > INPUT_BUTTON_MAX) {
	//	return;
	//}

	key_bindings[button] = false;
}

bool input_state_button(button_t state) {
	return key_bindings[state];
}

void input_clear_all_inputs() {
	memset(key_bindings, 0, sizeof(key_bindings));
}

const char* input_button_name(button_t button) {
	return button_names[button];
}