#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003470E8(s32, s32);                /* extern */

struct func_00347128_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_00347128(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    void *var_s0;

    var_s0 = arg0;
    var_s2 = arg0 + 0x4D8;
    var_s3 = var_s2;
    var_s4 = 3;
    func_003470E8(arg0 + 0x280, 0x4B);
    func_003470E8(arg0 + 0x2A0, 0x4C);
    func_003470E8(arg0 + 0x410, 0x4D);
    func_003470E8(arg0 + 0x430, 0x4E);
    func_003470E8(arg0 + 0x450, 0x2D);
    func_003470E8(arg0 + 0x470, 0x42);
    func_003470E8(arg0 + 0x490, 0x41);
    do {
        if (arg1 != 0) {
            func_003470E8(var_s2, 0x4A);
        } else {
            func_003470E8(var_s3, 0x22);
        }
        func_003470E8(var_s0 + 0x538, 0x10);
        var_s4 -= 1;
        func_003470E8(var_s0 + 0x5B8, 0x14);
        var_s3 += 0x1A0;
        func_003470E8(var_s0 + 0x558, 0x11);
        var_s2 += 0x1A0;
        func_003470E8(var_s0 + 0x4F8, 0x49);
        func_003470E8(var_s0 + 0x518, 0x13);
        func_003470E8(var_s0 + 0x5D8, 0x1E);
        func_003470E8(var_s0 + 0x5F8, 0x1F);
        func_003470E8(var_s0 + 0x618, 0x1F);
        func_003470E8(var_s0 + 0x578, 0x30);
        temp_a0 = var_s0 + 0x598;
        var_s0 += 0x1A0;
        func_003470E8(temp_a0, 0x20);
    } while (var_s4 >= 0);
    ((struct func_00347128_arg0 *)arg0)->unk0 = 0;
    ((struct func_00347128_arg0 *)arg0)->unk4 = 1;
}
