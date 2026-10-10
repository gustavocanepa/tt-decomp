/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Val;
extern "C" f32 func_0043E0B0(Val *v);
extern "C" void func_0043D810(Val *v, s32 n);

extern "C" void func_0043F0D0(Val *a, Val *b) {
    f32 x = func_0043E0B0(a);
    f32 y = func_0043E0B0(b);
    func_0043D810(a, (s32)x & (s32)y);
}
