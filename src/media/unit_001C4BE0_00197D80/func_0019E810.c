#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033CA70(s8);                              /* extern */

extern char D_005E6B18[];
struct func_0019E810_arg0 {
    char pad0[0x48];
    u16 unk48;
    char pad4A[0x136];
    s8 unk180;
};

s32 func_0019E810(struct func_0019E810_arg0 *arg0) {
    if (arg0->unk48 & 1 & 0xFFFF) {
        return func_0033CA70(arg0->unk180);
    }
    return (s32)D_005E6B18;
}
