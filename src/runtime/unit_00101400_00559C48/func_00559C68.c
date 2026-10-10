#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559C68_arg0 {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x1150];
    s32 unk1168;
};

void func_00559C68(struct func_00559C68_arg0 *arg0) {
    arg0->unk1168 = (s32) (arg0->unk14 + 0x100);
}
