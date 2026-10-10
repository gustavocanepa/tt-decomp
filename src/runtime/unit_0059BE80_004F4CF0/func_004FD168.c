/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FC130(s32);                         /* extern */

s32 func_004FD168(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        func_004FC130(arg2);
    }
    return 1;
}
