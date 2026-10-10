#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033E2F0(void *, void *);              /* extern */
s32 func_003890D8(s32);                         /* extern */
s32 func_0034F6E8(void *);                      /* extern */
s32 RacePause__structor_0(void *);                      /* extern */
s32 func_00377730(void *, void *);              /* extern */
s32 func_0037D418(void *);                      /* extern */
s32 func_0037DF48(void *, void *);              /* extern */
s32 func_00385EB0();                            /* extern */
s32 func_003A3F58(void *);                      /* extern */

extern char D_005D2EF0[];
struct RaceMachineTest__structor_0_temp_s0 {
    char pad0[0x28];
    s32 unk28;
};

struct RaceMachineTest__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
    char pad68[0x8];
    void *unk70;
    char pad74[0xDB8];
    s32 unkE2C;
};

void RaceMachineTest__structor_0(void *arg0) {
    s32 temp_a0;
    s32 var_s0;
    s32 var_s1;
    struct RaceMachineTest__structor_0_temp_s0 *temp_s0;
    void *temp_s1;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;

    var_s1 = 5;
    var_s0 = arg0 + 0xF280;
    func_00385EB0();
    ((struct RaceMachineTest__structor_0_arg0 *)arg0)->unk64 = (s32)D_005D2EF0;
    do {
        temp_a0 = var_s0;
        var_s0 += 8;
        var_s1 -= 1;
        func_003890D8(temp_a0);
    } while (var_s1 != -1);
    temp_s0 = arg0 + 0xF2B0;
    temp_s4 = arg0 + 0xF2E8;
    temp_s2 = arg0 + 0xFAF4;
    RacePause__structor_0(temp_s0);
    func_0037D418(temp_s4);
    func_0034F6E8(temp_s2);
    temp_s1 = arg0 + 0x14FB0;
    temp_s3 = arg0 + 0xE418;
    func_003A3F58(temp_s1);
    func_0033E2F0(arg0, temp_s2);
    ((struct RaceMachineTest__structor_0_arg0 *)arg0)->unk70 = temp_s1;
    temp_s0->unk28 = 1;
    func_00377730(temp_s0, temp_s3);
    func_0037DF48(temp_s4, temp_s3);
    ((struct RaceMachineTest__structor_0_arg0 *)arg0)->unkE2C = 0xF;
}
