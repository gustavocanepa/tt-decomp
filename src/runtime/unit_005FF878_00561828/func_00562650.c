#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562650_arg0 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 func_00562650(struct func_00562650_arg0 *arg0) {
    return arg0->unk7C;
}
