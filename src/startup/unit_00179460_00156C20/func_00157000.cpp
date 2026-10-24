#include "types.h"

struct Inner {
    char pad0[0x20];
    s32 unk20;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_00156538(struct Buf00109C40 *arg0);
extern "C" void func_00198A08(s32 arg0);
extern "C" void func_001564E0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00157000(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_00156538(&buf);
    p = buf.ptr;
    func_00198A08(p->unk20);
    func_001564E0(&buf, 2);
}
