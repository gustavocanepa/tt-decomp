#include "types.h"

struct Obj { char pad[0x1148]; u8 unk9C; };

extern "C" u64 func_00562CA8(Obj *arg0) {
    u64 v = arg0->unk9C;
    return v >> 7;
}
