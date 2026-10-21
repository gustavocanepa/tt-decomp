#include "types.h"

extern s32 D_00585C94;
extern "C" s32 SPEC_DATABASE__DatabaseTable__getRow(s32, s32, s32);

extern "C" s32 func_0040F5F8(u64 id, s32 x) {
    return SPEC_DATABASE__DatabaseTable__getRow(D_00585C94, (s32)(id & 0xFFFFFFFF), x) != 0;
}
