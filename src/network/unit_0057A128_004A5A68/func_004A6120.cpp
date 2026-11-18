#include "types.h"

extern "C" f32 func_004A5EE8(f32 arg0);
extern "C" f32 func_004A6008(f32 arg0);

extern "C" f32 func_004A6120(f32 arg0, f32 arg1) {
    f32 result = func_004A6008(arg0);
    return func_004A5EE8(arg1 * result);
}
