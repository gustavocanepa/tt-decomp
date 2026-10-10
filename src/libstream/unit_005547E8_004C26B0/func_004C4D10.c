#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004C6FE0(s32);                         /* extern */

extern char D_0059D4A8[];
struct func_004C4D10_arg0 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
};

void func_004C4D10(struct func_004C4D10_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = func_004C6FE0((s32)D_0059D4A8);
    arg0->unk18 = temp_v0;
    arg0->unk14 = 1;
}
