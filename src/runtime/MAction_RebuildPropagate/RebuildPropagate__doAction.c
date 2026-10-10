/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E8060(s32, s32);                    /* extern */
s32 func_00202930();                                /* extern */
s32 func_0020D7A8(s32);                             /* extern */
s32 func_002A8968(s32, s32);                        /* extern */

struct RebuildPropagate__virtual_01_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void RebuildPropagate__doAction(struct RebuildPropagate__virtual_01_arg0 *arg0, s32 arg1) {
    if ((func_002A8968(arg1, func_00202930()) != 0) && (func_0020D7A8(arg1) != 0)) {
        func_001E8060(arg0->unk4, arg1);
    }
}
