#include "types.h"

extern "C" f32 func_004A5D18(f32);

extern "C" void func_003E5CE8(f32 *arg0) {
    f32 temp_f0 = *arg0;
    f32 buf[4];

    buf[0] = temp_f0;
    func_004A5D18(temp_f0);
}
