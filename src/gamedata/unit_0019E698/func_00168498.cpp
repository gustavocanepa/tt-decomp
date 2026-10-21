#include "types.h"

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_001680E8(struct Buf00109C40 *arg0);
extern "C" void func_003FE7B0(s32 arg0);
extern "C" void func_00168090(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00168498(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_001680E8(&buf);
    p = buf.ptr;
    func_003FE7B0(p->unk10);
    func_00168090(&buf, 2);
}
