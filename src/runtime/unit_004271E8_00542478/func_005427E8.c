#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005427E8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_005427E8_temp_a1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_005427E8_arg1 {
    char pad0[0x60];
    f32 unk60;
};

void *func_005427E8(struct func_005427E8_arg0 *arg0, void *arg1) {
    struct func_005427E8_temp_a1 *temp_a1;

    temp_a1 = arg1 + 0x60;
    arg0->unk0 = (f32) ((struct func_005427E8_arg1 *)arg1)->unk60;
    arg0->unk4 = (f32) temp_a1->unk4;
    arg0->unk8 = (f32) temp_a1->unk8;
    arg0->unkC = (f32) temp_a1->unkC;
    return arg0;
}
