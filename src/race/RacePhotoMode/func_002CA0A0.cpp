#include "types.h"

extern "C" void func_00370BE8(void *self, u32 innerColor, u32 outerColor, f32 innerRadius, f32 outerRadius);
extern "C" s32 func_00477D28(void *, void *, f32, f32, f32, f32, f32);

extern "C" void func_002CA0A0(void *arg0, void *arg1) {
    f32 prod;

    prod = *(f32 *)((char *)arg0 + 0x327B4) * 0x1.666666p-1f * 0x1.47AE14p-7f;
    func_00370BE8(arg1, (u32)func_00477D28(arg0, arg1, 0.0f, 0.0f, 0.0f, prod, 255.0f), 0, 420.0f, 200.0f);
}
