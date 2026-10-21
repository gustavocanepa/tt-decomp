#include "types.h"

struct Inner {
    char pad0[0x10];
    s32 unk10;
};

struct Buf {
    struct Inner *ptr;
    char pad4[0xC];
};

extern "C" void func_00141F98(void *arg0, int arg1);
extern "C" s32 func_00141FF0(void *arg0);
extern "C" void func_003F7598(s32 arg0);

extern "C" void func_00149BD8(void) {
    struct Buf buf;
    struct Inner *p;

    func_00141FF0(&buf);
    p = buf.ptr;
    func_003F7598(p->unk10 + 0x1DA0);
    func_00141F98(&buf, 2);
}
