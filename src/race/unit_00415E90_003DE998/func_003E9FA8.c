#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_003E9D50(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */

struct func_003E9FA8_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_003E9FA8_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_003E9FA8_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_003E9FA8_arg3 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

f32 func_003E9FA8(struct func_003E9FA8_arg0 *arg0, struct func_003E9FA8_arg1 *arg1, struct func_003E9FA8_arg2 *arg2, struct func_003E9FA8_arg3 *arg3) {
    return func_003E9D50(arg0->unk0, arg0->unk4, arg0->unk8, arg1->unk0, arg1->unk4, arg1->unk8, arg2->unk0, arg2->unk4, arg2->unk8, arg3->unk0, arg3->unk4, arg3->unk8) / 6.0f;
}
