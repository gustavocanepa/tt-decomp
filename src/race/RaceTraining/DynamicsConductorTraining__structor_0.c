#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002CF8D0();                                /* extern */
s32 func_0033E2F0(void *, s32);                 /* extern */
s32 func_00370E40(s32);                         /* extern */
s32 func_00371D18(s32);                         /* extern */
s32 func_0037FAA0(void *);                      /* extern */
s32 func_003803A8(void *, void *);              /* extern */
s32 func_00388260();                            /* extern */
s32 func_003A3418(void *);                      /* extern */

extern char D_005D4DF8[];
extern char D_005D6C68[];
struct DynamicsConductorTraining__structor_0_temp_s0 {
    char pad0[0x241CC];
    s32 unk241CC;
};

struct DynamicsConductorTraining__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    void *unk70;
    s32 unk74;
    char pad78[0xDB4];
    s32 unkE2C;
};

void DynamicsConductorTraining__structor_0(void *arg0) {
    s32 temp_s2;
    s32 temp_s4;
    struct DynamicsConductorTraining__structor_0_temp_s0 *temp_s0;
    void *temp_s1;

    temp_s4 = arg0 + 0x39930;
    func_00388260();
    temp_s2 = arg0 + 0x13C40;
    temp_s0 = arg0 + 0x14E30;
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unk64 = (s32)D_005D4DF8;
    temp_s1 = arg0 + 0x39000;
    func_00370E40(temp_s2);
    func_003A3418(temp_s0);
    temp_s0->unk241CC = (s32)D_005D6C68;
    func_0037FAA0(temp_s1);
    func_00371D18(temp_s4);
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unk74 = temp_s2;
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unk70 = temp_s0;
    if (func_002CF8D0() == 0) {
        func_003803A8(temp_s1, arg0 + 0xE418);
    }
    func_0033E2F0(arg0, temp_s4);
    ((struct DynamicsConductorTraining__structor_0_arg0 *)arg0)->unkE2C = 3;
}
