#include "types.h"

extern "C" f32 func_0032E068(f32 *arg0) {
    f32 v = *arg0;

    if (v <= -1.0f) {
        v = -1.0f;
    }
    if (v >= 1.0f) {
        v = 1.0f;
    }
    return v;
}
