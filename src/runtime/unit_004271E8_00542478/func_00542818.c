#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542818_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00542818_temp_a0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_00542818_arg0 {
    char pad0[0x60];
    f32 unk60;
};

void func_00542818(void *arg0, struct func_00542818_arg1 *arg1) {
    struct func_00542818_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x60;
    if (temp_a0 != arg1) {
        ((struct func_00542818_arg0 *)arg0)->unk60 = (f32) arg1->unk0;
        temp_a0->unk4 = (f32) arg1->unk4;
        temp_a0->unk8 = (f32) arg1->unk8;
        temp_a0->unkC = (f32) arg1->unkC;
    }
}
