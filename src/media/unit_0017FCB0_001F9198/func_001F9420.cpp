#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001F8CD0(struct Buf00109C40 *arg0);
extern "C" void func_001FA1A8(s32 arg0);
extern "C" void func_001F8C78(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001F9420(void) {
    struct Buf00109C40 buf;

    func_001F8CD0(&buf);
    func_001FA1A8(buf.unk0);
    func_001F8C78(&buf, 2);
}
