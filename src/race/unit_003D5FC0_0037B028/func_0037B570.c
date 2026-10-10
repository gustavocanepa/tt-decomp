#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_002E5E40(s32);                             /* extern */
f32 func_002E5EA0(s32, f32);                        /* extern */
f32 func_002E5ED0(s32, f32);                        /* extern */

struct func_0037B570_arg1 {
    char pad0[0x4];
    s32 unk4;
};
struct func_0037B570_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void *func_0037B570(struct func_0037B570_arg0 *arg0, struct func_0037B570_arg1 *arg1, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;

    temp_f22 = func_002E5E40(arg1->unk4);
    temp_f20 = func_002E5EA0(arg1->unk4, fparg0);
    temp_f0 = func_002E5ED0(arg1->unk4, fparg0);
    arg0->unk0 = temp_f22;
    arg0->unk4 = temp_f20;
    arg0->unk8 = temp_f0;
    return arg0;
}
