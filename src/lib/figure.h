#ifndef FIGURE_H
#define FIGURE_H

#include "common.h"
#include "mt.h"

typedef enum
ft { 
    SQUARE,
    THUNDER,
    LINE,
    L_TYPE
} figure_type;

struct figure;

typedef struct __attribute__((packed))
part {
// их значения все равно не выйдут из деапозона от 0 до 30,
// так что можно использовать char, который занимает всего 1 байт памяти
    char x, y;
    struct figure* parent_ptr;
} part;

typedef struct
figure {
    figure_type type;
    i32 color;
    part parts[4]; // больше 4 их быть не может
    char x, y; // координаты левого нижнего угла фигуры
} figure;

void
init_rnd();

figure*
generate_figure();

#endif // FIGURE_H