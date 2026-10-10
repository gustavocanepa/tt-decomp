/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00439B48(s32, s32, void *, s32, s32); /* extern */
void *func_00473980(s32);                       /* extern */

struct func_00445598_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};
struct func_00445598_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_00445598(s32 arg0, struct func_00445598_arg1 *arg1) {
    struct func_00445598_temp_v0 *temp_v0;

    temp_v0 = func_00473980(2);
    temp_v0->unk0 = (f32) arg1->unk0;
    temp_v0->unk4 = (f32) arg1->unk4;
    temp_v0->unk8 = (f32) arg1->unk8;
    temp_v0->unkC = (f32) arg1->unk4;
    temp_v0->unk10 = (f32) arg1->unk0;
    temp_v0->unk14 = (f32) arg1->unkC;
    temp_v0->unk18 = (f32) arg1->unk8;
    temp_v0->unk1C = (f32) arg1->unkC;
    func_00439B48(arg0, 4, temp_v0, 0, 0);
}
