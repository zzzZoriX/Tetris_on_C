/**
 * @file main.c
 * @author anyvvaay
 * @brief мейн файл тетриса на С
 * @version 0.1
 * @date 2025-08-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "./lib/main.h"
#include "lib/figure.h"
#include "lib/graphics.h"
#include "lib/map.h"

i32
main(void){
    system("cls");

    const i16 result = kernel(); 

    return 0;
}

const i16 __stdcall
kernel(){
    map map;
    char c;

    i32 score = 0;
    unsigned char speed = 1;
    figure 
        * current_figure,
        * next_figure
    ;
    
    printf(
        "It's my own realization of tetris on C!\n"
        "\tto exit press 'q'\n"
        "    press any key to continue...\n"
    );

    _getch();
    system("cls");

    init_rnd(); // инициализируем рандомайзер для фигур
    init_map(&map); // инициализируем игровое поле

    current_figure = generate_figure();
    next_figure = generate_figure();

    printf(
        "%d %d %d %d\n",
        current_figure->color, current_figure->type, current_figure->x, current_figure->y
    );

    while(true){
        if(_kbhit()){
            c = _getch();

            if(c == 'q')
                break;
        }

// устанавливаем фигуру на поле
        place_figure(current_figure, &map);

        system("cls");
        display_map(
            map, 
            (game_data){next_figure, score, speed}
        );

        Sleep(1000 / speed);
    }

    printf("test\n");
    delete_map(&map);
    printf("test\n");

    system("cls");
    printf("Total score: %d\n", score);

    return 0;
}