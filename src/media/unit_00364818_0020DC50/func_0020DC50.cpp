#include "types.h"

extern "C" s32 func_0020DBC8(void *);
extern "C" s32 func_0020DAE8(void *);

extern "C" s32 func_0020DC50(void *o) {
    s32 r = 0;
    if (func_0020DBC8(o) || func_0020DAE8(o))
        r = 1;
    return r;
}
