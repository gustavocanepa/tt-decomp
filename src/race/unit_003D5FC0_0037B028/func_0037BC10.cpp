#include "types.h"

struct Obj003D7648 {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_0039FF18(s32 arg0, s8 arg1, f32 arg2);

extern "C" s32 func_0037BC10(Obj003D7648 *arg0, s32 arg1) {
    char *p = (char *)arg0 + arg1;
    return func_0039FF18(arg0->unk4, *(s8 *)(p + 0xC), 0.0f);
}
