#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041F840(void *);                      /* extern */
s32 func_0041F9B0(void *);                          /* extern */
s32 func_0041FAC8(void *, s32, s32, s32); /* extern */
s32 func_0041FCA0(void *, s32);                 /* extern */
s32 func_00420030(void *, s32);             /* extern */

extern char D_0057A908[];
struct func_001B01D0_arg0 {
    char pad0[0x60];
    s32 unk60;
    s32 unk64;
};
struct func_001B01D0_arg1 {
    char pad0[0x7C];
    s32 unk7C;
};

s32 func_001B01D0(struct func_001B01D0_arg0 *arg0, struct func_001B01D0_arg1 *arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 != NULL) {
        arg0->unk60 = 0;
        arg0->unk64 = 0;
        var_v0 = func_0041F9B0(arg1);
        if (var_v0 != 0) {
            func_0041F840(arg1);
            func_0041FAC8(arg1, arg1->unk7C, (s32)D_0057A908, 2);
            func_0041FCA0(arg1, arg1->unk7C);
            func_00420030(arg1, -1);
            var_v0 = 1;
        }
    }
    return var_v0;
}
