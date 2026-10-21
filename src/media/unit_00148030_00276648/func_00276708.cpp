#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_00276388(struct Buf00109C40 *arg0);
extern "C" void func_00276B80(s32 arg0);
extern "C" void func_00276330(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_00276708(void) {
    struct Buf00109C40 buf;

    func_00276388(&buf);
    func_00276B80(buf.unk0);
    func_00276330(&buf, 2);
}
