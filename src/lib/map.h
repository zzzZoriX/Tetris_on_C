#ifndef MAP_H
#define MAP_H

#include "common.h"
#include "figure.h"
#include "graphics.h"

typedef struct
cell {
    bool is_free;
    part f_part;
} cell;

void
init_map(cell[WIDTH - 2][HEIGHT - 2]);

#endif // MAP_H