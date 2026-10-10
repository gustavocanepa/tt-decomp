#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003480B0(s32, s32);                /* extern */

struct func_00369670_arg0 {
    char pad0[0x48BC];
    s32 unk48BC;
};

void func_00369670(void *arg0) {
    func_003480B0(arg0 + 0x48C0, 0);
    ((struct func_00369670_arg0 *)arg0)->unk48BC = 0;
}
