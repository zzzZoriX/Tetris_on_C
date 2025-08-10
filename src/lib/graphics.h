#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "common.h"
#include "figure.h"
#include "map.h"

#define WIDTH   15
#define HEIGHT  25

#define SCORE_LEVEL 3
#define SPEED_LEVEL 7
#define NEXT_FIGURE_LEVEL 11

typedef struct __attribute__((packed))
{
    figure* next_figure;
    i32 score;
    unsigned char speed;
} game_data;

void
display_map(const map, const game_data);

#endif // GRAPHICS_H