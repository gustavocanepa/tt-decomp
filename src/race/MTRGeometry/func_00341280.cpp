#include "types.h"

extern "C" void *func_004172F0(void);
extern "C" f32 func_00417230(void *p);

extern "C" f32 func_00341280(void) {
    void *p = func_004172F0();
    if (p) {
        return func_00417230(p) + 0.1f;
    }
    return 0.1f;
}
