#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0041DD08(void *, void *, s32);         /* extern */
f32 func_0041E068(void *, s32);                         /* extern */
s32 GT4Model__CarData__offsetBrake(void *, f32);                 /* extern */
s32 func_004F6678(void *, s32, s32);        /* extern */

struct func_0041E0A8_temp_s0 {
    char pad0[0x10];
    s32 unk10;
};

void *func_0041E0A8(void *arg0, s32 arg1) {
    s32 temp_a2;
    u16 *temp_v1;
    void *temp_a1;
    struct func_0041E0A8_temp_s0 *temp_s0;

    if (*M2C_FIELD(arg0, u16 **, 0x10) & 0x8000) {
        GT4Model__CarData__offsetBrake(arg0, -func_0041E068(arg0, 0));
        temp_v1 = M2C_FIELD(arg0, u16 **, 0x10);
        *temp_v1 &= 0x7FFF;
    }
    temp_s0 = M2C_FIELD(arg0, void **, 0x20);
    temp_a2 = temp_s0->unk10;
    temp_a1 = temp_s0;
    M2C_FIELD(arg0, s32 *, 0x20) = 0;
    func_0041DD08(arg0, temp_a1, ((arg1 - temp_a2) + 0xF) & ~0xF);
    M2C_FIELD(arg0, void **, 0x20) = temp_s0;
    func_004F6678(temp_s0, 0, arg1);
    return M2C_FIELD(arg0, void **, 0x20);
}
