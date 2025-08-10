#include "./lib/graphics.h"

static inline void
_print_width(){
    printf("+");
    for(int i = 1; i < WIDTH - 1; ++i)
        printf(" -");
    printf(" +\n");
}

static inline void
_print_height(){
    for(int i = 0; i < HEIGHT; ++i){
        printf("|");
        for(int j = 0; j < WIDTH - 2; ++j)
            printf("  ");
        printf(" |\n");
    }
}

void
display_map(const i32 score, const unsigned char speed){
    _print_width();
    _print_height();
    _print_width();
}