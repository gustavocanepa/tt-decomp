#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AD9F8(void *, s32);             /* extern */
s32 func_004ADE50();                            /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005DAE30[];
struct func_004ADAE0_arg0 {
    char pad0[0x54];
    s32 unk54;
};

void func_004ADAE0(void *arg0, s32 arg1) {
    ((struct func_004ADAE0_arg0 *)arg0)->unk54 = (s32)D_005DAE30;
    func_004ADE50();
    func_004AD9F8(arg0 + 0x4C, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
