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
    
    printf(
        "its my own realization of tetris on C!\n"
        "    press any key to continue...\n"
    );

    _getch();
    system("cls");

    init_rnd(); // инициализируем рандомайзер для фигур
    init_map(&map); // инициализируем игровое поле

    display_map(2, 1);

    delete_map(&map);

    return 0;
}