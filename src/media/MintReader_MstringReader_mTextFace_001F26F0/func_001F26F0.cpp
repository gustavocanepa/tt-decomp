#include "types.h"

struct Obj00245240 {
    char pad[0x12C];
    s32 unk104;
};

extern "C" void func_002590C8(void *arg0, s32 arg1);

extern "C" void *func_001F26F0(void *arg0, struct Obj00245240 *arg1) {
    void *s0 = arg0;

    func_002590C8(arg0, arg1->unk104);
    return s0;
}
