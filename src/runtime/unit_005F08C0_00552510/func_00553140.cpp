#include "types.h"

struct Elem005F5710 {
    char pad0[0x18];
    f32 unk18;
};

extern "C" f32 func_00553140(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 0x6C;
    return ((struct Elem005F5710 *)arg0)->unk18;
}
