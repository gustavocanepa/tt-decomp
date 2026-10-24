/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Ha3AA8D0 { s32 w; f32 f; };
struct Hb3AA8D0 { f32 f0; f32 f4; f32 f8; };
struct Hc3AA8D0 { f32 f0; f32 f4; s32 i8; };

static inline void setv(Hb3AA8D0 *v,float x,float y,float z) { v->f0=x; v->f4=y; v->f8=z; }
static inline void setc(Hc3AA8D0 *v,float x,float y,int z) { v->f0=x; v->f4=y; v->i8=z; }
extern "C" void func_0035FAA0(void *arg0, s32 arg1) {
    struct Ha3AA8D0 *a2 = (struct Ha3AA8D0 *)((char *)arg0 + 0x4C);
    struct Hb3AA8D0 *v0;
    f32 zero;
    switch (arg1) {
    case 1: {
        struct Hb3AA8D0 *a3 = (struct Hb3AA8D0 *)((char *)arg0 + 0x58);
        a2->f = 3.0f;
        a2->w = (a2->w & ~0xFF) | arg1;
        setv(a3,0.2f,0.93f,0.11f);
        return;
    }
    case 2: {
        struct Hc3AA8D0 *v1 = (struct Hc3AA8D0 *)((char *)arg0 + 0x58);
        a2->f = 3.0f;
        a2->w = a2->w & ~0xFF;
        setc(v1,0.98f,0.89f,0);
        return;
    }
    case 0:
    default:
        zero = 0.0f;
        v0 = (struct Hb3AA8D0 *)((char *)a2 + 0xC);
        v0->f0 = zero;
        v0->f4 = zero;
        v0->f8 = zero;
        return;
    }
}
