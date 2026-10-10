#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381BB8(s8, s32);                      /* extern */

struct func_00382188_arg0 {
    s8 unk0;
    char pad1[0x2];
    s8 unk3;
    char pad4[0x12];
    s8 unk16;
};

void func_00382188(struct func_00382188_arg0 *arg0, s8 arg1) {
    arg0->unk3 = arg1;
    arg0->unk16 = func_00381BB8(arg0->unk0, 0);
}
