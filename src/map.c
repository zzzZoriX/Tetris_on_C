#include "./lib/map.h"

void
init_map(map* map){
    *map = (cell**)calloc(30 - 2, sizeof(cell*));
    if(!*map){
        _set_cmd_text_color(RED);
        printf("Error: Can't allocate memory for map...");
        _set_cmd_text_color(WHITE);
        exit(1);
    }

    for(char h = 0; h < 30 - 2; ++h){
        (*map)[h] = (cell*)calloc(15 - 2, sizeof(cell));
        if(!(*map)[h]){
            for (int i = 0; i < h; ++i)
                free((*map)[i]);
            free(*map);

            _set_cmd_text_color(RED);
            printf("Error: Can't allocate memory for map...");
            _set_cmd_text_color(WHITE);
            exit(1);
        }
    }

    for(char h = 0; h < 30 - 2; ++h)
        for(char w = 0; w < 15; ++w)
            (*map)[h][w].is_free = true;
}

void
delete_map(map* map){
    for(char h = 0; h < 30 - 2; ++h)
        for(char w = 0; w < 15; ++w)
            free(*map[h]);
}