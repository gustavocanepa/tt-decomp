#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceEventQueue__structor_1(void *, s32);             /* extern */
s32 func_00375840();                            /* extern */
s32 func_003758C0(void *);                      /* extern */
s32 func_003759E8(void *);                      /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D3A70[];
struct func_003756E0_arg0 {
    char pad0[0x974];
    s32 unk974;
};

void func_003756E0(void *arg0, s32 arg1) {
    ((struct func_003756E0_arg0 *)arg0)->unk974 = (s32)D_005D3A70;
    func_00375840();
    func_003758C0(arg0);
    func_003759E8(arg0);
    RaceEventQueue__structor_1(arg0 + 0xF4, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
