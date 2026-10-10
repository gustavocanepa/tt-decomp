#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_003EBCF8_arg1 {
    f32 unk0;
    f32 unk4;
};
struct func_003EBCF8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    char pad10[0x4];
    f32 unk14;
    f32 unk18;
};

void func_003EBCF8(struct func_003EBCF8_arg0 *arg0, struct func_003EBCF8_arg1 *arg1) {
    arg1->unk0 = (f32) (arg0->unk0 + ((arg1->unk0 * arg0->unk8) / arg0->unk14));
    arg1->unk4 = (f32) (arg0->unk4 + ((arg1->unk4 * arg0->unkC) / arg0->unk18));
}
