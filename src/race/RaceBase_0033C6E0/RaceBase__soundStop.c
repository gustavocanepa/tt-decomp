/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

s32 func_003480B0(s32, s32);                /* extern */
s32 func_0036C908(void *, s32, s32, s32); /* extern */

struct RaceBase__virtual_89_arg0 {
    char pad0[0x6C];
    void *unk6C;
};

struct RaceBase__virtual_89_temp_s1 {
    char pad0[0x60];
    s32 *unk60;
};

void RaceBase__soundStop(struct RaceBase__virtual_89_arg0 *arg0) {
    s32 temp_v0;
    s32 var_s0;
    void *temp_s1;

    temp_s1 = arg0->unk6C;
    var_s0 = 0;
    if (*((struct RaceBase__virtual_89_temp_s1 *)temp_s1)->unk60 > 0) {
        do {
            temp_v0 = var_s0 * 4;
            var_s0 += 1;
            func_003480B0(*(s32 *)(temp_v0 + M2C_FIELD(((struct RaceBase__virtual_89_temp_s1 *)temp_s1)->unk60, s32 *, 8)) + 0x48C0, 1);
        } while (var_s0 < *((struct RaceBase__virtual_89_temp_s1 *)temp_s1)->unk60);
    }
    func_0036C908(temp_s1 + 0xF4, 0x18, -2, 0);
}
