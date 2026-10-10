#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

void *func_0034C5E8(s32);                           /* extern */
s32 GT4Course__RunwayData__Section__checkPointCount(void *, s32);                 /* extern */
s32 GT4Course__RunwayData__checkPointCount(s32, s32);                    /* extern */

struct func_0034AFD0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xB0];
    s32 unkB8;
};

void RaceCourse__getCheckPointCount(struct func_0034AFD0_arg0 *arg0, s32 arg1) {
    if (arg0->unkB8 < 0) {
        GT4Course__RunwayData__Section__checkPointCount(func_0034C5E8(arg0->unk4), arg1);
        return;
    }
    GT4Course__RunwayData__checkPointCount(M2C_FIELD(func_0034C5E8(arg0->unk4), s32 *, 0x9C) + (arg0->unkB8 << 5), arg1);
}
