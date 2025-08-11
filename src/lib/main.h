#ifndef MAIN_H
#define MAIN_H

#include "common.h"
#include "graphics.h"
#include "figure.h"
#include "map.h"

const i16 __stdcall
kernel();

void
change_figure(figure**, figure**, map*);

#endif // MAIN_H