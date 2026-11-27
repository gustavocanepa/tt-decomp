/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Obj { f32 m0; f32 m4; f32 m8; s32 mC; };

extern "C" float func_005357F8(void *);

extern "C" void func_0032E0E8(Obj *o, void *arg1, f32 a, f32 b) {
    f32 r = func_005357F8(arg1);
    s32 c = o->mC;
    if (c < 2) {
        o->mC = c + 1;
    } else {
        o->mC = 0;
        a = a * -0x1.428f6p-3f + 0x1.fc962ep-1f;
        if (a < r)
            o->m4 = func_005357F8(arg1) * 256.0f;
    }
    if (b > 1.0f)
        o->m4 = 256.0f;
    f32 x = o->m0;
    o->m8 = o->m8 + ((((o->m4 - x) * 60.0f) + (o->m8 * -10.0f)) / 60.0f);
    o->m0 = x + o->m8 / 60.0f;
}
