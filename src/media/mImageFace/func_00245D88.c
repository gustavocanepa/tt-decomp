#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00245D88_arg0 {
    char pad0[0x174];
    u8 unk174;
    u8 unk175;
};

void func_00245D88(struct func_00245D88_arg0 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (s32) arg0->unk174;
    *arg2 = (s32) arg0->unk175;
}
