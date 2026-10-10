/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005038D8();                                /* extern */
s32 func_00503928();                            /* extern */

extern void *D_0077A040;
struct func_004D45B0_var_s0 {
    void *unk0;
    char pad4[0x8];
    s32 unkC;
};

void *func_004D45B0(s32 arg0) {
    s32 temp_v1;
    struct func_004D45B0_var_s0 *var_s0;

    temp_v1 = func_005038D8();
    for (var_s0 = D_0077A040; var_s0 != NULL; var_s0 = var_s0->unk0) {
        if (arg0 == var_s0->unkC) {
            if (temp_v1 != 0) {
                func_00503928();
            }
            return var_s0;
        }
    }
    if (temp_v1 != 0) {
        func_00503928();
    }
    return NULL;
}
