/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Buf {
    char pad0[0x40000];
    s32 cnt[2];
    f32 scale;
};

struct Ctx {
    char pad0[0x80];
    void *course;
};
struct Race {
    char pad0[0x6C];
    Ctx *ctx;
};

struct Self {
    s32 f0;
    char *vtbl;
    char pad8[8];
    char f10[8];
    char f18[0x30];
    char f48[0x30];
    void *f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    char f8C[8];
    char f94[8];
    char f9C[8];
    char fA4[0xA0];
    char f144[0x140];
    char f284[8];
    char pad28C[4];
    char f290[0x10];
    s32 f2A0;
    s32 f2A4;
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    Buf *buf;
    s32 f2B8;
    f32 f2BC;
    f32 f2C0;
    s32 f2C4;
    s32 f2C8;
    s32 f2CC;
    s32 f2D0;
    s32 f2D4;
    s32 f2D8;
    s32 f2DC;
    s32 f2E0;
    f32 f2E4;
    f32 f2E8;
    f32 f2EC;
    f32 f2F0;
    char pad2F4[4];
    f32 f2F8;
    f32 f2FC;
    f32 f300;
    f32 f304;
    f32 f308;
    s32 f30C;
};

extern char D_005A50F8[];
extern s32 D_005797E8;
extern s32 D_005865D0;
extern Race *D_005797E0;

extern "C" void func_00117660(Buf *) throw();
extern "C" void func_0011C690(void *);
extern "C" void *func_002A7618(Self *);
extern "C" f32 RaceCourse__getCourseLength(void *);
extern "C" void func_004AE9C0(void *);
extern "C" void func_004A48C0(void *);
extern "C" s32 func_004A53A0(s32);
extern "C" void func_004A5618(void *);
extern "C" void *func_004A56C8(s32 *, s32 *, s32);
extern "C" s32 func_004A58E0(u32, s32);
extern "C" void *func_004F6678(void *, s32, u32);
extern "C" void *exception__structor_0(u32);

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

extern "C" void mLoggerControl__structor_0(Self *self) {
    s32 entry[4];
    s32 spare[4];
    s32 attr[4];

    func_002A7618(self);
    self->vtbl = D_005A50F8;
    func_004A48C0(self->f10);
    func_004AE9C0(self->f18);
    func_004AE9C0(self->f48);
    self->f78 = 0;
    self->f7C = D_005797E8;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f2A0 = 0;
    self->f2A4 = 0;
    self->f2A8 = 0;
    self->f2AC = 0;
    self->f2B0 = 0;
    Buf *buf = (Buf *)exception__structor_0(0x4000C);
    func_00117660(buf);
    self->buf = buf;
    self->f2B8 = D_005865D0 == 0;
    self->f2BC = self->f2B8 ? 25.0f : 0x1.9255c2p+4f;
    self->f2C0 = self->f2B8 ? 1.0f : 0x1.9bfdb4p+0f;
    self->f2C4 = 0;
    self->f2C8 = 0;
    self->f2CC = 0;
    self->f2D0 = 0;
    self->f2D4 = 0;
    self->f2D8 = 0;
    self->f2DC = 0;
    self->f2E0 = 0;
    self->f2E4 = 1.0f;
    self->f2E8 = 1.0f;
    self->f2EC = 1.0f;
    self->f2F0 = 1.0f;
    self->f2F8 = 0.0f;
    self->f2FC = 0.0f;
    self->f300 = 0.0f;
    self->f304 = 0.0f;
    self->f308 = 800.0f;
    self->f30C = 0x320;
    func_004F6678(self->f8C, 0, 8);
    func_004F6678(self->f94, 0, 8);
    func_004F6678(self->f9C, 0, 8);
    func_004F6678(self->fA4, 0, 0xA0);
    func_004F6678(self->f144, 0, 0x140);
    func_004F6678(self->f284, 0, 8);
    func_004F6678(self->f290, 0, 0x10);
    if (D_005797E0 != 0) {
        f32 len = RaceCourse__getCourseLength(D_005797E0->ctx->course);
        self->f300 = len;
        self->buf->scale = maxf(0.5f, len / 16383.0f);
    }
    s32 *pa = attr;
    entry[0] = (s32)func_0011C690;
    entry[1] = (s32)self;
    *pa = 0;
    attr[1] = 0x8000;
    void *t = func_004A56C8(entry, pa, func_004A53A0(func_004A58E0(1, 1)));
    self->f78 = t;
    func_004A5618(t);
}
