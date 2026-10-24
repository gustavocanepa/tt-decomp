#include "types.h"

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" void func_0015A690(void *arg0, int arg1);
extern "C" s32 func_0015A6E8(void *arg0);
extern "C" void func_003FC378(s32 arg0);

extern "C" void func_00163768(void) {
    struct Buf buf;
    struct Inner *p;

    func_0015A6E8(&buf);
    p = buf.ptr;
    func_003FC378(p->unk10 + 0x1230);
    func_0015A690(&buf, 2);
}
