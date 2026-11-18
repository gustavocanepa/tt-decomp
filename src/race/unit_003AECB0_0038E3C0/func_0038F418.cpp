#include "types.h"

struct E_00621978 {
    s32 unk0;
    s32 unk4;
};

extern "C" E_00621978 D_005848E8[];

extern "C" s32 func_0038F418(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg0 < 9) {
        var_v0 = D_005848E8[arg0].unk0 + arg1 * 8;
    }
    return var_v0;
}
