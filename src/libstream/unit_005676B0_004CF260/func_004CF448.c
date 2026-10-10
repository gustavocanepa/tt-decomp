/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CF438(s32);                         /* extern */
s32 func_004A48C0(s32);                     /* extern */
s32 func_004A48D8(s32, s32);            /* extern */

extern char D_005A0B68[];
extern char D_005A0B88[];
void func_004CF448(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_s0;
    s32 var_s1;

    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            var_s1 = 3;
            var_s0 = (s32)D_005A0B68;
            var_a0 = (s32)D_005A0B68;
            do {
                var_s0 += 8;
                var_s1 -= 1;
                func_004CF438(var_a0);
                var_a0 = var_s0;
            } while (var_s1 != -1);
        }
        if (arg1 == 0xFFFF) {
            if (arg0 == 1) {
                func_004A48C0((s32)D_005A0B88);
            }
            if (arg0 == 0) {
                func_004A48D8((s32)D_005A0B88, 2);
            }
        }
    }
}
