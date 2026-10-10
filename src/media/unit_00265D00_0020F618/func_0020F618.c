#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_00202370();                              /* extern */

struct func_0020F618_arg0 {
    char pad0[0xA8];
    void *unkA8;
};
struct func_0020F618_var_v1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    char pad10[0x18];
    s32 unk28;
};
struct func_0020F618_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_0020F618(struct func_0020F618_arg0 *arg0, struct func_0020F618_arg1 *arg1) {
    void *temp_v0;
    struct func_0020F618_var_v1 *var_v1;

    var_v1 = arg0->unkA8;
    if (var_v1 == NULL) {
        temp_v0 = func_00202370();
        arg0->unkA8 = temp_v0;
        var_v1 = temp_v0;
    }
    if (var_v1 != arg1) {
        var_v1->unk0 = (f32) arg1->unk0;
        var_v1->unk4 = (f32) arg1->unk4;
        var_v1->unk8 = (f32) arg1->unk8;
        var_v1->unkC = (f32) arg1->unkC;
        var_v1 = arg0->unkA8;
    }
    var_v1->unk28 = (s32) (var_v1->unk28 | 1);
}
