#include "types.h"

struct Struct_00343A58 {
    char pad0[0x14];
    u8 unk14;
};

extern "C" void func_002E4AE0(Struct_00343A58 *arg0, f32 arg1);

extern "C" void func_002E4BC0(Struct_00343A58 *arg0) {
    if (arg0->unk14 == 0) {
        return func_002E4AE0(arg0, 0.0f);
    }
}
