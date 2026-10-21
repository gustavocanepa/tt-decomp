#include "types.h"

extern s32 D_00586A6C;
extern "C" s32 func_00455858(s32 *arg0);

extern "C" s32 func_004559D8(s32 *arg0) {
    *arg0 = D_00586A6C;
    return func_00455858(arg0);
}
