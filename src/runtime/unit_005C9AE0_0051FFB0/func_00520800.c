#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00520800_arg0 {
    char pad0[0x48];
    u16 unk48;
};

s32 func_00520800(struct func_00520800_arg0 *arg0) {
    return ((u16) arg0->unk48 >> 3) & 1;
}
