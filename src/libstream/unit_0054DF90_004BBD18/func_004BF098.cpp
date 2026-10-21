#include "types.h"

struct Struct0086F800 {
    s32 unk0;
    char pad[0x3C];
    s32 unk40;
};

extern Struct0086F800 D_00776E40;

extern "C" void func_004F4348(s32 arg0);
extern "C" void func_004F45D8(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_004BF098(s32 arg0) {
    func_004F4348(D_00776E40.unk0);
    D_00776E40.unk40 = arg0;
    func_004F45D8(&D_00776E40, 2, 0, 0, 0);
}
