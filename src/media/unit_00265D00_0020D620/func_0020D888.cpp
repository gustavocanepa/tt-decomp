#include "types.h"

struct Obj { char pad[0xAC]; s32 unk98; };

extern "C" u64 func_0020D888(Obj *arg0) {
    u64 v = arg0->unk98;
    v = v >> 1;
    return v & 1;
}
