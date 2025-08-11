#include "./lib/figure.h"
#include "lib/common.h"

static enum ft
figure_types[] = {
    SQUARE,
    THUNDER, 
    LINE, 
    L_TYPE
}; // типы фигур в виде массива

static i32
colors[] = {
    RED,
    GREEN,
    BLUE,
    WHEEL,
    PURPLE,
    YELLOW
};

static mt _meta, _mt_x;

static inline void
init_part(part* p, const char x, const char y){
    p->x = x;
    p->y = y;
}


void
init_rnd(){
    init_mt(&_meta, 21);
    init_mt(&_mt_x, 312);
}

figure*
generate_figure(){
    figure* new_figure = (figure*)malloc(sizeof(figure));
    if(!new_figure){
        system("cls");
        _set_cmd_text_color(RED);
        printf("Error: Can't allocate memory for figure...");
        _set_cmd_text_color(WHITE);
        exit(1);
    }

    u32 
        color_index = get_rand(&_meta) % 6,   // рандомим цвет
        ft_index = get_rand(&_meta) % 4       // рандомим тип фигуры
    ;

    new_figure->color = colors[color_index];
    new_figure->type = figure_types[ft_index];
    new_figure->x = get_rand(&_mt_x) % 13;
    if(new_figure->x == 15)
        --new_figure->x;


    for(char i = 0; i < 4; ++i)
        new_figure->parts[i].parent_ptr = new_figure; // обозначаем родителя каждой части фигуры
    

    switch(new_figure->type){
        case SQUARE:
            new_figure->y = 1;
            
            init_part(&new_figure->parts[0], new_figure->x, 1);
            init_part(&new_figure->parts[1], new_figure->x, 0);
            init_part(&new_figure->parts[2], new_figure->x + 1, 1);
            init_part(&new_figure->parts[3], new_figure->x + 1, 0);

            break;

        case THUNDER:
            new_figure->y = 2;
            
            init_part(&new_figure->parts[0], new_figure->x + 1, 2);
            init_part(&new_figure->parts[1], new_figure->x + 1, 1);
            init_part(&new_figure->parts[2], new_figure->x, 1);
            init_part(&new_figure->parts[3], new_figure->x, 0);

            break;

        case LINE:
            new_figure->y = 2;
            
            init_part(&new_figure->parts[0], new_figure->x, 2);
            init_part(&new_figure->parts[1], new_figure->x, 1);
            init_part(&new_figure->parts[2], new_figure->x, 0);

            break;

        case L_TYPE:
            new_figure->y = 2;
            
            init_part(&new_figure->parts[0], new_figure->x + 1, 2);
            init_part(&new_figure->parts[1], new_figure->x, 2);
            init_part(&new_figure->parts[2], new_figure->x, 1);
            init_part(&new_figure->parts[3], new_figure->x, 0);

            break;
    }

    return new_figure;
}

void
delete_figure(figure** f){
    if(!f || !*f)
        return;
    
    for(char i = 0; i < 4; ++i)
        (*f)->parts[i].parent_ptr = NULL;

    *f = NULL;
}