#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

void *func_0034C5E8(s32);                           /* extern */

struct func_0034B1A8_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xB0];
    s32 unkB8;
};

f32 func_0034B1A8(struct func_0034B1A8_arg0 *arg0) {
    if (arg0->unkB8 < 0) {
        return M2C_FIELD(func_0034C5E8(arg0->unk4), f32 *, 0x18);
    }
    return M2C_FIELD((M2C_FIELD(func_0034C5E8(arg0->unk4), s32 *, 0x9C) + (arg0->unkB8 << 5)), f32 *, 0x0);
}
