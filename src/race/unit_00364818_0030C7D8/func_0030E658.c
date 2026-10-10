#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_002FD3D0(s32);                             /* extern */

struct func_0030E658_arg0 {
    char pad0[0x10];
    f32 unk10;
};

f32 func_0030E658(void *arg0) {
    return func_002FD3D0(arg0 + 0x24) * ((struct func_0030E658_arg0 *)arg0)->unk10;
}
