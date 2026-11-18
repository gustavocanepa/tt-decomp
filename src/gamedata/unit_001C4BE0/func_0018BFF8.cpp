#include "types.h"

struct Buf {
    void *ptr;
    char pad[0xC];
};

extern "C" void func_0018ACD8(struct Buf *arg0);
extern "C" void func_001AE2E0(void *arg0);
extern "C" void func_0018AC80(struct Buf *arg0, s32 arg1);

extern "C" void func_0018BFF8(void) {
    struct Buf buf;

    func_0018ACD8(&buf);
    func_001AE2E0((char *)buf.ptr + 0x2A0);
    func_0018AC80(&buf, 2);
}
