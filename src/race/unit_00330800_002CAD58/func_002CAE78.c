#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_005857DC[];
struct func_002CAE78_arg0 {
    char pad0[0x14];
    f32 unk14;
};

void func_002CAE78(struct func_002CAE78_arg0 *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(*(void **)D_005857DC, s32 *, 0x179C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        arg0->unk14 = 0x1.5555540000000p+0f;
        return;
    case 1:
        arg0->unk14 = 0x1.c71c700000000p+0f;
        return;
    case 2:
        arg0->unk14 = 0x1.8000000000000p+0f;
        return;
    case 3:
        arg0->unk14 = 0x1.0000000000000p+0f;
        return;
    }
}
