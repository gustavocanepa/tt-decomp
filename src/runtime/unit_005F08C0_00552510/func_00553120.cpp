#include "types.h"

struct Elem {
    char pad[0x14];
    f32 unk14;
};

extern "C" f32 func_00553120(char *arg0, s32 arg1) {
    arg0 = arg0 + arg1 * 0x6C;
    return ((Elem *)arg0)->unk14;
}
