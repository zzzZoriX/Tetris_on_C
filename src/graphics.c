#include "./lib/graphics.h"

static inline void
_print_width(){
    printf("+");
    for(int i = 1; i < WIDTH - 1; ++i)
        printf(" -");
    printf(" +\n");
}

void
display_map(const map map, const game_data gd){
    _print_width();

    for(char h = 0; h < HEIGHT - 2; ++h){
        printf("|");

        for(char w = 0; w < WIDTH - 2; ++w){
            if(map[h][w].is_free)
                printf("  ");
            else{
                const i32 cell_color = map[h][w].f_part.parent_ptr->color;
                _set_cmd_text_color(cell_color);

                printf("[]");
                _set_cmd_text_color(WHITE);
            }
        }
        printf(" |");

        if(h == SCORE_LEVEL)
            printf("\tscore:\n");
        else if(h == SCORE_LEVEL + 1)
            printf("\t  %d\n", gd.score);

        else if(h == SPEED_LEVEL)
            printf("\tspeed:\n");
        else if(h == SPEED_LEVEL + 1)
            printf("\t  %d\n", gd.speed);

        else if(h == NEXT_FIGURE_LEVEL)
            printf("\tnext:\n");
        //else if(h == NEXT_FIGURE_LEVEL + 1);

        else
            printf("\n");
    }

    _print_width();
}