#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005C50E8[];
void func_002A2558(void *, s32 *);
void func_002A7590(void *, s32);
s32 func_002A7618(void *);
struct hMethodObject__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void hMethodObject__structor_0(void *arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    func_002A7618(arg0);
    ((struct hMethodObject__structor_0_arg0 *)arg0)->unk4 = (s32)D_005C50E8;
    func_002A7590((s8 *)arg0 + 0x10, arg1);
    sp[0] = arg2;
    func_002A2558((s8 *)arg0 + 0x14, sp);
}
