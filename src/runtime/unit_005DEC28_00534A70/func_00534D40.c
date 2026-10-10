#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00534D40_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

s32 func_00534D40(struct func_00534D40_arg0 *arg0) {
    return arg0->unk4C;
}
