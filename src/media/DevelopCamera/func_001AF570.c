#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AF570_arg0 {
    char pad0[0x14094];
    f32 unk14094;
    f32 unk14098;
    f32 unk1409C;
    f32 unk140A0;
};

void func_001AF570(struct func_001AF570_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    arg0->unk14094 = fparg0;
    arg0->unk14098 = fparg1;
    arg0->unk1409C = fparg2;
    arg0->unk140A0 = fparg3;
}
