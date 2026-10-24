#include "types.h"

struct Obj0043C148 {
    char pad[0x2D];
    s8 unk2D;
};

extern "C" s8 func_00403DA8(Obj0043C148 *arg0, s32 arg1) {
    s8 var_v0;

    var_v0 = 0;
    if (arg1 == 0) {
        var_v0 = arg0->unk2D;
    }
    return var_v0;
}
