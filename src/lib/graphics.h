#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "common.h"
#include "map.h"

#define WIDTH   15
#define HEIGHT  30

#define SCORE_LEVEL 3
#define SPEED_LEVEL 5

void
display_map(map, const i32, const unsigned char);

#endif // GRAPHICS_H