#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D9050(s32);                         /* extern */
s32 func_002D9078(s32);                         /* extern */
s32 func_002D90A8(s32);                         /* extern */
s32 func_003EB018(s32);                             /* extern */
s32 func_003EB020(s32);                             /* extern */

s32 func_002D8910(s32 arg0, s32 arg1) {
    if (func_003EB020(arg1) & 0x1000) {
        func_002D9050(arg0);
    }
    if (func_003EB020(arg1) & 0x2000) {
        func_002D9078(arg0);
    }
    if (func_003EB018(arg1) & 0x4000) {
        func_002D90A8(arg0);
    }
}
