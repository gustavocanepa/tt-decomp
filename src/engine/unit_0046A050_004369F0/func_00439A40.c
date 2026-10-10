/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A180();                            /* extern */
s32 func_0046A6C8(s32, void *, s32, s32, s32); /* extern */
void *func_00473980(s32);                       /* extern */

struct func_00439A40_arg0 {
    char pad0[0x14];
    s32 unk14;
};
struct func_00439A40_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};
struct func_00439A40_arg1 {
    f32 unk0;
    f32 unk4;
};
struct func_00439A40_arg2 {
    f32 unk0;
    f32 unk4;
};
struct func_00439A40_arg3 {
    f32 unk0;
    f32 unk4;
};

void func_00439A40(struct func_00439A40_arg0 *arg0, struct func_00439A40_arg1 *arg1, struct func_00439A40_arg2 *arg2, struct func_00439A40_arg3 *arg3) {
    struct func_00439A40_temp_v0 *temp_v0;

    if (arg0->unk14 == 0) {
        func_0043A180();
    }
    temp_v0 = func_00473980(2);
    temp_v0->unk0 = (f32) arg1->unk0;
    temp_v0->unk4 = (f32) arg1->unk4;
    temp_v0->unk8 = (f32) arg2->unk0;
    temp_v0->unkC = (f32) arg2->unk4;
    temp_v0->unk10 = (f32) arg3->unk0;
    temp_v0->unk14 = (f32) arg3->unk4;
    func_0046A6C8(1, temp_v0, 0, 0, 0);
}
