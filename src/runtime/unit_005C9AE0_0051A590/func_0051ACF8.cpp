#include "types.h"

struct Sub005CBFA8 {
    char pad0[0x68];
    s32 unk68;
};

struct S005CBFA8 {
    char pad0[0x10];
    Sub005CBFA8 *unk10;
};

extern "C" f32 func_0051ACF8(struct S005CBFA8 *arg0) {
    return (f32)arg0->unk10->unk68 * 0.0078125f;
}
