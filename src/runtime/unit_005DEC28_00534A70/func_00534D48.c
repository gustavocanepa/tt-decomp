#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00534D48_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

s32 func_00534D48(struct func_00534D48_arg0 *arg0) {
    return arg0->unk5C;
}
