#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E4EC0_arg0 {
    char pad0[0x6D0];
    s32 unk6D0;
};

s32 func_001E4EC0(struct func_001E4EC0_arg0 *arg0) {
    return arg0->unk6D0;
}
