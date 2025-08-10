#include "./lib/map.h"

void
init_map(cell*** map){
    *map = (cell**)calloc(HEIGHT - 2, sizeof(cell*));
    if(!*map){
        printf("Error: Can't allocate memory for map...");
        exit(1);
    }

    for(char h = 0; h < HEIGHT - 2; ++h){
        *map[h] = (cell*)calloc(WIDTH - 2, sizeof(cell));
        if(!*map[h]){
            printf("Error: Can't allocate memory for map...");
            exit(1);
        }
    }

    for(char h = 0; h < HEIGHT - 2; ++h)
        for(char w = 0; w < WIDTH; ++w)
            (*map[h][w]).is_free = true;
}

void
delete_map(cell*** map){
    for(char h = 0; h < HEIGHT - 2; ++h)
        for(char w = 0; w < WIDTH; ++w)
            free(*map[h]);
}