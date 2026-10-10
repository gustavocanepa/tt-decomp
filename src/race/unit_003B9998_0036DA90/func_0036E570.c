#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 RacePS2Base__getMasterVolume();                                /* extern */

struct func_0036E570_arg0 {
    char pad0[0xE1C];
    s32 unkE1C;
    char padE20[0xC1DC];
    f32 unkCFFC;
};

f32 func_0036E570(struct func_0036E570_arg0 *arg0) {
    f32 var_f1;

    var_f1 = RacePS2Base__getMasterVolume();
    if (arg0->unkE1C > 0) {
        var_f1 *= arg0->unkCFFC;
    }
    return var_f1;
}
