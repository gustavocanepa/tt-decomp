#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381DA8(s8, s32);                      /* extern */

struct func_00382348_arg0 {
    s8 unk0;
    char pad1[0xF];
    s16 unk10;
    char pad12[0xC];
    s8 unk1E;
};

void func_00382348(struct func_00382348_arg0 *arg0, s16 arg1) {
    arg0->unk10 = arg1;
    arg0->unk1E = func_00381DA8(arg0->unk0, 0);
}
