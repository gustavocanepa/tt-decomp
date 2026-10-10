#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00263B60_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_00263B60_temp_v0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_00263B60_arg0 {
    char pad0[0x60];
    f32 unk60;
    char pad64[0xC];
    f32 unk70;
};

void func_00263B60(void *arg0, struct func_00263B60_arg1 *arg1, f32 fparg0) {
    struct func_00263B60_temp_v0 *temp_v0;

    temp_v0 = arg0 + 0x60;
    if (temp_v0 != arg1) {
        ((struct func_00263B60_arg0 *)arg0)->unk60 = (f32) arg1->unk0;
        temp_v0->unk4 = (f32) arg1->unk4;
        temp_v0->unk8 = (f32) arg1->unk8;
        temp_v0->unkC = (f32) arg1->unkC;
    }
    ((struct func_00263B60_arg0 *)arg0)->unk70 = fparg0;
}
