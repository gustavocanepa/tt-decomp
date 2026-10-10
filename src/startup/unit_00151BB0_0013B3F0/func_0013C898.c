/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_001CE3D0(s32 *, s32);              /* extern */
s32 func_002C0FE8(s32);                         /* extern */
s32 func_002C1050(s32);                         /* extern */

struct func_0013C898_arg0 {
    char pad0[0x90];
    s32 unk90;
};

void func_0013C898(void *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 temp_v0;

    if ((arg0 + 0x90) != arg1) {
        temp_s0 = *arg1;
        if (temp_s0 != 0) {
            func_002C0FE8(temp_s0);
        }
        temp_v0 = ((struct func_0013C898_arg0 *)arg0)->unk90;
        if (temp_v0 != 0) {
            func_002C1050(temp_v0);
        }
        ((struct func_0013C898_arg0 *)arg0)->unk90 = temp_s0;
    }
    func_001CE3D0(arg1, 2);
}
