#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

void *func_002E8A48(void *);                        /* extern */

struct func_00387268_temp_v0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_00387268_temp_v0_2 {
    char pad0[0x10];
    s32 unk10;
};
struct func_00387268_temp_v0_3 {
    char pad0[0x10];
    s32 unk10;
};
struct func_00387268_temp_v0_4 {
    char pad0[0x10];
    s32 unk10;
};

struct func_00387268_arg0 {
    char pad0[0x6C];
    void *unk6C;
    char pad70[0xE6AC];
    s32 unkE71C;
    char padE720[0x1DC];
    s32 unkE8FC;
    char padE900[0x1DC];
    s32 unkEADC;
    char padEAE0[0x1DC];
    s32 unkECBC;
    char padECC0[0x59C];
    s32 unkF25C;
    char padF260[0x4];
    s32 unkF264;
};

s32 func_00387268(void *arg0) {
    s32 var_s2;
    struct func_00387268_temp_v0 *temp_v0;
    struct func_00387268_temp_v0_2 *temp_v0_2;
    struct func_00387268_temp_v0_3 *temp_v0_3;
    struct func_00387268_temp_v0_4 *temp_v0_4;

    ((struct func_00387268_arg0 *)arg0)->unkECBC = 1;
    var_s2 = 0;
    temp_v0 = func_002E8A48(arg0 + 0xEBC0);
    if (temp_v0 != NULL) {
        temp_v0->unk10 = 0x157529FF;
    }
    if (((struct func_00387268_arg0 *)arg0)->unkF264 != 0) {
        ((struct func_00387268_arg0 *)arg0)->unkE71C = 1;
        temp_v0_2 = func_002E8A48(arg0 + 0xE620);
        if (temp_v0_2 != NULL) {
            temp_v0_2->unk10 = 0x157529FF;
        }
        ((struct func_00387268_arg0 *)arg0)->unkE8FC = 1;
        temp_v0_3 = func_002E8A48(arg0 + 0xE800);
        if (temp_v0_3 != NULL) {
            temp_v0_3->unk10 = 0x157529FF;
        }
        ((struct func_00387268_arg0 *)arg0)->unkEADC = 1;
        temp_v0_4 = func_002E8A48(arg0 + 0xE9E0);
        if (temp_v0_4 != NULL) {
            temp_v0_4->unk10 = 0x157529FF;
        }
        var_s2 = 1;
        *M2C_FIELD(M2C_FIELD(((struct func_00387268_arg0 *)arg0)->unk6C, void **, 0x60), s32 **, 8) = ((struct func_00387268_arg0 *)arg0)->unkF264;
        ((struct func_00387268_arg0 *)arg0)->unkF264 = 0;
    }
    ((struct func_00387268_arg0 *)arg0)->unkF25C = 1;
    return var_s2;
}
