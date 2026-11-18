#include "types.h"

extern "C" f32 func_0032D0B8(f32 x) {
    if (x <= 0.0f) {
        x = 0.0f;
    }
    if (x >= 1.0f) {
        x = 1.0f;
    }
    if (x < 0x1.999998p-2f) {
        return x / 0x1.999998p-2f * 70.0f;
    }
    return (x - 0x1.999998p-2f) / 0x1.333334p-1f * 40.0f + 110.0f;
}
