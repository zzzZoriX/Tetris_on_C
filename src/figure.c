#include "./lib/figure.h"

static enum ft
figure_types[] = {SQUARE, THUNDER, LINE, L_TYPE}; // типы фигур в виде массива

static i32
colors[] = {
    (FOREGROUND_RED | FOREGROUND_INTENSITY),
    (FOREGROUND_GREEN | FOREGROUND_INTENSITY),
    (FOREGROUND_BLUE | FOREGROUND_INTENSITY),
    (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY),
    (FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY),
    (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
};

static mt _meta, _mt_x;

void
init_rnd(){
    init_mt(&_meta, 21);
    init_mt(&_mt_x, 312);
}

figure*
generate_figure(const char x, const char y){
    figure* new_figure = (figure*)malloc(sizeof(figure));
    if(!new_figure){
        system("cls");
        printf("Error: Can't allocate memory for figure...");
        exit(1);
    }

    u32 
        color_index = get_rand(&_meta) % 6,   // рандомим цвет
        ft_index = get_rand(&_meta) % 4       // рандомим тип фигуры
    ;

    new_figure->color = colors[color_index];
    new_figure->type = figure_types[ft_index];
    new_figure->x = get_rand(&_mt_x) % WIDTH;

    switch(new_figure->type){
        case SQUARE:
            new_figure->y = 2;
            break;

        case THUNDER:
            new_figure->y = 3;
            break;

        case LINE:  
            new_figure->y = 3;
            break;

        case L_TYPE:
            new_figure->x = 3;
            break;
    }

    return new_figure;
}