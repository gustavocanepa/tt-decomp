#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001DF250(struct Buf00109C40 *arg0);
extern "C" void func_001E56B0(s32 arg0);
extern "C" void func_001DF1F8(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001DFC08(void) {
    struct Buf00109C40 buf;

    func_001DF250(&buf);
    func_001E56B0(buf.unk0);
    func_001DF1F8(&buf, 2);
}
