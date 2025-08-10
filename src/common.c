#include "./lib/common.h"

void
_set_cmd_text_color(const i32 color){
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        color
    );
}