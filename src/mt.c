#include "./lib/mt.h"

static void twist_(mt* mt){
    uint32_t* state_arr = mt->state_arr;

    for(short i = 0; i < MT_n; ++i){
        uint32_t y = (state_arr[i] & 0x80000000) | (state_arr[(i + 1) % MT_n] & 0x7FFFFFFF);
        uint32_t x = state_arr[(i + MT_n) % MT_n] ^ (y >> 1);

        if(y & 1) x ^= MT_a;

        state_arr[i] = x;
    }

    mt->state_i = 0;
}

void init_mt(mt* mt, uint32_t seed){
    uint32_t* state_arr = mt->state_arr;
    state_arr[0] = seed;

    for(short i = 1; i < MT_n; ++i)
        state_arr[i] = MT_rf * (state_arr[i - 1] ^ (state_arr[i - 1] >> 30)) + i;

    mt->state_i = MT_n;
}

uint32_t get_rand(mt* mt){
    if(mt->state_i >= MT_n) twist_(mt);

    uint32_t y = mt->state_arr[mt->state_i++];
    y ^= (y >> MT_u);
    y ^= ((y << MT_s) & MT_b);
    y ^= ((y << MT_t) & MT_c);
    y ^= (y >> MT_l);

    return y;
}