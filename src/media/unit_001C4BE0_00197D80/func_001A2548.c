/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001A1FF8(s32);                         /* extern */
s32 func_004A8268(s32, s32);                        /* extern */
s32 func_004F7B74(s32, s32);                    /* extern */

void func_001A2548(s32 arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x14;
    if (func_004A8268(arg1, temp_s1) != 0) {
        func_001A1FF8(arg0);
    }
    func_004F7B74(temp_s1, arg1);
}
