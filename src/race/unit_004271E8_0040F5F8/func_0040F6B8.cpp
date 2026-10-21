#include "types.h"

extern s32 D_00585CA4;
extern "C" s32 SPEC_DATABASE__DatabaseTable__getRow(s32, s32, s32);

extern "C" s32 func_0040F6B8(u64 id, s32 x) {
    return SPEC_DATABASE__DatabaseTable__getRow(D_00585CA4, (s32)(id & 0xFFFFFFFF), x) != 0;
}
