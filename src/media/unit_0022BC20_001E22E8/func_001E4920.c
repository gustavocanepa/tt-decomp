#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E4920_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_001E4920_temp_a1_2 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_001E4920_arg1 {
    char pad0[0x1CE8];
    s32 unk1CE8;
};
struct func_001E4920_temp_a1 {
    char pad0[0x708];
    f32 unk708;
};

void *func_001E4920(struct func_001E4920_arg0 *arg0, void *arg1) {
    void *temp_a1;
    struct func_001E4920_temp_a1_2 *temp_a1_2;

    temp_a1 = arg1 + (((struct func_001E4920_arg1 *)arg1)->unk1CE8 * 0x38);
    temp_a1_2 = temp_a1 + 0x708;
    arg0->unk0 = (f32) ((struct func_001E4920_temp_a1 *)temp_a1)->unk708;
    arg0->unk4 = (f32) temp_a1_2->unk4;
    arg0->unk8 = (f32) temp_a1_2->unk8;
    arg0->unkC = (f32) temp_a1_2->unkC;
    return arg0;
}
