#include "types.h"

extern "C" void func_004755EC(f32 a, f32 b, f32 c);
extern "C" void func_00475758(f32 a);
extern "C" void ModelSet2___render(s32 a0, s32 a1, s32 a2);

extern "C" void func_003D0468(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4) {
    func_004755EC(*(f32 *)((char *)arg0 + 0x3C), 0.0f, *(f32 *)((char *)arg0 + 0x40));
    func_00475758(*(f32 *)((char *)arg0 + 0x5C) * 57.324841f);
    ModelSet2___render(arg1, arg4[*(s32 *)((char *)arg0 + 0x30)], arg2);
}
