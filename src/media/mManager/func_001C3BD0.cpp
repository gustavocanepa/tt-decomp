#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001C2A78(struct Buf00109C40 *arg0);
extern "C" void func_001CCCA0(s32 arg0);
extern "C" void func_001C2A20(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001C3BD0(void) {
    struct Buf00109C40 buf;

    func_001C2A78(&buf);
    func_001CCCA0(buf.unk0);
    func_001C2A20(&buf, 2);
}
