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
place_figure(figure*, map*);

void
delete_map(map*);

void
remove_figure(figure*, map*);

void
move_figure(figure*, map*, void(*)(figure*));

#endif // MAP_H