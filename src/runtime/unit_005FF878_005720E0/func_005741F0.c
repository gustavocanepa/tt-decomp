#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005741F0_arg0 {
    char pad0[0x30];
    s32 unk30;
};

s32 func_005741F0(struct func_005741F0_arg0 *arg0) {
    return arg0->unk30;
}
