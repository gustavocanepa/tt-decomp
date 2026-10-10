/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00210028();                                /* extern */
s32 func_00257240(s32, s32, s32);               /* extern */

void func_00257200(s32 arg0, s32 arg1) {
    func_00257240(arg0, func_00210028(), arg1);
}
