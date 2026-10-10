#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_0034C5E8(s32);                           /* extern */
s32 GT4Course__RunwayData__Section__getCheckPoint(void *, s32, s32);            /* extern */
s32 GT4Course__RunwayData__getCheckPoint(s32, s32, s32);               /* extern */

struct func_0034B048_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xB0];
    s32 unkB8;
};

void RaceCourse__getCheckPoint(struct func_0034B048_arg0 *arg0, s32 arg1, s32 arg2) {
    if (arg0->unkB8 < 0) {
        GT4Course__RunwayData__Section__getCheckPoint(func_0034C5E8(arg0->unk4), arg1, arg2);
        return;
    }
    GT4Course__RunwayData__getCheckPoint(M2C_FIELD(func_0034C5E8(arg0->unk4), s32 *, 0x9C) + (arg0->unkB8 << 5), arg1, arg2);
}
