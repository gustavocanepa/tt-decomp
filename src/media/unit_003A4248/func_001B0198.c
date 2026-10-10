#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_003F1740(void *, s32);                     /* extern */

struct func_001B0198_arg0 {
    char pad0[0x68];
    s32 unk68;
    s32 unk6C;
};

f32 func_001B0198(void *arg0) {
    if (((struct func_001B0198_arg0 *)arg0)->unk6C != 0) {
        return func_003F1740(arg0 + 0x70, ((struct func_001B0198_arg0 *)arg0)->unk68);
    }
    return 0x0.0p+0f;
}
