#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_0034C5E8(s32);                           /* extern */

struct func_0034B208_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xB0];
    s32 unkB8;
};

f32 func_0034B208(struct func_0034B208_arg0 *arg0) {
    if (arg0->unkB8 < 0) {
        return M2C_FIELD(func_0034C5E8(arg0->unk4), f32 *, 0x1C);
    }
    return M2C_FIELD((M2C_FIELD(func_0034C5E8(arg0->unk4), s32 *, 0x9C) + (arg0->unkB8 << 5)), f32 *, 4);
}
