#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0044FF40_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_0044FF40_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_0044FF40(struct func_0044FF40_arg0 *arg0, struct func_0044FF40_arg1 *arg1) {
    arg0->unk0 = (f32) arg1->unk0;
    arg0->unk8 = (f32) arg1->unk4;
    arg0->unk4 = (f32) arg1->unk8;
    arg0->unkC = (f32) arg1->unkC;
}
