#include "types.h"

extern "C" s32 func_004A4570(s32 arg0, s32 arg1);

extern "C" s32 func_004A47A0(s32 arg0, s32 arg1, s32 arg2) {
    return func_004A4570(arg1, arg2);
}
