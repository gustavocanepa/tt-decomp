#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00400D78(s32 *, s32);              /* extern */
s32 func_0040BC48(void *, s32);             /* extern */
s32 func_0050E1A8(s32 *);                       /* extern */

extern char D_005D9790[];
void func_00565920(s32 *arg0, s32 arg1) {
    void *temp_s1;
    void *var_s0;

    *arg0 = (s32)D_005D9790;
    if (arg0 != (s32 *)-8) {
        var_s0 = arg0 + 0x12E;
        temp_s1 = arg0 + 2;
        if (temp_s1 != var_s0) {
            do {
                var_s0 -= 0x190;
                func_0040BC48(var_s0, 2);
            } while (temp_s1 != var_s0);
        }
    }
    func_00400D78(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
