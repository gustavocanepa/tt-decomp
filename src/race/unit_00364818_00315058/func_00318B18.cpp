#include "types.h"

struct Obj {
    char pad[0xD8];
    f32 unkD8;
};

extern "C" s32 func_00318950(f32 arg0);

extern "C" s32 func_00318B18(Obj *arg0) {
    return func_00318950(arg0->unkD8);
}
