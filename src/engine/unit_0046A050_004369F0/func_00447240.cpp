#include "types.h"

struct Obj004804E0 {
    char pad0[0x74];
    s32 unk74;
    char pad78[0x30];
    u32 *unkA8;
};

extern "C" void func_00447278(Obj004804E0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_00447240(Obj004804E0 *arg0, s32 arg1) {
    if (arg0->unk74 != 0) {
        func_00447278(arg0, arg1, 0x7FFFFFFF, arg0->unkA8[0], (s32)arg0->unkA8);
    }
}
