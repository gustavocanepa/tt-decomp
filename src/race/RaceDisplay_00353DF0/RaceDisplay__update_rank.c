/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

s32 func_003591D8(void *, f32);                 /* extern */
s32 RaceRankDisplay__setRank(void *, s8, s32);         /* extern */

struct RaceDisplay__virtual_25_arg1_unk60 {
    char pad0[0x8];
    s32 unk8;
};
struct RaceDisplay__virtual_25_arg1 {
    char pad0[0x60];
    struct RaceDisplay__virtual_25_arg1_unk60 *unk60;
};

struct RaceDisplay__virtual_25_arg0 {
    char pad0[0x2E];
    s8 unk2E;
};

void RaceDisplay__update_rank(void *arg0, struct RaceDisplay__virtual_25_arg1 *arg1, f32 fparg0) {
    void *temp_s0;

    temp_s0 = arg0 + 0x1358;
    RaceRankDisplay__setRank(temp_s0, M2C_FIELD(M2C_FIELD(*(s32 *)((((struct RaceDisplay__virtual_25_arg0 *)arg0)->unk2E * 4) + arg1->unk60->unk8), void **, 0x18), s8 *, 0x5D3), 1);
    func_003591D8(temp_s0, fparg0);
}
