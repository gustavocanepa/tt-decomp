#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

f32 func_00341950(void *, f32);                     /* extern */
void *func_00341AD8();                              /* extern */

struct NormalCarGeometry__virtual_12_arg0 {
    char pad0[0x4];
    s32 unk4;
};
struct NormalCarGeometry__virtual_12_temp_s0 {
    char pad0[0x8];
    f32 unk8;
};

f32 NormalCarGeometry__GetSteeringWheelCenter_Z(struct NormalCarGeometry__virtual_12_arg0 *arg0, f32 fparg0) {
    struct NormalCarGeometry__virtual_12_temp_s0 *temp_s0;

    if (arg0->unk4 == 0) {
        return M2C_FIELD(func_00341AD8(), f32 *, 8);
    }
    temp_s0 = func_00341AD8();
    return temp_s0->unk8 + func_00341950(arg0, fparg0);
}
