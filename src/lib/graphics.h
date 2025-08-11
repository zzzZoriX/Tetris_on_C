#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "common.h"
#include "figure.h"
#include "map.h"

#define WIDTH   15
#define HEIGHT  25

#define MAX_SCORE_LEVEL 3
#define SCORE_LEVEL 7
#define SPEED_LEVEL 11
#define NEXT_FIGURE_LEVEL 15

typedef struct __attribute__((packed))
{
    figure* next_figure;
    i32 score;
    i32 max_score;
    f32 speed;
} game_data;

void
display_map(const map, const game_data);

#endif // GRAPHICS_H