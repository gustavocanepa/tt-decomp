#include "types.h"

struct Struct_003A4A78 {
    u8 unk0;
    char pad1[0x53];
    f32 unk54;
};

extern "C" s32 func_00359DB0(Struct_003A4A78 *arg0) {
    s32 var_v0;

    if (arg0->unk0 == 0) {
        return 0;
    }
    var_v0 = 1;
    if (!(arg0->unk54 > 0.0f)) {
        var_v0 = 0;
    }
    return var_v0;
}
