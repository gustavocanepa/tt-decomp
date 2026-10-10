#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 *func_004130E8(void *, s32);
struct func_00413010_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00413010(struct func_00413010_arg0 *arg0) {
    s32 i;
    for (i = 0; i < arg0->unk4; i++) {
        *func_004130E8(arg0, i) = -1;
    }
}
