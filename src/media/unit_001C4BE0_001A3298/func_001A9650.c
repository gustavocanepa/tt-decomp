/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046F0F8(s32);                     /* extern */
s32 func_004702D8(s32, f32);                /* extern */
s32 func_00470478(s32);                     /* extern */
s32 func_00473F50(s32, s32, s32, s32);  /* extern */
s32 func_00477DC0(s32);                     /* extern */
s32 func_00478C98(s32);                     /* extern */

void func_001A9650(s32 arg0, s32 arg1, f32 fparg0) {
    if (!(fparg0 < 0x1.0000000000000p-7f)) {
        func_00477DC0(0x80000000);
        func_004702D8(0x64, fparg0);
        func_0046F0F8(6);
        func_00478C98(5);
        func_00470478(0);
        func_00473F50(0, 0, arg0, arg1);
    }
}
