#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00304690_arg0 {
    char pad0[0x4B4];
    f32 unk4B4;
    char pad4B8[0x1A8];
    f32 unk660;
    s32 unk664;
};

void func_00304690(struct func_00304690_arg0 *arg0) {
    arg0->unk664 = 0;
    arg0->unk660 = (f32) arg0->unk4B4;
}
