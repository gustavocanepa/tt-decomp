/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001DAE00(s32, s32);                    /* extern */
s32 func_00202538(s32, s32, s32);                      /* extern */

struct func_0020B408_arg0 {
    char pad0[0xA8];
    s32 unkA8;
};

s32 func_0020B408(s32 arg0, s32 arg1) {
    s32 v = ((struct func_0020B408_arg0 *)arg0)->unkA8;
    if (v != 0) {
        func_00202538(v, arg1, arg0);
    }
    func_001DAE00(arg0, arg1);
}
