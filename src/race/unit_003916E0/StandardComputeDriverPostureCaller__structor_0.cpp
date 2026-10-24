#include "types.h"

extern "C" s32 D_00767D18;
extern "C" char D_005CEAC8;

extern "C" void StandardComputeDriverPostureCaller__structor_0(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF && arg0 == 1) {
        D_00767D18 = (s32)&D_005CEAC8;
    }
}
