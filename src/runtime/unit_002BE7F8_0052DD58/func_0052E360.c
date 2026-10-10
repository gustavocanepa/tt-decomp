#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052E360_arg0 {
    char pad0[0x34];
    f32 unk34;
    char pad38[0x34];
    f32 unk6C;
    char pad70[0x4];
    s32 unk74;
};

void func_0052E360(struct func_0052E360_arg0 *arg0, f32 fparg0) {
    arg0->unk34 = fparg0;
    arg0->unk74 = 1;
    arg0->unk6C = fparg0;
}
