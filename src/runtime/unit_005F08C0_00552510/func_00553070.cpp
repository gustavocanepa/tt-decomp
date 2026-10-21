#include "types.h"

struct Elem {
    char pad[0x20];
    f32 unk20;
};

extern "C" f32 func_00553070(char *arg0, s32 arg1) {
    return ((Elem *)(arg0 + arg1 * 0x6C))->unk20;
}
