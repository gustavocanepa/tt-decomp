#include "types.h"

struct Struct_001460C8 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" s32 func_00408B58(s32 arg0);
extern "C" s32 func_0040DB18(s32 arg0);
extern "C" void func_00131D90(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_00131E70(Struct_001460C8 *arg0, s32 arg1, s32 arg2) {
    s32 temp = func_00408B58(arg0->unk14);
    temp = func_0040DB18(temp);
    func_00131D90(arg0, arg1, arg2, temp);
}
