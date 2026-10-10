/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0041DCD8(s32);                         /* extern */
s32 func_0041DFB0(s32, s32);                        /* extern */

void func_0041A500(s32 *arg0, s32 *arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = func_0041DFB0(*arg1, arg2);
    *arg0 = temp_v0;
    func_0041DCD8(temp_v0);
}
