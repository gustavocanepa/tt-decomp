#include "types.h"

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_0015A6E8(struct Buf00109C40 *arg0);
extern "C" void func_003FCE58(s32 arg0);
extern "C" void func_0015A690(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00164A30(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_0015A6E8(&buf);
    p = buf.ptr;
    func_003FCE58(p->unk10);
    func_0015A690(&buf, 2);
}
