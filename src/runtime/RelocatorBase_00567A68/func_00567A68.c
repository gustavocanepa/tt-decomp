#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D9C30[];
struct func_00567A68_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x6C];
    s32 unk74;
    s32 unk78;
    s32 unk7C;
};

void func_00567A68(struct func_00567A68_arg0 *arg0) {
    arg0->unk4 = 0;
    arg0->unk74 = 0;
    arg0->unk0 = (s32)D_005D9C30;
    arg0->unk78 = 0;
    arg0->unk7C = 0;
}
