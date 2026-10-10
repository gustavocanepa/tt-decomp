#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004158A0_arg0 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};

void func_004158A0(struct func_004158A0_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk8 = (f32) ((fparg0 + arg0->unk10) * arg0->unk18);
    arg0->unkC = (f32) ((fparg1 + arg0->unk14) * arg0->unk1C);
}
