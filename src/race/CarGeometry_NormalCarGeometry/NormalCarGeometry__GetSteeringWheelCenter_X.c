#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00341800(void *, f32);                     /* extern */
f32 *func_00341AD8();                               /* extern */

struct NormalCarGeometry__virtual_10_arg0 {
    char pad0[0x4];
    s32 unk4;
};

f32 NormalCarGeometry__GetSteeringWheelCenter_X(struct NormalCarGeometry__virtual_10_arg0 *arg0, f32 fparg0) {
    f32 *temp_s0;

    if (arg0->unk4 == 0) {
        return *func_00341AD8();
    }
    temp_s0 = func_00341AD8();
    return *temp_s0 + func_00341800(arg0, fparg0);
}
