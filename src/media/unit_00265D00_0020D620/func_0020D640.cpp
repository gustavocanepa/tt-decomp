#include "types.h"

struct Obj {
    char pad[0xAC];
    u32 f98;
};

extern "C" s32 func_0020D6B8(Obj *arg0);

extern "C" s32 func_0020D640(Obj *arg0) {
    s32 r = func_0020D6B8(arg0);
    if (r == 0) {
        return 0;
    }
    u32 a = arg0->f98;
    if (a & 0xF00) {
        u32 x = ((a >> 4) ^ a) & (a >> 8) & 0xF;
        return x == 0;
    }
    if (a & 0xF0) {
        u32 y = (a >> 4) & a & 0xF;
        return y != 0;
    }
    return 1;
}
