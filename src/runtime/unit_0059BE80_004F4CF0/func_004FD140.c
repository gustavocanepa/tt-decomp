/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FC080(s32);                         /* extern */

s32 func_004FD140(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        func_004FC080(arg2);
    }
    return 1;
}
