#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

typedef struct { s16 d; s16 pad; s32 (*fn)(void *, s32); } E;
f32 func_00322080(s32, f32);
struct func_0031C428_arg0 {
    char pad0[0xA4C];
    s32 unkA4C;
};

f32 func_0031C428(s8 *arg0, f32 fparg0) {
    f32 var_f0;
    s32 temp_v0;
    E *e = (E *)(*(s8 **)arg0 + 0xE0);
    temp_v0 = e->fn(arg0 + e->d, ((struct func_0031C428_arg0 *)arg0)->unkA4C);
    var_f0 = 0x1.9000000000000p+6f;
    if (temp_v0 != 0) {
        var_f0 = func_00322080(temp_v0, fparg0);
        if (var_f0 < 0x1.9999980000000p-4f) {
            var_f0 = 0x1.9999980000000p-4f;
        }
    }
    return var_f0;
}
