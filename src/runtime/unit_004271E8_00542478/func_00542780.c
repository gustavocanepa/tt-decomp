#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542780_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00542780_temp_a1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_00542780_arg1 {
    char pad0[0x50];
    f32 unk50;
};

void *func_00542780(struct func_00542780_arg0 *arg0, void *arg1) {
    struct func_00542780_temp_a1 *temp_a1;

    temp_a1 = arg1 + 0x50;
    arg0->unk0 = (f32) ((struct func_00542780_arg1 *)arg1)->unk50;
    arg0->unk4 = (f32) temp_a1->unk4;
    arg0->unk8 = (f32) temp_a1->unk8;
    arg0->unkC = (f32) temp_a1->unkC;
    return arg0;
}
