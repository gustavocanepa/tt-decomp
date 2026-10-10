#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AF820();                            /* extern */

extern char D_005ADB80[];
struct func_001B0338_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

void func_001B0338(struct func_001B0338_arg0 *arg0) {
    func_001AF820();
    arg0->unk5C = (s32)D_005ADB80;
}
