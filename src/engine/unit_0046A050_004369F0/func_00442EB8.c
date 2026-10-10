#include "types.h"
#define NULL 0
f32 func_0043E0B0(s32);
void func_00447CD8(void *);
void func_00447D00(void *, s32);
struct func_00442EB8_arg1 {
    char pad0[0x8];
    s32 unk8;
};

f32 func_00442EB8(u32 n, struct func_00442EB8_arg1 *arg1) {
    f32 a, b;
    if (n >= 2U) {
        a = func_0043E0B0(arg1->unk8 - 8);
        func_00447CD8(arg1);
        b = func_0043E0B0(arg1->unk8 - 8);
        func_00447D00(arg1, n - 1);
        return (a < b) ? b : a;
    }
    func_00447D00(arg1, n);
    return 0.0f;
}
