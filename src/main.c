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
    
    printf(
        "It's my own realization of tetris on C!\n"
        "\tto exit press 'q'\n"
        "    press any key to continue...\n"
    );

    _getch();
    system("cls");

    init_rnd(); // инициализируем рандомайзер для фигур
    init_map(&map); // инициализируем игровое поле

    while(true){
        if(_kbhit()){
            c = _getch();

            if(c == 'q')
                break;
        }

        system("cls");
        display_map(map, score, 1);

        Sleep(1000);
    }

    delete_map(&map);

    system("cls");
    printf("Total score: %d\n", score);

    return 0;
}