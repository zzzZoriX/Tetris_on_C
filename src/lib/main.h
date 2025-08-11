#ifndef MAIN_H
#define MAIN_H

#include "common.h"
#include "graphics.h"
#include "figure.h"
#include "map.h"

void __stdcall
kernel();

void
change_figure(figure**, figure**, map*);

void
save_data();

#endif // MAIN_H