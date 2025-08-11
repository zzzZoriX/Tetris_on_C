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

        if(h == MAX_SCORE_LEVEL)
            printf("\tmax score:\n");
        else if(h == MAX_SCORE_LEVEL + 1)
            printf("\t    %d\n", gd.max_score);

        else if(h == SCORE_LEVEL)
            printf("\t  score:\n");
        else if(h == SCORE_LEVEL + 1)
            printf("\t    %d\n", gd.score);

        else if(h == SPEED_LEVEL)
            printf("\t  speed:\n");
        else if(h == SPEED_LEVEL + 1)
            printf("\t   %.1f\n", gd.speed);


        else if(h == NEXT_FIGURE_LEVEL)
            printf("\t  next:\n");
        
        else if(h == NEXT_FIGURE_LEVEL + 1){
            _set_cmd_text_color(gd.next_figure->color);
            printf("\t  []");

            if(gd.next_figure->type == SQUARE)
                printf("[]");

            printf("\n");
            _set_cmd_text_color(WHITE);
        }
        else if(h == NEXT_FIGURE_LEVEL + 2){
            _set_cmd_text_color(gd.next_figure->color);
            printf("\t  []");

            if(gd.next_figure->type == SQUARE || gd.next_figure->type == THUNDER)
                printf("[]");

            printf("\n");
            _set_cmd_text_color(WHITE);
        }
        else if(h == NEXT_FIGURE_LEVEL + 3 && gd.next_figure->type != SQUARE){
            _set_cmd_text_color(gd.next_figure->color);
            
            if(gd.next_figure->type == LINE)
                printf("\t  []\n");
            else if(gd.next_figure->type == L_TYPE)
                printf("\t  [][]\n");
            else if(gd.next_figure->type == THUNDER)
                printf("\t    []\n");

            _set_cmd_text_color(WHITE);
        }


        else
            printf("\n");
    }

    _print_width();
}