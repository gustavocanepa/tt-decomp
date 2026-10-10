/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B5D28(s32);                         /* extern */
s32 func_004C72B8(s32, s32);                /* extern */

extern char D_0059D4A8[];
void func_0042DC98(s32 arg0) {
    func_004C72B8((s32)D_0059D4A8, arg0);
    func_004B5D28(arg0 == 0);
}
