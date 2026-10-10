#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0045F2B8_arg0 {
    char pad0[0x48];
    f32 unk48;
    f32 unk4C;
    char pad50[0x14];
    s32 unk64;
};

void func_0045F2B8(struct func_0045F2B8_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk48 = fparg0;
    arg0->unk4C = fparg1;
    arg0->unk64 = 0;
}
