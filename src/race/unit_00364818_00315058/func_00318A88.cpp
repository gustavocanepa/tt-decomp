#include "types.h"

struct Obj {
    char pad[0x28];
    f32 unk28;
};

extern "C" s32 func_00318950(f32 arg0);

extern "C" s32 func_00318A88(Obj *arg0) {
    return func_00318950(arg0->unk28);
}
