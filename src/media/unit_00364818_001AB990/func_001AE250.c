#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AE250_arg0 {
    char pad0[0x140C4];
    s32 unk140C4;
    f32 unk140C8;
};

void func_001AE250(struct func_001AE250_arg0 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk140C4 = arg1;
    arg0->unk140C8 = fparg0;
}
