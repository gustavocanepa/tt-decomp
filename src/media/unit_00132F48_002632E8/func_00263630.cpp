#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00262C60(struct Buf00109C40 *arg0);
extern "C" void func_00263CE8(s32 arg0);
extern "C" void func_00262C08(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00263630(void) {
    struct Buf00109C40 buf;

    func_00262C60(&buf);
    func_00263CE8(buf.unk0);
    func_00262C08(&buf, 2);
}
