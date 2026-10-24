#include "types.h"

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf00109C40 {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" s32 func_00141000(struct Buf00109C40 *arg0);
extern "C" void func_003FAC90(s32 arg0);
extern "C" void func_00140FA8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00141C30(void) {
    struct Buf00109C40 buf;
    struct Inner *p;

    func_00141000(&buf);
    p = buf.ptr;
    func_003FAC90(p->unk10);
    func_00140FA8(&buf, 2);
}
