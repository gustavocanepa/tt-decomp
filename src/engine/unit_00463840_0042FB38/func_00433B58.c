#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724
#include "m2c_macros.h"

s32 func_0042FD90(void *);
struct func_00433B58_arg1 {
    char pad0[0x1088];
    f32 unk1088;
    char pad108C[0x2C];
    f32 unk10B8;
    f32 unk10BC;
    char pad10C0[0x3];
    u8 unk10C3;
    char pad10C4[0xC];
    f32 unk10D0;
};

struct func_00433B58_temp_v0 {
    f32 unk0;
};

void func_00433B58(void *arg0, struct func_00433B58_arg1 *arg1) {
    f32 *temp_v0;

    M2C_FIELD(func_0042FD90(arg0), f32 *, 0x70) = (f32) ((arg1->unk10B8 + arg1->unk10BC) / arg1->unk1088);
    temp_v0 = (f32 *)(func_0042FD90(arg0) + 0x74);
    ((struct func_00433B58_temp_v0 *)temp_v0)->unk0 = 0x0.0p+0f;
    if (arg1->unk10C3 == 7) {
        ((struct func_00433B58_temp_v0 *)temp_v0)->unk0 = (f32) ((arg1->unk10D0 * 0x1.9999980000000p-1f) / arg1->unk1088);
    }
}
