typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
#define NULL 0
f32 func_0043E0B0(s32);
void func_00447CD8(void *);
void func_00447D00(void *, s32);
f32 func_00442EB8(u32 n, void *arg1) {
    f32 a, b;
    if (n >= 2U) {
        a = func_0043E0B0(*(s32 *)((s8 *)arg1 + 8) - 8);
        func_00447CD8(arg1);
        b = func_0043E0B0(*(s32 *)((s8 *)arg1 + 8) - 8);
        func_00447D00(arg1, n - 1);
        return (a < b) ? b : a;
    }
    func_00447D00(arg1, n);
    return 0.0f;
}
