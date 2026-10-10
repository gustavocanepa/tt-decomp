#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004126E0(s32, s32);                /* extern */

struct func_00412828_arg0 {
    char pad0[0x4];
    s32 *unk4;
};

void func_00412828(struct func_00412828_arg0 *arg0) {
    func_004126E0(*arg0->unk4, 1);
}
