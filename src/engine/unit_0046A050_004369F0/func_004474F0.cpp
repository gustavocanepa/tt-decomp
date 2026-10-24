#include "types.h"

struct Inner { char pad[0x20]; s32 unk20; };
struct Obj { char pad[0x60]; Inner *unk60; };

extern "C" s32 func_004474F0(Obj *arg0) {
    return arg0->unk60->unk20;
}
