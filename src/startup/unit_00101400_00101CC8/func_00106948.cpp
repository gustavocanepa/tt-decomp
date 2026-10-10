#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
void func_00475638(f32, f32, f32);
struct func_00106948_arg0 {
    char pad0[0x14];
    f32 unk14;
    char pad18[0x10];
    s32 unk28;
};

void func_00106948(struct func_00106948_arg0 *arg0) {
    f32 a = 0.75f;
    if (arg0->unk28 == 0) a = 1.0f;
    func_00475638(a, arg0->unk14, 1.0f);
}

}
