#include "types.h"

extern "C" {
f32 func_003E5C08(f32 *arg0, f32 fparg0);            /* extern */

struct func_003E1C58_arg0 {
    char pad0[4];
    f32 unk4;
};

s32 func_003E1C58(f32 *arg0, f32 *arg1, s32 arg2, f32 fparg0) {
    f32 slot[4];
    f32 t = func_003E5C08(arg1, -0x1.921FB4p+1f);
    slot[0] = t;
    f32 v = fparg0 * 0x1.69E954p+0f;
    if (v <= t) {
        if (arg2 != 0) {
            ((struct func_003E1C58_arg0 *)arg0)->unk4 = v;
        }
        return 0;
    }
    f32 nv = -v;
    if (t <= nv) {
        if (arg2 != 0) {
            ((struct func_003E1C58_arg0 *)arg0)->unk4 = nv;
        }
        return 0;
    }
    ((struct func_003E1C58_arg0 *)arg0)->unk4 = t;
    return 1;
}
}
