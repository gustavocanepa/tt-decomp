/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GranTurismo4__GameObjectManager__append(s32, s32);                    /* extern */
s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */
s32 func_004ACC88(s32, s32);                    /* extern */
s32 func_004AC7F0(s32, s32);                        /* extern */

void func_00108738(s32 arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0xC;
    func_004A4D68(temp_s2);
    if (func_004AC7F0(arg0, arg1) != 0) {
        func_004ACC88(arg0, arg1);
        GranTurismo4__GameObjectManager__append(arg0, arg1);
    }
    func_004A4DD8(temp_s2);
}
