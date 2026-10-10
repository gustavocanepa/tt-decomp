/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00404AC8(s32, s32);                /* extern */
s32 func_00403FD0(s32, s32);                /* extern */
s32 func_00404310(s32, s32);                /* extern */
s32 func_00404728(s32, s32);                /* extern */

void func_00403328(s32 arg0) {
    func_00404AC8(arg0 + 0x18, 0);
    func_00403FD0(arg0 + 0x48, 0);
    func_00404310(arg0 + 0x64, 0);
    func_00404728(arg0 + 0x8C, 0);
}
