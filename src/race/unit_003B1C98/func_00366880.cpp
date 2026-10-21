/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct V3 {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" V3 D_005F6800;

extern "C" void func_004A6328(f32 *, f32 *, f32);

static inline float bits(unsigned int word) {union U {unsigned int i;float f;} u;u.i=word;return u.f;}

struct Loc {
    f32 s;
    f32 c;
    char pad[0x8];
    V3 v;
};

extern "C" void func_00366880(s32 *arg0, f32 *arg1, f32 *arg2, f32 angle) {
    Loc loc;
    func_004A6328(&loc.s, &loc.c, angle);
    loc.v = D_005F6800;
    *arg0 = 0;
    f32 c = loc.c;
    f32 s = loc.s;
    f32 ka = bits(0x3e49d8c6);
    f32 kb = bits(0xbf78e757);
    f32 kc = bits(0x3f53b139);
    f32 nka = -ka;
    f32 outy = c * kb;
    f32 outz = s * kb;
    s *= nka;
    c *= nka;
    outz += c;
    outy -= s;
    outz += ka;
    outy -= kb;
    outz *= kc;
    outy *= kc;
    *arg1 = outy;
    *arg2 = outz;
}
