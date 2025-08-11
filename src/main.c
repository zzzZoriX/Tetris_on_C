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
#include <conio.h>

static f32 speed = 1;
static i32 score = 0;
static i32 max_score = 0;


i32
main(void){
    system("cls");

    kernel(); 

    printf(
        "\nSave data? (y/n)\n"
    );

    char answer;
    scanf("%c", &answer);
    getchar();
    answer = tolower(answer);

    if(answer == 'y')
        save_data();

    return 0;
}

void __stdcall
kernel(){
    map map;
    char c = 's';

    figure 
        * current_figure,
        * next_figure
    ;
    
    while(c == 's'){
        printf(
        "It's my own realization of tetris on C!\n"
            "\tto exit press 'q'\n"
            "\tto settings press 's'\n"
            "    press any key to continue...\n"
        );

        c = _getch();
        system("cls");

        if(c == 's')
            settings();
    }

    init_rnd(c); // инициализируем рандомайзер для фигур
    init_map(&map); // инициализируем игровое поле

    current_figure = generate_figure();
    next_figure = generate_figure();

    while(true){
        if(_kbhit()){
            c = _getch();

            if(c == 'd')
                move_figure(current_figure, &map, move_right);

            else if(c == 'a')
                move_figure(current_figure, &map, move_left);

            else if(c == 's'){
                if(!check_bottom(current_figure, map)){
                    change_figure(&current_figure, &next_figure, &map);
                    continue;
                }

                move_figure(current_figure, &map, move_down);
            }

            else if(c == 'q')
                break;
        }


// устанавливаем фигуру на поле
        place_figure(current_figure, &map);


        system("cls");
        display_map(
            map, 
            (game_data){next_figure, score, max_score, speed}
        );


        if(!check_bottom(current_figure, map)){
            change_figure(&current_figure, &next_figure, &map);
            continue;
        }

// пассивно двигаем фигуру вниз
        move_figure(current_figure, &map, move_down);


        Sleep(1000 / speed);
    }

    delete_map(&map);

    if(max_score < score)
        max_score = score;

    system("cls");
    printf("Total score: %d\nMax score: %d\n", score, max_score);

    return;
}

void
change_figure(figure** cf, figure** nf, map* map){
    char full_row = -1;

    while((full_row = check_rows(*map)) != -1){
        for (char w = 0; w < WIDTH - 2; ++w) {
            if (!(*map)[full_row][w].is_free && (*map)[full_row][w].f_part.parent_ptr) 
                (*map)[full_row][w].f_part.parent_ptr = NULL;

            (*map)[full_row][w].is_free = true;
        }

        for (char h = full_row; h > 0; --h)
            for (char w = 0; w < WIDTH - 2; ++w)
                (*map)[h][w] = (*map)[h-1][w];

        for (char w = 0; w < WIDTH - 2; ++w) {
            (*map)[0][w].is_free = true;
            (*map)[0][w].f_part.parent_ptr = NULL;
        }
        
        score += 100;
    }

    *cf = *nf;
    *nf = generate_figure();

    score += 10;
}

void
save_data(){
    system("cls");

    FILE* sfpt = fopen("C:\\CTETRIS_DATA_SAVE.dat", "wb");
    if(!sfpt){
        _set_cmd_text_color(RED);
        printf("Error: Can't create a save file on path: C:\\CTETRIS_DATA_SAVE.dat");
        _set_cmd_text_color(WHITE);

        exit(1);
    }

    fprintf(sfpt, "%d %f", max_score, speed);

    fclose(sfpt);

    _set_cmd_text_color(GREEN);
    printf("Data successfully saved on path: C:\\CTETRIS_DATA_SAVE.dat!");
    _set_cmd_text_color(WHITE);
}

void
settings(){
    char c;

    printf(
        "  change speed:\n"
        "\t%.1f\n", speed
    );

    while(true){
        if(_kbhit()){
            c = _getch();

            if(c == 'q')
                break;

            if(c == 77){
                speed += 0.1;

                system("cls");
                printf(
                    "  change speed:\n"
                    "\t%.1f\n", speed
                );
            }

            if(c == 75){
                if(speed >= 0.1)
                    speed -= 0.1;

                system("cls");
                printf(
                    "  change speed:\n"
                    "\t%.1f\n", speed
                );
            }
        }
    }

    system("cls");
}