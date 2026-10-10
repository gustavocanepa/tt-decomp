#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005A7DC8[];
s32 func_002A7618(void *);
void func_003FC8C8(void *);
struct mOption__structor_1_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
};

void mOption__structor_1(void *arg0, s32 arg1) {
    func_002A7618(arg0);
    ((struct mOption__structor_1_arg0 *)arg0)->unk4 = (s32)D_005A7DC8;
    ((struct mOption__structor_1_arg0 *)arg0)->unk10 = arg1;
    func_003FC8C8((s8 *)arg0 + 0x18);
}
