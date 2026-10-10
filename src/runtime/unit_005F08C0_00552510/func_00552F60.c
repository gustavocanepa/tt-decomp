#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552F60_arg0 {
    char pad0[0x100C];
    s32 unk100C;
};

s32 func_00552F60(struct func_00552F60_arg0 *arg0) {
    return arg0->unk100C;
}
