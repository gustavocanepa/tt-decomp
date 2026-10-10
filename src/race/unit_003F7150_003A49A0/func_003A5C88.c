#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct DynamicsConductor {
    void * unk0;
    char unk_4[0x90];
    f32 unk94;
};
f32 func_002F0570(struct DynamicsConductor *);
struct func_003A5C88_temp_a1 {
    char pad0[0x4C4];
    f32 unk4C4;
    char pad4C8[0x4];
    s16 unk4CC;
    char pad4CE[0x2];
    u8 unk4D0;
};

struct func_003A5C88_arg0 {
    char pad0[0x4];
    struct DynamicsConductor *unk4;
};

f32 func_003A5C88(void *arg0) {
    f32 temp_f20;
    f32 var_f0;
    s32 temp_s0;
    struct func_003A5C88_temp_a1 *temp_a1;

    temp_a1 = arg0 + 0x104;
    var_f0 = 0x0.0p+0f;
    temp_s0 = temp_a1->unk4CC - temp_a1->unk4D0;
    if (temp_s0 > 0) {
        temp_f20 = temp_a1->unk4C4;
        var_f0 = temp_f20 + (func_002F0570(((struct func_003A5C88_arg0 *)arg0)->unk4) * (f32) (temp_s0 - 1));
    }
    return var_f0;
}
