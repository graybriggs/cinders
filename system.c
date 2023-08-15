
#include <stdint.h>

#include "platform_sdl.h"
#include "render.h"
#include "system.h"


static float accumulator;
static float frame_start;

//static const float frames_per_second = 60.0f;
#define FRAMES_PER_SECOND 60.0f
static const float dt = 1.0f / FRAMES_PER_SECOND; // fixed timestep of 1/60th of a second
static uint32_t updates_per_second;


void system_init() {

	render_init(window);

	accumulator = 0.0f;
	frame_start = platform_get_ticks();

}


void system_update() {
	const float currentTime = platform_get_ticks();
	accumulator += currentTime - frame_start;
	frame_start = currentTime;
	updates_per_second = 0;
	//


	if (accumulator > 0.2f)
		accumulator = 0.2f;

	while (accumulator > dt) {

		//move_cinders(cinders, dt);

		accumulator -= dt;
		++updates_per_second;
	}


	// render_begin_frame();

	// update()

	// render_end_frame();

	// input_clear();

}


void system_cleanup() {
	render_cleanup();
}