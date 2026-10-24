#include "types.h"

struct Buf00109C40 {
    s32 unk0;
    char pad4[0xC];
};

extern "C" void func_001E6480(struct Buf00109C40 *arg0);
extern "C" void func_001E95D0(s32 arg0);
extern "C" void func_001E6428(struct Buf00109C40 *arg0, s32 arg1);

extern "C" void func_001E6CD8(void) {
    struct Buf00109C40 buf;

    func_001E6480(&buf);
    func_001E95D0(buf.unk0);
    func_001E6428(&buf, 2);
}
