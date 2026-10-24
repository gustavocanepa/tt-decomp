#include "types.h"

struct S0047DAE0 {
    char pad0[0x47];
    u8 unk47;
};

extern "C" f32 func_004447F8(S0047DAE0 *arg0) {
    return (f32)arg0->unk47 * 0.0078125f;
}
