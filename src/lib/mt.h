#pragma once 

#include <stdint.h>

#define MT_w 32
#define MT_n 624
#define MT_m 397
#define MT_r 31
#define MT_a 0x9908B0DF // в 10-чной системе - 2567483615
#define MT_u 11
#define MT_s 7
#define MT_b 0x9D2C5680 // в 10-чной системе - 2636928640
#define MT_t 15
#define MT_c 0xEFC60000 // в 10-чной системе - 4022730752
#define MT_l 18
#define MT_rf 1812433253


typedef struct mt {
    uint32_t state_arr[MT_n];
    int state_i;
} mt;

void init_mt(mt*, uint32_t);
uint32_t get_rand(mt*);