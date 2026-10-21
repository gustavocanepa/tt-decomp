#include "types.h"

struct Obj { char pad[4]; s32 unk4; };

extern "C" void func_003BD508(Obj **arg0, s32 arg1) {
    (*arg0)->unk4 = arg1;
}
