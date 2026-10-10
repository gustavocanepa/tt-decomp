#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556340_arg0 {
    char pad0[0x2D];
    s8 unk2D;
};

void func_00556340(struct func_00556340_arg0 *arg0, s8 arg1) {
    arg0->unk2D = arg1;
}
