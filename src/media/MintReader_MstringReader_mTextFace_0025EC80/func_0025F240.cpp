#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0025E718(struct Buf00109C40 *arg0);
extern "C" void func_0025FEC8(s32 arg0);
extern "C" void func_0025E6C0(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0025F240(void) {
    struct Buf00109C40 buf;

    func_0025E718(&buf);
    func_0025FEC8(buf.unk0);
    func_0025E6C0(&buf, 2);
}
