#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00284978(struct Buf00109C40 *arg0);
extern "C" void func_00285000(s32 arg0);
extern "C" void func_00284920(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00284CF8(void) {
    struct Buf00109C40 buf;

    func_00284978(&buf);
    func_00285000(buf.unk0);
    func_00284920(&buf, 2);
}
