/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA830(s32);                         /* extern */

extern char D_005A0D50[];
extern char D_0078A600[];
s32 func_004DDD10(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 temp_a0;

    if (*(s32 *)D_005A0D50 == 0) {
        return 0;
    }
    *(s32 *)D_005A0D50 = 0;
    temp_a0 = *(s32 *)D_0078A600;
    if (temp_a0 >= 0) {
        func_004FA830(temp_a0);
    }
    return 1;
}
