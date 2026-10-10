/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002D5E18(s32);                         /* extern */
s32 func_0046F0F8(s32);                     /* extern */
s32 func_004702D8(s32, f32);                /* extern */
s32 func_00477DC0(s32);                         /* extern */

void func_002D5DC8(s32 arg0, s32 arg1, f32 fparg0) {
    func_00477DC0(arg1);
    func_004702D8(0x21, fparg0);
    func_0046F0F8(6);
    func_002D5E18(arg0);
}
