#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004ADFA0(s32, s32, s32);           /* extern */
s32 func_004F6678(s32, s32, s32);           /* extern */

extern char D_007739A0[];
s32 func_004A4570(s32 arg0, s32 arg1) {
    s32 temp_s0;
    s32 temp_v0;

    temp_s0 = arg0 * arg1;
    temp_v0 = func_004ADFA0((s32)D_007739A0, temp_s0, 0x10);
    if (temp_v0 != 0) {
        func_004F6678(temp_v0, 0, temp_s0);
    }
    return temp_v0;
}
