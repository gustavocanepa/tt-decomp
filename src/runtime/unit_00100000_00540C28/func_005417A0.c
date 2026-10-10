#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005417A0_arg0 {
    char pad0[0x114];
    s32 unk114;
};

s32 func_005417A0(struct func_005417A0_arg0 *arg0) {
    return arg0->unk114;
}
