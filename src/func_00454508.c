#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00454508_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
};

void func_00454508(struct func_00454508_arg0 *arg0, f32 fparg0) {
    arg0->unk0 = (f32) (arg0->unk0 / fparg0);
    arg0->unk4 = (f32) (arg0->unk4 / fparg0);
    arg0->unk8 = (f32) (arg0->unk8 / fparg0);
    arg0->unkC = (f32) (arg0->unkC / fparg0);
    arg0->unk10 = (f32) (arg0->unk10 / fparg0);
    arg0->unk14 = (f32) (arg0->unk14 / fparg0);
    arg0->unk18 = (f32) (arg0->unk18 / fparg0);
    arg0->unk1C = (f32) (arg0->unk1C / fparg0);
    arg0->unk20 = (f32) (arg0->unk20 / fparg0);
}
