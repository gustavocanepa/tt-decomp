#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002A27C8(struct Buf00109C40 *arg0);
extern "C" void hModule__clearModuleValue(s32 arg0);
extern "C" void func_002A2770(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_002A3238(void) {
    struct Buf00109C40 buf;

    func_002A27C8(&buf);
    hModule__clearModuleValue(buf.unk0);
    func_002A2770(&buf, 2);
}
