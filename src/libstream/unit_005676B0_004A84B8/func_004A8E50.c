#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A8DF0(s32);                             /* extern */
s32 func_004A8E90(s32, s32, s32);               /* extern */

void func_004A8E50(s32 arg0, s32 arg1) {
    func_004A8E90(arg0, func_004A8DF0(arg1), arg1);
}
