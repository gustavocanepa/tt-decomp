/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00406918();                                /* extern */
s32 func_00406B18(s32, s32);                    /* extern */

void func_00406A10(s32 arg0, s32 arg1, s32 arg2) {
    func_00406B18(arg0, func_00406918() + arg2);
}
