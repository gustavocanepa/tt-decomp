#include "types.h"

struct Obj { char pad[0xC]; s32 unkC; };

extern "C" void func_003BD528(Obj **arg0, s32 arg1) {
    (*arg0)->unkC = arg1;
}
