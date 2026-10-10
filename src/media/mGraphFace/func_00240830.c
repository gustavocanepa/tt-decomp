#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00240830_arg0 {
    char pad0[0x1B8];
    s32 unk1B8;
};

void func_00240830(struct func_00240830_arg0 *arg0, s32 arg1) {
    arg0->unk1B8 = arg1;
}
