#include "types.h"

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_00159750(struct Buf00109C40 *arg0);
extern "C" void func_001986F8(s32 arg0);
extern "C" void func_001596F8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0015A0C8(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_00159750(&buf);
    p = buf.ptr;
    func_001986F8(p->unk10);
    func_001596F8(&buf, 2);
}
