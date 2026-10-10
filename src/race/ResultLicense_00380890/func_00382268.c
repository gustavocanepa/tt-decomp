#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381C68(s8, s32);                      /* extern */

struct func_00382268_arg0 {
    s8 unk0;
    char pad1[0x7];
    s16 unk8;
    char padA[0x10];
    s8 unk1A;
};

void func_00382268(struct func_00382268_arg0 *arg0, s16 arg1) {
    arg0->unk8 = arg1;
    arg0->unk1A = func_00381C68(arg0->unk0, 0);
}
