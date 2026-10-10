#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AF7F8_arg0 {
    char pad0[0x142FC];
    s32 unk142FC;
    f32 unk14300;
    f32 unk14304;
};

void func_001AF7F8(struct func_001AF7F8_arg0 *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    arg0->unk142FC = arg1;
    arg0->unk14300 = fparg0;
    arg0->unk14304 = fparg1;
}
