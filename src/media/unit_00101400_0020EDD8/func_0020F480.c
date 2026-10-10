#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0020F480_arg0 {
    char pad0[0x8C];
    f32 unk8C;
    char pad90[0x1C];
    s32 unkAC;
};

void func_0020F480(struct func_0020F480_arg0 *arg0, f32 fparg0) {
    arg0->unk8C = fparg0;
    arg0->unkAC = (s32) (arg0->unkAC | 0x40000);
}
