#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_003418B0(void *, f32);                     /* extern */
void *func_00341AD8();                              /* extern */

struct NormalCarGeometry__virtual_11_arg0 {
    char pad0[0x4];
    s32 unk4;
};
struct NormalCarGeometry__virtual_11_temp_s0 {
    char pad0[0x4];
    f32 unk4;
};

f32 NormalCarGeometry__GetSteeringWheelCenter_Y(struct NormalCarGeometry__virtual_11_arg0 *arg0, f32 fparg0) {
    struct NormalCarGeometry__virtual_11_temp_s0 *temp_s0;

    if (arg0->unk4 == 0) {
        return M2C_FIELD(func_00341AD8(), f32 *, 4);
    }
    temp_s0 = func_00341AD8();
    return temp_s0->unk4 + func_003418B0(arg0, fparg0);
}
