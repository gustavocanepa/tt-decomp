/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

struct Race;
struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VEntryC { s16 delta; s16 index; struct Car *(*fn)(void *, s32); };

struct Sub { char pad0[0x40]; s32 f40; };
struct Car {
    char pad0[0xDC];
    Sub sub;
    char pad120[0x1D0 - 0x120];
    s32 f1D0;
};

struct Z { char pad0[0x18]; s32 f18; };
struct Y { Z *f0; Z *f4; };
struct X { char pad0[8]; Y *f8; };
struct Ctx {
    char pad0[0x60];
    X *f60;
    char pad64[0x80 - 0x64];
    void *course;
    char pad84[0xE4 - 0x84];
    s32 fE4;
};
struct Race {
    char pad0[0x64];
    char *vtbl;
    char pad68[4];
    Ctx *ctx;
    char pad70[0xD88 - 0x70];
    s32 fCC4;
};

struct Buf {
    char buf0[0x20000];
    char buf1[0x20000];
    s32 cnt[2];
    f32 scale;
};

struct Log {
    f32 f0;
    char pad4[0x2C - 4];
    f32 f2C;
    char pad30[0x4C - 0x30];
};

struct Self {
    char pad0[0x2A4];
    s32 f2A4;
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    Buf *buf;
    char pad2B8[0x2E8 - 0x2B8];
    f32 f2E8;
    char pad2EC[0x2F8 - 0x2EC];
    f32 f2F8;
    f32 f2FC;
    char pad300[0x308 - 0x300];
    f32 f308;
    s32 f30C;
};

extern Race *D_005797E0;
extern char D_005E0128[];

extern "C" f32 func_001176B0(Buf *, s32) throw();
extern "C" void func_00117F00(Log *, char *, s32 *, f32, f32, s32) throw();
extern "C" void func_00117F50(Log *) throw();
extern "C" void func_0011BCA8(Self *, char *) throw();
extern "C" void func_0011BE60(Self *) throw();
extern "C" s32 func_002E8518(Sub *);
extern "C" void func_0033A158(Race *, s32, s32);
extern "C" s32 func_0033C828(Race *);
extern "C" f32 RaceCourse__getCourseLength(void *);
extern "C" void func_004AEB30(void *);
extern "C" void func_004A4930(void *);
extern "C" void func_004A4970(void *);

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline void vcall(Race *r, s32 off) {
    VEntry *e = (VEntry *)(r->vtbl + off);
    e->fn((char *)r + e->delta);
}

static inline Car *getcar(Race *r, s32 i) {
    VEntryC *e = (VEntryC *)(r->vtbl + 0x240);
    return e->fn((char *)r + e->delta, i);
}

static inline void lock(Self *s) { func_004A4930((char *)s + 0x10); }
static inline void unlock(Self *s) { func_004A4970((char *)s + 0x10); }
static inline s32 pos(Sub *s) { return s->f40; }
static inline bool update(Self *self, Sub *sub) {
    lock(self);
    self->f2AC = pos(sub);
    self->f2B0 = func_002E8518(sub);
    bool done = self->f2AC >= self->f2B0;
    unlock(self);
    return done;
}

extern "C" void func_0011C0D0(Self *self) {
    Log log0;
    Log log1;
    Race *race = D_005797E0;

    if (race != 0) {
        Ctx *ctx = race->ctx;
        ctx->fE4 = 1;
        X *x = ctx->f60;
        func_0033A158(race, race->fCC4 == 1 ? 3 : 2, 0);
        vcall(race, 0x500);
        Buf *buf = self->buf;
        f32 len = RaceCourse__getCourseLength(race->ctx->course);
        f32 rate = maxf(len / 16383.0f, 0.5f);
        buf->scale = rate;
        Car *c0 = getcar(race, 0x100);
        func_00117F00(&log0, buf->buf0, &buf->cnt[0], rate, len, x->f8->f0->f18);
        Car *c1 = getcar(race, 1);
        Z *z;
        if (c1->f1D0 != 0) {
            z = x->f8->f0;
        } else {
            z = x->f8->f4;
        }
        Log *p1 = &log1;
        func_00117F00(p1, buf->buf1, &buf->cnt[1], rate, len, z->f18);
        s32 n0 = func_002E8518(&c0->sub);
        s32 n1 = 0;
        if (c1->f1D0 == 0) {
            n1 = func_002E8518(&c1->sub);
        }
        if (n0 <= n1) {
            c0 = c1;
        }
        Sub *sub = &c0->sub;
        while (self->f2A4 != 0 && func_0033C828(race) != 1) {
            if (update(self, sub)) {
                break;
            }
            vcall(race, 0x38);
            func_00117F50(&log0);
            func_00117F50(p1);
        }
        vcall(race, 0x2D0);
        ctx->fE4 = 0;
        if (self->f2A4 != 0) {
            s32 a = buf->cnt[0];
            s32 b = buf->cnt[1];
            if (a < b) {
                b = a;
            }
            buf->cnt[0] = b;
            buf->cnt[1] = b;
            self->f2F8 = minf(log0.f0, p1->f0);
            f32 d0 = func_001176B0(buf, 0);
            f32 d1 = func_001176B0(buf, 1);
            self->f2FC = minf(d0, d1) + self->f2F8;
            f32 vmax = maxf(log0.f2C, log1.f2C);
            self->f30C = (s32)minf(800.0f, vmax * 3.6f + 100.0f);
            self->f308 = (f32)self->f30C;
            self->f2E8 = maxf(1.0f, (f32)(s32)(vmax * 9.0f / 250.0f));
            func_0011BE60(self);
            self->f2A8 = 1;
        }
    }
    self->f2A4 = 0;
    func_004AEB30((char *)self + 0x18);
    func_0011BCA8(self, D_005E0128);
}
