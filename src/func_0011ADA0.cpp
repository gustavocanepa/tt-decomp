/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct Obj {
    char pad0[0x2BC];
    f32 f2BC;
    f32 f2C0;
    char pad2C4[0x2D4 - 0x2C4];
    f32 f2D4;
    char pad2D8[4];
    f32 f2DC;
};
extern "C" void func_00475030(f32, f32, f32, f32, f32, f32);
extern "C" void func_00478F40(f32, f32, f32);
extern "C" void func_0011ADA0(Obj *o, s32 n, f32 x, f32 w) {
    f32 x2 = x + w;
    f32 a = o->f2D4;
    f32 b = o->f2DC;
    s32 lo = (s32)(a / o->f2BC);
    lo--;
    s32 hi = (s32)(b / o->f2BC) + 1;
    func_00478F40(0.25f, 0.25f, 0.25f);
    s32 i;
    for (i = lo; i <= hi; i++) {
        if (i & 3) {
            f32 px = (f32)i * o->f2BC;
            func_00475030(px, x, 0.0f, px, x2, 0.0f);
        }
    }
    s32 k;
    for (k = 0; k <= n; ) {
        f32 y = x + (w * (f32)k / (f32)n) * o->f2C0;
        f32 c = 0.25f;
        if (k % 100 == 0) {
            c = 1.0f;
            if (k != 0) {
                c = 0.5f;
            }
        }
        k += 25;
        func_00478F40(c, c, c);
        func_00475030(a, y, 0.0f, b, y, 0.0f);
    }
}
