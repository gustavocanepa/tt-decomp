#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

extern char D_00582D40[];
extern char D_00582D44[];
extern char D_00582D48[];
void func_002E8690(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_004A45D0(*(s32 *)(s32)D_00582D40);
    *(s32 *)(s32)D_00582D40 = 0;
    *(s32 *)D_00582D44 = 0;
    *(s32 *)D_00582D48 = 0;
}
