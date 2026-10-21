#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_0026E9C0(struct Buf00109C40 *arg0);
extern "C" void func_0026FE20(s32 arg0);
extern "C" void func_0026E968(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_0026EFD8(void) {
    struct Buf00109C40 buf;

    func_0026E9C0(&buf);
    func_0026FE20(buf.unk0);
    func_0026E968(&buf, 2);
}
