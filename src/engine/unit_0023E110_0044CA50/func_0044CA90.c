#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_0044CA50(s32, s32);                    /* extern */
s32 func_0056CFD8();                            /* extern */
s32 func_0056D010(s32, s32);                    /* extern */

struct func_0044CA90_arg0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

void func_0044CA90(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_s0;

    var_s0 = 0;
    func_0056CFD8();
    func_0056D010(arg0 + 8, arg1);
    if (((struct func_0044CA90_arg0 *)arg0)->unk4 > 0) {
        do {
            temp_a0 = var_s0 * 8;
            var_s0 += 1;
            func_0044CA50(((struct func_0044CA90_arg0 *)arg0)->unk8 + temp_a0, arg1);
        } while (var_s0 < ((struct func_0044CA90_arg0 *)arg0)->unk4);
    }
}
