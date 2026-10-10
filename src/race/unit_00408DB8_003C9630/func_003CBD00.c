#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003CBBE0(void *, void *, void *, void *, s32, s32, s32); /* extern */

struct func_003CBD00_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x54];
    s32 unk5C;
    s32 unk60;
    char pad64[0xEC];
    s32 unk150;
};
struct func_003CBD00_arg1 {
    s32 unk0;
    s32 unk4;
    char pad8[0x54];
    s32 unk5C;
    s32 unk60;
    char pad64[0xEC];
    s32 unk150;
};
struct func_003CBD00_var_a2 {
    s32 unk0;
};
struct func_003CBD00_var_a3 {
    s32 unk0;
};

void *func_003CBD00(void *arg0, void *arg1) {
    s32 temp_a5;
    s32 temp_a6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a4;
    void *var_a2;
    void *var_a3;

    var_a4 = 0;
    temp_a6 = arg0 + 0xC;
    temp_a5 = arg1 + 0xC;
    var_a3 = arg0 + 0xB4;
    var_a2 = arg1 + 0xB4;
    ((struct func_003CBD00_arg0 *)arg0)->unk0 = (s32) ((struct func_003CBD00_arg1 *)arg1)->unk0;
    ((struct func_003CBD00_arg0 *)arg0)->unk4 = (s32) ((struct func_003CBD00_arg1 *)arg1)->unk4;
    ((struct func_003CBD00_arg0 *)arg0)->unk5C = (s32) ((struct func_003CBD00_arg1 *)arg1)->unk5C;
    ((struct func_003CBD00_arg0 *)arg0)->unk60 = (s32) ((struct func_003CBD00_arg1 *)arg1)->unk60;
    do {
        temp_v1 = var_a4 * 4;
        var_a4 += 1;
        *(s32 *)(temp_a6 + temp_v1) = *(s32 *)(temp_a5 + temp_v1);
        M2C_FIELD(var_a3, s32 *, -0x50) = (s32) M2C_FIELD(var_a2, s32 *, -0x50);
        temp_v1_2 = ((struct func_003CBD00_var_a2 *)var_a2)->unk0;
        var_a2 += 4;
        ((struct func_003CBD00_var_a3 *)var_a3)->unk0 = temp_v1_2;
        var_a3 += 4;
    } while (var_a4 < 0x14);
    func_003CBBE0(arg0 + 0x104, arg1 + 0x104, var_a2, var_a3, var_a4, temp_a5, temp_a6);
    ((struct func_003CBD00_arg0 *)arg0)->unk150 = (s32) ((struct func_003CBD00_arg1 *)arg1)->unk150;
    return arg0;
}
