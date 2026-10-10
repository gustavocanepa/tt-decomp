#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00119870(void *);                      /* extern */
f32 func_0011BDE8(void *);                          /* extern */
s32 func_001DD3C8(s32, f32);                    /* extern */

struct func_00195A18_arg0 {
    char pad0[0xB8];
    void *unkB8;
    s32 unkBC;
    s32 unkC0;
};
struct func_00195A18_temp_a0 {
    char pad0[0x2A4];
    s32 unk2A4;
};

s32 func_00195A18(struct func_00195A18_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    struct func_00195A18_temp_a0 *temp_a0;

    if ((arg0->unkC0 != 0) && (temp_a0 = arg0->unkB8, (temp_a0 != NULL))) {
        if (temp_a0->unk2A4 != 0) {
            temp_s0 = arg0->unkBC;
            if (temp_s0 != 0) {
                return func_001DD3C8(temp_s0, func_0011BDE8(temp_a0));
            }
        } else if (arg2 != 0) {
            func_00119870(temp_a0);
        }
    }
}
