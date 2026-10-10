/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00206DD8(s32);                             /* extern */
s32 func_00210118();                                /* extern */

s32 func_00210088(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_00210118();
    if (temp_v0 != 0) {
        return func_00206DD8(temp_v0);
    }
    return arg0;
}
