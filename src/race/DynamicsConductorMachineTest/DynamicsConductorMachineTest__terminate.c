#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002F3028();                            /* extern */
s32 func_002FBF80(s32);                         /* extern */
s32 DynamicsConductorMachineTest__getTestMode(s32);                             /* extern */

void DynamicsConductorMachineTest__terminate(s32 arg0) {
    s32 temp_v0;

    func_002F3028();
    temp_v0 = DynamicsConductorMachineTest__getTestMode(arg0);
    if (temp_v0 >= 3) {
        return;
    }
    if (temp_v0 <= 0) {
        return;
    }
    func_002FBF80(arg0);
}
