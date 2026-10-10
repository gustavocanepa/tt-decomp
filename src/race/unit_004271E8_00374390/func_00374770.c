#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003CCEE0(s32);                         /* extern */
s32 func_0041F840(s32);                         /* extern */

s32 func_00374770(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_003CCEE0(arg0 + 0xDF0);
        func_0041F840(arg1);
    }
}
