typedef int s32;
typedef float f32;

extern "C" f32 func_003F4AB8(void *a0, s32 a1, s32 a2);
extern "C" f32 func_003F1AF0(void *a0, s32 a1, s32 a2);
extern "C" void func_003F2440(void *a0);
extern "C" void func_00473050(void);
extern "C" void func_004751FC(void);
extern "C" void func_003F39A0(void *a0, s32 a1, void *a2, f32 f12);
extern "C" void func_003F39E8(void *a0, s32 a1, void *a2, f32 f12, f32 f13);
extern "C" void func_004730A8(void);
extern "C" void func_003F2728(void *a0);
extern "C" void func_003F24A8(void *a0, s32 a1);

extern "C" void func_003EEDA0(char *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *out, f32 unused, f32 fparg1) {
    struct Val { s32 a, b, c, d; char pad[0x40]; } sp;
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
        func_003F2440(&sp);
        func_00473050();
        func_004751FC();
        if (s2 != 0) {
            func_003F39A0(s0, s1, &sp, r);
        } else {
            func_003F39E8(s0, s1, &sp, r, fparg1);
        }
        func_004730A8();
        if (sp.d != 0) {
            func_003F2728(&sp);
        }
        func_003F24A8(&sp, 2);
    }
}
