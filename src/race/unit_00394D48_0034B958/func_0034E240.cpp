#include "types.h"

struct Struct_00320108 {
    char pad0[0x90];
    float unk90;
};

extern "C" void func_0034E690(s32 arg0, float arg1, float arg2);

extern "C" void func_0034E240(struct Struct_00320108 *arg0, s32 arg1) {
    func_0034E690(arg1, arg0->unk90, arg0->unk90);
}
