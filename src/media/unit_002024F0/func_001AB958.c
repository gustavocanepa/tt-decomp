#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AB958_arg0 {
    f32 unk0;
    char pad4[0x4];
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

void func_001AB958(struct func_001AB958_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk0 = fparg0;
    arg0->unk8 = fparg1;
    arg0->unkC = fparg2;
    arg0->unk10 = fparg3;
}
