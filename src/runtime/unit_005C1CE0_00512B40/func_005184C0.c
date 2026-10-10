#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005184C0_arg0 {
    char pad0[0x184];
    s32 unk184;
};

s32 func_005184C0(struct func_005184C0_arg0 *arg0) {
    return arg0->unk184;
}
