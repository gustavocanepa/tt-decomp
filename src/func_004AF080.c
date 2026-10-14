#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A48D8(void *, s32);             /* extern */
s32 func_004AF0F0(void *, s32);             /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DAE48[];
struct func_004AF080_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_004AF080(struct func_004AF080_arg0 *arg0, s32 arg1) {
    arg0->unk14 = (s32)D_005DAE48;
    func_004AF0F0(arg0, -1);
    func_004A48D8(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
