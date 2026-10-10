#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005DAEA0[];
struct func_004B08B8_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x14];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};

void func_004B08B8(struct func_004B08B8_arg0 *arg0) {
    arg0->unk2C = 0;
    arg0->unk28 = 0;
    arg0->unk30 = (s32)D_005DAEA0;
    arg0->unk10 = 0;
}
