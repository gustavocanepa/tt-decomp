/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005BB4C8[];
struct func_0053F218_arg2 {
    char pad0[0x4];
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

struct func_0053F218_var_a0 {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
};

void *func_0053F218(void *arg0, s32 arg1, struct func_0053F218_arg2 *arg2) {
    s32 var_a1;
    void *var_a0;

    var_a0 = arg0;
    var_a1 = arg1;
    if (var_a1 != 0) {
        do {
            var_a1 -= 1;
            if (var_a0 != NULL) {
                ((struct func_0053F218_var_a0 *)var_a0)->unk0 = (s32)D_005BB4C8;
                ((struct func_0053F218_var_a0 *)var_a0)->unk4 = (s32) arg2->unk4;
                ((struct func_0053F218_var_a0 *)var_a0)->unk8 = (f32) arg2->unk8;
                ((struct func_0053F218_var_a0 *)var_a0)->unkC = (f32) arg2->unkC;
                ((struct func_0053F218_var_a0 *)var_a0)->unk10 = (f32) arg2->unk10;
                ((struct func_0053F218_var_a0 *)var_a0)->unk14 = (f32) arg2->unk14;
                ((struct func_0053F218_var_a0 *)var_a0)->unk18 = (f32) arg2->unk18;
            }
            var_a0 += 0x1C;
        } while (var_a1 != 0);
    }
    return var_a0;
}
