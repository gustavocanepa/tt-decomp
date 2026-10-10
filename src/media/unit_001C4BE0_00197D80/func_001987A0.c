#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00198D50(void *);                      /* extern */
s32 func_00198DD8(void *, s32);             /* extern */
s32 func_004AE9C0();                            /* extern */

struct func_001987A0_arg0 {
    char pad0[0x30];
    s32 unk30;
    char pad34[0x640];
    s32 unk674;
    s32 unk678;
    s32 unk67C;
    char pad680[0x8];
    s32 unk688;
    s32 unk68C;
    s32 unk690;
    char pad694[0xC];
    s32 unk6A0;
    char pad6A4[0x2C];
    s32 unk6D0;
    s32 unk6D4;
    s32 unk6D8;
    s32 unk6DC;
    s32 unk6E0;
};

void func_001987A0(void *arg0, s32 arg1) {
    s32 *var_v0;
    s32 var_v1;

    func_004AE9C0();
    ((struct func_001987A0_arg0 *)arg0)->unk30 = arg1;
    var_v0 = arg0 + 0x34;
    var_v1 = 0x18F;
    do {
        var_v1 -= 1;
        *var_v0 = 0;
        var_v0 += 1;
    } while (var_v1 != -1);
    ((struct func_001987A0_arg0 *)arg0)->unk674 = 0;
    ((struct func_001987A0_arg0 *)arg0)->unk6D0 = -1;
    ((struct func_001987A0_arg0 *)arg0)->unk6D4 = -1;
    ((struct func_001987A0_arg0 *)arg0)->unk6D8 = -1;
    ((struct func_001987A0_arg0 *)arg0)->unk6DC = -1;
    ((struct func_001987A0_arg0 *)arg0)->unk678 = 0;
    ((struct func_001987A0_arg0 *)arg0)->unk67C = 0;
    ((struct func_001987A0_arg0 *)arg0)->unk688 = 0;
    ((struct func_001987A0_arg0 *)arg0)->unk68C = 0;
    ((struct func_001987A0_arg0 *)arg0)->unk690 = 0;
    ((struct func_001987A0_arg0 *)arg0)->unk6A0 = 0;
    ((struct func_001987A0_arg0 *)arg0)->unk6E0 = 0;
    func_00198DD8(arg0, 0);
    func_00198D50(arg0);
}
