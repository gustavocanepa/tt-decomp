#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00518470_arg0 {
    char pad0[0x17C];
    s32 unk17C;
};

s32 func_00518470(struct func_00518470_arg0 *arg0) {
    return arg0->unk17C;
}
