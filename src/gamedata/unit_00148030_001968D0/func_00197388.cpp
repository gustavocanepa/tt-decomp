#include "types.h"

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_00197200(struct Buf00109C40 *arg0);
extern "C" void func_003F7AC0(s32 arg0);
extern "C" void func_001971A8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00197388(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_00197200(&buf);
    p = buf.ptr;
    func_003F7AC0(p->unk10);
    func_001971A8(&buf, 2);
}
