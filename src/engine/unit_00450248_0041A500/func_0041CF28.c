/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041ED48(s32, s32, s32);               /* extern */

struct func_0041CF28_arg0 {
    void *unk0;
    char pad4[0x9C];
    s32 unkA0;
};
struct func_0041CF28_temp_a1 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
};
struct func_0041CF28_temp_v0 {
    char pad0[0x20];
    s32 unk20;
    s32 unk24;
};

void func_0041CF28(struct func_0041CF28_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 var_a0;
    struct func_0041CF28_temp_a1 *temp_a1;
    struct func_0041CF28_temp_v0 *temp_v0;

    temp_a1 = arg0->unk0;
    var_a0 = arg2;
    if (temp_a1 != NULL) {
        if (var_a0 == 0) {
            var_a0 = temp_a1->unk1C;
        }
        temp_a1_2 = temp_a1->unk18;
        if ((var_a0 != 0) && (temp_a1_2 != 0)) {
            func_0041ED48(var_a0, temp_a1_2, arg1);
        }
        if (arg0->unkA0 != 0) {
            temp_v0 = arg0->unk0;
            temp_a0 = temp_v0->unk24;
            temp_a1_3 = temp_v0->unk20;
            if ((temp_a0 != 0) && (temp_a1_3 != 0)) {
                func_0041ED48(temp_a0, temp_a1_3, arg1);
            }
        }
    }
}
