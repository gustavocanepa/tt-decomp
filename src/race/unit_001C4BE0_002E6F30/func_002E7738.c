#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E7738_arg0 {
    char pad0[0x10];
    void *unk10;
};
struct func_002E7738_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_002E7738_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_002E7738_temp_v0 {
    char pad0[0x50];
    f32 unk50;
    f32 unk54;
};

void func_002E7738(struct func_002E7738_arg0 *arg0, struct func_002E7738_arg1 *arg1, struct func_002E7738_arg2 *arg2) {
    struct func_002E7738_temp_v0 *temp_v0;

    temp_v0 = arg0->unk10;
    arg1->unk0 = (f32) arg2->unk0;
    arg1->unk4 = (f32) (arg2->unk4 + temp_v0->unk54);
    arg1->unk8 = (f32) (arg2->unk8 + temp_v0->unk50);
}
