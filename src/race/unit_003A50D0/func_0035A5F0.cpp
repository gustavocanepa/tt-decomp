#include "types.h"

struct S003A5268 {
    char pad0[0x2C];
    s32 unk2C;
};

extern "C" void func_004F7B74(void *arg0);

extern "C" void func_0035A5F0(struct S003A5268 *arg0, s32 arg1, s32 arg2) {
    arg0->unk2C = arg2;
    func_004F7B74((char *)arg0 + 0x30);
}
