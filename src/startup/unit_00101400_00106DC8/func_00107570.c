/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00101B00(s32, s32);                    /* extern */
s32 func_00107B30();                            /* extern */
s32 func_0047DA88();                            /* extern */
s32 func_004A5688();                            /* extern */
s32 func_004AEE40();                            /* extern */

void func_00107570(s32 arg0, s32 arg1) {
    func_004AEE40();
    func_004A5688();
    func_00101B00(arg0, arg1);
    func_0047DA88();
    func_00107B30();
}
