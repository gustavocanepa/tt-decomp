/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00423EC8();                            /* extern */
s32 GT4Model__BinStreamReader__readArray(s32, s32, s32);           /* extern */

void func_002DDBA8(s32 arg0, s32 arg1) {
    func_00423EC8();
    GT4Model__BinStreamReader__readArray(arg0, arg1, 4);
}
