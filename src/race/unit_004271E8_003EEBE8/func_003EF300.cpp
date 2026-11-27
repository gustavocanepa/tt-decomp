#include "types.h"

struct Val { s32 a; char *b; s32 flag; f32 c; };

extern "C" f32 func_003F4AB8(void *a0, s32 a1, s32 a2);
extern "C" f32 func_003F1AF0(void *a0, s32 a1, s32 a2);
extern "C" void func_003F39A0(void *a0, s32 a1, void *a2, f32 f12);
extern "C" void func_003F39E8(void *a0, s32 a1, void *a2, f32 f12, f32 f13);
extern "C" void func_00468C10(f32 f12, f32 f13, f32 f14, f32 f15);
extern "C" void func_003F4EA8(void *a0, s32 a1);
extern char D_005D87E8[];

extern "C" void func_003EF300(char *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *out, f32 u12, f32 f13, f32 f14, f32 f15, f32 f16) {
    struct Val sp;
    char *v = *(char **)(arg0 + 4);
    if (v != 0) {
        s32 s1;
        s32 s2;
        if (arg2 >= 0) {
            s1 = arg2;
            s2 = 1;
        } else {
            if (arg3 < 0) {
                return;
            }
            s1 = arg3;
            s2 = 0;
        }
        char *s0 = *(char **)(v + 0x10) + (arg1 << 4);
        f32 r;
        if (s2 != 0) {
            r = func_003F4AB8(*(char **)(s0 + 4) + (s1 << 5), arg2, arg3);
        } else {
            r = func_003F1AF0(*(char **)(s0 + 8) + (s1 << 5), arg2, arg3);
        }
        if (out != 0) {
            *out = r;
        }
        sp.a = 0;
        sp.b = D_005D87E8;
        sp.flag = 0;
        if (s2 != 0) {
            func_003F39A0(s0, s1, &sp, r);
        } else {
            func_003F39E8(s0, s1, &sp, r, f16);
        }
        if (sp.flag != 0) {
            func_00468C10(sp.c, f13, f14, f15);
        }
        func_003F4EA8(&sp, 2);
    }
}
