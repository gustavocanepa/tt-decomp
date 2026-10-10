#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542008_arg0 {
    char pad0[0x68];
    s32 unk68;
};

s32 func_00542008(struct func_00542008_arg0 *arg0) {
    return arg0->unk68;
}
