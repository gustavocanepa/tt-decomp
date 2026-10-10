#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00248288_arg0 {
    char pad0[0x1A4];
    s32 unk1A4;
};

s32 func_00248288(struct func_00248288_arg0 *arg0) {
    return (u32) (arg0->unk1A4 - 2) < 2U;
}
