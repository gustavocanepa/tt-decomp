#include "types.h"

struct Sub005CC0A8 {
    char pad0[0x78];
    s32 unk78;
};

struct S005CC0A8 {
    char pad0[0x10];
    Sub005CC0A8 *unk10;
};

extern "C" f32 func_0051ADF8(struct S005CC0A8 *arg0) {
    return (f32)arg0->unk10->unk78 * 0.0078125f;
}
