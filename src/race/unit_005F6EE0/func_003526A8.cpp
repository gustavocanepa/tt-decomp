/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned char u8;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Msg { char pad[0x20]; s32 color; };
struct Table { char pad[0x124]; char *name; };
struct Self { char *vtbl; };
struct Arg { char pad[0x71A]; u8 b6fe; };

extern Table *D_00584418;
extern "C" s32 func_003067F0(Arg *) throw();
extern "C" void func_004A6500(char *, char *, ...);
extern "C" void RaceMessageDisplay__setFont(void *, char *, s32);
extern "C" void Oscillator__setCount(void *, s32, s32);
extern "C" void Oscillator__setCycle(void *, f32, f32);
extern "C" void RaceMessageDisplay__setMessage(void *, char *, f32, f32);
extern char D_005F41D0[];

extern "C" void func_003526A8(Self *self, Arg *arg) {
    char buf[0x80];
    char *osc = (char *)self + 0x2280;
    s32 n = func_003067F0(arg);
    Msg *m = (Msg *)((char *)self + 0x224C);
    if (n > 0) {
        func_004A6500(buf, D_00584418->name, n);
        RaceMessageDisplay__setFont(m, D_005F41D0, 1);
        m->color = 0x800000C8;
        Oscillator__setCount(osc, -1, 1);
        Oscillator__setCycle(osc, 1.0f, 1.0f);
        RaceMessageDisplay__setMessage(m, buf, 0x1.999998p-3f, 0.0f);
    } else {
        VEnt *e = (VEnt *)(self->vtbl + 0xF8);
        ((void (*)(void *, s32))e->fn)((char *)self + e->delta, arg->b6fe);
    }
}
