#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005C4548[];
void func_0029BB98(void *, s32 *);
s32 func_002A7618(void *);
struct hFunctionObject__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void hFunctionObject__structor_0(void *arg0, s32 arg1) {
    s32 sp[4];
    func_002A7618(arg0);
    ((struct hFunctionObject__structor_0_arg0 *)arg0)->unk4 = (s32)D_005C4548;
    sp[0] = arg1;
    func_0029BB98((s8 *)arg0 + 0x10, sp);
}
