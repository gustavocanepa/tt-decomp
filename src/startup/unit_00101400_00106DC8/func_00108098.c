/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00481978(s32);                     /* extern */
s32 func_004A8268(s32, s32);                /* extern */

extern char D_005DCFA0[];
extern char D_005DE838[];
extern char D_005DE8E0[];
void func_00108098(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (func_004A8268((s32)D_005DCFA0, (s32)D_005DE838) == 0) {
        func_00481978((s32)D_005DE8E0);
    }
}
