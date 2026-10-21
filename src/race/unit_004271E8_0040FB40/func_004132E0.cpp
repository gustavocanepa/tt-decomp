#include "types.h"

struct Obj {
    s32 pad0;
    s32 count;
};

extern "C" s32 *func_004130B8(Obj *, s32) throw();
extern "C" s32 *func_004130E8(Obj *, s32) throw();
extern "C" s32 *func_00413120(Obj *, s32) throw();

extern "C" s32 func_004132E0(Obj *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 best = -1;

    for (i = 0; i < arg0->count; i++) {
        if (*func_004130E8(arg0, i) == -1) {
            continue;
        }
        if (arg1 != *func_004130B8(arg0, i)) {
            continue;
        }
        if (arg2 != *func_00413120(arg0, i)) {
            continue;
        }
        best = i;
        break;
    }
    return best;
}
