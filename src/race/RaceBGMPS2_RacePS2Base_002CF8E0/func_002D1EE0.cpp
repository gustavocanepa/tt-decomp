/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

static inline float sqrt_s(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct Out { float f0, f4, f8, fC; s32 i10; s32 i14; s32 i18; };
struct Src { char pad[0x1750]; s32 flags; float f1754, f1758, f175C, f1760; s32 i1764; };
struct Dim { char pad[8]; s32 w; };

extern "C" s32 func_00104E00(void *);
extern "C" void func_003912F8(void *, s32, void *);

extern "C" void func_002D1EE0(char *arg0, Dim *arg1, s32 arg2) {
    Src *s = *(Src **)(*(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4) + 0x80);
    Out *o = (Out *)(arg0 + 0x369C);
    if (s->flags & 1) {
        float a = (float)arg1->w;
        float b = (float)func_00104E00(arg1);
        s32 half = arg1->w / 2;
        float k = sqrt_s(a * a + b * b) / 0x1.869c18p+9f;
        s32 q = func_00104E00(arg1) / 4;
        o->i14 = half;
        o->i18 = q;
        o->f0 = s->f1754;
        o->f4 = s->f1758;
        o->f8 = s->f175C;
        o->fC = s->f1760 * k;
        o->i10 = s->i1764;
        func_003912F8(o, arg2, arg1);
    }
}
