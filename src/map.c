#include "./lib/map.h"

void
init_map(cell map[WIDTH - 2][HEIGHT - 2]){
    for(char w = 0; w < WIDTH - 2; ++w)
        for(char h = 0; h < HEIGHT; ++h)
            map[w][h].is_free = true;
}