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
        for(char w = 0; w < 15 - 2; ++w)
            if(!(*map)[h][w].is_free && (*map)[h][w].f_part.parent_ptr){
                delete_figure(&(*map)[h][w].f_part.parent_ptr);

                (*map)[h][w].is_free = true;
            }

    for(char h = 0; h < 25 - 2; ++h)
        free((*map)[h]);

    free(*map);
}

// (figure->type == LINE ? 3 : 4) - т.к. line использует лишь 3 части, то использование четвертой будет неправильным
// 13 - ширина поля/последняя ячейка поля в ширину, 14 за ее границами
void
place_figure(figure* figure, map* map){ 
    for(char i = 0; i < (figure->type == LINE ? 3 : 4); ++i){
        const char x = figure->parts[i].x;
        if(x >= 13)
            move_left(figure);

        else if(x <= -1)
            move_right(figure);
    }

    for(char i = 0; i < (figure->type == LINE ? 3 : 4); ++i){ 
        char 
            x = figure->parts[i].x,
            y = figure->parts[i].y
        ;

        (*map)[y][x].f_part = figure->parts[i];
        (*map)[y][x].is_free = false;
    }
}

void
remove_figure(figure* f, map* map){
    for(char i = 0; i < (f->type == LINE ? 3 : 4); ++i){
        char
            x = f->parts[i].x,
            y = f->parts[i].y
        ;

        (*map)[y][x].is_free = true;
    }
}

void
move_figure(figure* f, map* map, void (*dir)(figure*)){
    remove_figure(f, map);
    dir(f);
}

bool
check_bottom(figure* f, map map){
    for(char i = 0; i < (f->type == LINE ? 3 : 4); ++i){
        char
            x = f->parts[i].x,
            y = f->parts[i].y + 1
        ;

        if(y >= 23 || (!map[y][x].is_free && map[y][x].f_part.parent_ptr != f)) return false;
    }

    return true;
}

char
check_rows(map map){
    for(char h = 22; h >= 0; --h){
        bool is_full_row = true;

        for(char w = 0; w < 15 - 2; ++w)
            if(map[h][w].is_free){
                is_full_row = false;
                break;
            }

        if(is_full_row){
            return h;
        }
    }

    return -1;
}