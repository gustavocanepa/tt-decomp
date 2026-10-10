#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554148_arg0 {
    char pad0[0x2D8];
    s32 unk2D8;
};

void func_00554148(struct func_00554148_arg0 *arg0, s32 arg1) {
    arg0->unk2D8 = arg1;
}
