/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Ha3AA850 { s32 w; f32 f; };
struct Hb3AA850 { f32 f0; f32 f4; f32 f8; };

extern "C" void func_0035FB88(void *arg0, s32 arg1) {
    struct Hb3AA850 *v1 = (struct Hb3AA850 *)arg0;
    struct Ha3AA850 *a2 = (struct Ha3AA850 *)((char *)v1 + 0x70);
    struct Hb3AA850 *v0;
    f32 zero;
    if (arg1 != 0) {
        if (arg1 == 1) {
            v1 = (struct Hb3AA850 *)((char *)v1 + 0x7C);
            a2->f = 3.0f;
            a2->w = a2->w & ~0xFF;
            v1->f0 = 0.99f;
            v1->f4 = 0.39f;
            v1->f8 = 0.01f;
            return;
        }
    }
    zero = 0.0f;
    v0 = (struct Hb3AA850 *)((char *)a2 + 0xC);
    v0->f0 = zero;
    v0->f4 = zero;
    v0->f8 = zero;
}
