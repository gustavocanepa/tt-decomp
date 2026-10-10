#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002CF8D0();                                /* extern */
s32 func_003890D8(s32);                         /* extern */
s32 func_0037D418(void *);                      /* extern */
s32 func_0037DF48(void *, void *);              /* extern */
s32 func_00388260();                            /* extern */
s32 func_003A3418(void *);                      /* extern */

extern char D_005D34D0[];
extern char D_005D68D8[];
struct DynamicsConductorMission__structor_0_temp_s0 {
    char pad0[0x241CC];
    s32 unk241CC;
};

struct DynamicsConductorMission__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    void *unk70;
    char pad74[0xDB8];
    s32 unkE2C;
};

s32 DynamicsConductorMission__structor_0(void *arg0) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_s3;
    struct DynamicsConductorMission__structor_0_temp_s0 *temp_s0;
    void *temp_s0_2;

    var_s3 = 5;
    func_00388260();
    temp_s0 = arg0 + 0x13C40;
    var_s1 = arg0 + 0x37E10;
    ((struct DynamicsConductorMission__structor_0_arg0 *)arg0)->unk64 = (s32)D_005D34D0;
    func_003A3418(temp_s0);
    temp_s0->unk241CC = (s32)D_005D68D8;
    do {
        temp_a0 = var_s1;
        var_s1 += 8;
        var_s3 -= 1;
        func_003890D8(temp_a0);
    } while (var_s3 != -1);
    temp_s0_2 = arg0 + 0x37E40;
    func_0037D418(temp_s0_2);
    ((struct DynamicsConductorMission__structor_0_arg0 *)arg0)->unk70 = (void *) (arg0 + 0x13C40);
    if (func_002CF8D0() == 0) {
        func_0037DF48(temp_s0_2, arg0 + 0xE418);
    }
    ((struct DynamicsConductorMission__structor_0_arg0 *)arg0)->unkE2C = 0xA;
}
