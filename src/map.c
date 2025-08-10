#include "./lib/map.h"

void
init_map(map* map){
    *map = (cell**)calloc(25 - 2, sizeof(cell*));
    if(!*map){
        _set_cmd_text_color(RED);
        printf("Error: Can't allocate memory for map...");
        _set_cmd_text_color(WHITE);
        exit(1);
    }

    for(char h = 0; h < 25 - 2; ++h){
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

    for(char h = 0; h < 25 - 2; ++h)
        for(char w = 0; w < 15 - 2; ++w)
            (*map)[h][w].is_free = true;
}

void
delete_map(map* map){
    if(!map || !*map)
        return;
    
    for(char h = 0; h < 25 - 2; ++h)
        free((*map)[h]);

    free(*map);
}

void
place_figure(figure* figure, map* map){
    for(char i = 0; i < 4; ++i){
        char 
            x = figure->parts[i].x,
            y = figure->parts[i].y
        ;

        (*map)[y][x].f_part = figure->parts[i];
        (*map)[y][x].is_free = false;
    }
}