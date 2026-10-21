#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00247AD8(struct Buf00109C40 *arg0);
extern "C" void func_00249560(s32 arg0);
extern "C" void func_00247A80(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00248358(void) {
    struct Buf00109C40 buf;

    func_00247AD8(&buf);
    func_00249560(buf.unk0);
    func_00247A80(&buf, 2);
}
