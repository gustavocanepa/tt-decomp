#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005C9630[];
struct func_0030BFE0_arg0 {
    s32 unk0;
    s8 unk4;
    char pad5[0x3];
    s32 unk8;
};

void func_0030BFE0(struct func_0030BFE0_arg0 *arg0) {
    arg0->unk4 = 0;
    arg0->unk0 = 0;
    arg0->unk8 = (s32)D_005C9630;
}
