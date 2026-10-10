#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0042A398_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x48];
    s32 unk50;
    s32 unk54;
    s32 unk58;
};

void func_0042A398(struct func_0042A398_arg0 *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk54 = 0;
    arg0->unk50 = 0;
    arg0->unk58 = 0;
}
