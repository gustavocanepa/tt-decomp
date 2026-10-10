/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */

struct func_001087B0_var_s0 {
    s32 unk0;
    char pad4[0x4];
    void *unk8;
};

void func_001087B0(void **arg0, s32 (*arg1)(s32)) {
    s32 temp_a0;
    s32 temp_s2;
    struct func_001087B0_var_s0 *var_s0;

    temp_s2 = (s32)((char *)arg0 + 0xC);
    func_004A4D68(temp_s2);
    var_s0 = *arg0;
    if (var_s0 != NULL) {
        do {
            temp_a0 = var_s0->unk0;
            var_s0 = var_s0->unk8;
            arg1(temp_a0);
        } while (var_s0 != NULL);
    }
    func_004A4DD8(temp_s2);
}
