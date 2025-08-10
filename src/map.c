#include "./lib/map.h"

void
init_map(map* map){
    *map = (cell**)calloc(30 - 2, sizeof(cell*));
    if(!*map){
        printf("Error: Can't allocate memory for map...");
        exit(1);
    }

    for(char h = 0; h < 30 - 2; ++h){
        *map[h] = (cell*)calloc(15 - 2, sizeof(cell));
        if(!*map[h]){
            printf("Error: Can't allocate memory for map...");
            exit(1);
        }
    }

    for(char h = 0; h < 30 - 2; ++h)
        for(char w = 0; w < 15; ++w)
            (*map[h][w]).is_free = true;
}

void
delete_map(map* map){
    for(char h = 0; h < 30 - 2; ++h)
        for(char w = 0; w < 15; ++w)
            free(*map[h]);
}