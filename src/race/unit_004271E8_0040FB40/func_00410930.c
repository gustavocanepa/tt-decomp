#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00410930_arg0 {
    char pad0[0x14];
    u8 unk14;
};

s32 func_00410930(struct func_00410930_arg0 *arg0, s32 arg1) {
    return ((s32) arg0->unk14 >> arg1) & 1;
}
