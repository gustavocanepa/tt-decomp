#include "types.h"

extern "C" void *func_004172F0(void);
extern "C" f32 func_00417188(void *p);

extern "C" f32 SpecialCarGeometry__GetSeatPosition_Z(void) {
    void *p = func_004172F0();
    if (p) {
        return func_00417188(p) + 1.0815553665161133f;
    }
    return 1.0815553665161133f;
}
