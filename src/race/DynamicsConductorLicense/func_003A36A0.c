#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003A36A0_arg0 {
    char pad0[0x4E];
    u8 unk4E;
};

s32 func_003A36A0(struct func_003A36A0_arg0 *arg0) {
    return arg0->unk4E != 0;
}
