#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

typedef int16_t         i16;
typedef uint16_t        u16;
typedef int32_t         i32;
typedef uint32_t        u32;
typedef int64_t         i64;
typedef uint64_t        u64;

typedef float           f32;
typedef double          d64;

#define RED     FOREGROUND_RED | FOREGROUND_INTENSITY
#define GREEN   FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define BLUE    FOREGROUND_BLUE | FOREGROUND_INTENSITY
#define WHEEL   FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define PURPLE  FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY
#define YELLOW  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY
#define WHITE   FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

void
_set_cmd_text_color(const i32);

#endif // COMMON_H