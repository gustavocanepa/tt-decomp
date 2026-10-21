#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00139C38(struct Buf00109C40 *arg0);
extern "C" void func_0013C428(s32 arg0);
extern "C" void func_00139BE0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0013A970(void) {
    struct Buf00109C40 buf;

    func_00139C38(&buf);
    func_0013C428(buf.unk0);
    func_00139BE0(&buf, 2);
}
