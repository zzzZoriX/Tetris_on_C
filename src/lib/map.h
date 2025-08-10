#ifndef MAP_H
#define MAP_H

#include "common.h"
#include "figure.h"

typedef struct
cell {
    bool is_free;
    part f_part;
} cell;

typedef cell** map;

void
init_map(map*);

void
delete_map(map*);

#endif // MAP_H