#ifndef FIGURE_H
#define FIGURE_H

#include "common.h"
#include "graphics.h"
#include "mt.h"

typedef enum
ft { 
    SQUARE,
    THUNDER,
    LINE,
    L_TYPE
} figure_type;

typedef struct
figure {
    figure_type type;
    i32 color;
    char x, y; // x и y все равно не будут больше 127 и уж точно не опустятся ниже 0
} figure;

void
init_rnd();

figure*
generate_figure(const char, const char);

#endif // FIGURE_H