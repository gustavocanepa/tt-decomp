#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00555250_temp_a0 {
    char pad0[0xD40];
    s32 unkD40;
};

void *func_00555250(s32 arg0) {
    void *temp_a0;

    temp_a0 = arg0 + 0x1DB0;
    return (((struct func_00555250_temp_a0 *)temp_a0)->unkD40 * 0x6A0) + temp_a0;
}
