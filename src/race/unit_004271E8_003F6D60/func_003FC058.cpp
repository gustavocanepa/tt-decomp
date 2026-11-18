#include "types.h"

extern "C" s32 func_00400CF0(s32 arg0);
extern "C" s32 func_004052D8(s32 arg0);

extern "C" s32 func_003FC058(s32 arg0) {
    return func_00400CF0(func_004052D8(arg0 + 0x7D08) + 0x7D1C);
}
