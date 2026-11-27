#include "types.h"

extern "C" f32 func_003EB720(f32 fparg0) {
    f32 x = fparg0;
    x = x - 128.0f;
    if (x < 0.0f) {
        x += 8.0f;
        x = x / 120.0f;
        if (x > 0.0f) {
            x = 0.0f;
        }
        if (x < -1.0f) {
            x = -1.0f;
        }
    } else {
        x -= 8.0f;
        x = x / 120.0f;
        if (x < 0.0f) {
            x = 0.0f;
        }
        if (x > 1.0f) {
            x = 1.0f;
        }
    }
    return x;
}
