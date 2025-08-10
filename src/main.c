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

i32
main(void){
    system("cls");

    const i16 result = kernel(); 

    return 0;
}

const i16 __stdcall
kernel(){
    printf(
        "its my own realization of tetris on C!\n"
        "    press any key to continue...\n"
    );

    _getch();
    system("cls");

    init_rnd(); // инициализируем рандомайзер для фигур

    display_map(2, 1);

    return 0;
}