#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_002871B0(struct Buf00109C40 *arg0);
extern "C" void func_00287AC8(s32 arg0);
extern "C" void func_00287158(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00287658(void) {
    struct Buf00109C40 buf;

    func_002871B0(&buf);
    func_00287AC8(buf.unk0);
    func_00287158(&buf, 2);
}
