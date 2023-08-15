#pragma once

#define PI 3.14159265
#define DEG2RAD(a) a * PI / 180

typedef struct {
	float x;
	float y;
} vec2;

typedef enum {
	WHITE = 0,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	PURPLE,
	CYAN
} cinder_color;