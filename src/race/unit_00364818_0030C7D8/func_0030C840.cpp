#include "types.h"

extern "C" f32 func_0030C818(void **arg0, s32 *arg1);

extern "C" s32 func_0030C840(void **arg0, s32 *arg1) {
    return (s32)(func_0030C818(arg0, arg1) * 10.0f);
}
