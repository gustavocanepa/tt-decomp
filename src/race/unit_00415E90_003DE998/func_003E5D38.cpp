#include "types.h"

extern "C" f32 func_004A5DE0(f32);

extern "C" void func_003E5D38(f32 *arg0) {
    f32 temp_f0 = *arg0;
    f32 buf[4];

    buf[0] = temp_f0;
    func_004A5DE0(temp_f0);
}
