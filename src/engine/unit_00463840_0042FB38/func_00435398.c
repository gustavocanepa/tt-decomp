#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00434440(s32);                             /* extern */
s32 func_00434578(s32);                             /* extern */
s32 func_00434748(s32);                             /* extern */
s32 func_004348C0(s32);                         /* extern */
s32 func_00434B90();                                /* extern */

void func_00435398(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 temp_v0;

    temp_v0 = func_00434B90();
    *arg0 = func_00434440(temp_v0);
    *arg1 = func_00434578(temp_v0);
    *arg2 = func_00434748(temp_v0);
    func_004348C0(temp_v0);
}
