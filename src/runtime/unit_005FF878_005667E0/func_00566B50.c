#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00566B50_arg0 {
    char pad0[0x24];
    s32 unk24;
};

s32 func_00566B50(struct func_00566B50_arg0 *arg0) {
    return arg0->unk24;
}
