#include "types.h"

struct Elem {
    char pad[0x4];
    f32 unk4;
};

extern "C" f32 func_00417FE8(char *arg0, s32 arg1) {
    arg1 = arg1 + 0x98;
    arg0 = arg0 + arg1 * 4;
    return ((Elem *)arg0)->unk4;
}
