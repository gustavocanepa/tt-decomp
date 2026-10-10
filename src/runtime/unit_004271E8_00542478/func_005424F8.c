#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005424F8_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_005424F8_temp_a0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
};

struct func_005424F8_arg0 {
    char pad0[0x35C];
    f32 unk35C;
};

void func_005424F8(void *arg0, struct func_005424F8_arg1 *arg1) {
    struct func_005424F8_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x35C;
    ((struct func_005424F8_arg0 *)arg0)->unk35C = (f32) arg1->unk0;
    temp_a0->unk4 = (f32) arg1->unk4;
    temp_a0->unk8 = (f32) arg1->unk8;
}
