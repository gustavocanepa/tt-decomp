#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);


s32 func_00385B20();                            /* extern */

extern char D_005D3B30[];
struct PitmenData__structor_0_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x60];
    s32 unk6C;
};

void PitmenData__structor_0(void *arg0) {
    s32 *var_v0;
    s32 var_a1;
    s32 var_v1;
    s8 *var_a0;

    func_00385B20();
    ((struct PitmenData__structor_0_arg0 *)arg0)->unk8 = 0;
    var_a0 = arg0 + 0xC;
    ((struct PitmenData__structor_0_arg0 *)arg0)->unk6C = (s32)D_005D3B30;
    var_a1 = 0;
    do {
        var_v1 = 3;
        var_v0 = (s32 *)(var_a0 + 0xC);
loop_2:
        var_v1 -= 1;
        *var_v0 = 0;
        var_v0 -= 1;
        if (var_v1 >= 0) {
            goto loop_2;
        }
        var_a1 += 1;
        var_a0 += 0x10;
    } while (var_a1 < 6);
}
