#include "types.h"

struct Obj { char pad[0x5C]; f32 unk5C; };

extern "C" s32 func_003CF810(Obj *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk5C = fparg1;
    return 1;
}
