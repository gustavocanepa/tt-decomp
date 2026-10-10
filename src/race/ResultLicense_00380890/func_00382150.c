#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381B70(s8, s32);                      /* extern */

struct func_00382150_arg0 {
    s8 unk0;
    char pad1[0x1];
    s8 unk2;
    char pad3[0x12];
    s8 unk15;
};

void func_00382150(struct func_00382150_arg0 *arg0, s8 arg1) {
    arg0->unk2 = arg1;
    arg0->unk15 = func_00381B70(arg0->unk0, 0);
}
