/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Dim { char pad[0x10]; u32 w; u32 h; };
struct W {
    char pad[0xE4];
    Dim *c8;
    s32 iCC;
    s32 iD0;
    f32 fD4;
};
struct Src { void *a; s32 b; s32 c; };
struct Info { char pad[4]; char *p4; };
struct Hold { char pad[0x80]; };
struct Mid { char pad[0x80]; Info *i80; };
struct Top { char pad[0x6C]; Mid *m6C; };
struct Face { Top *t; s32 i4; s32 i8; };
struct Dm { char pad[0x84]; Dim *d84; };
struct Cur { char pad[4]; Dm *p4; };

extern "C" f32 func_00205C50(void *);
extern "C" f32 func_00205CB0(void *);
extern "C" void func_00205DF0(void *, f32, f32);
extern "C" void func_00205E48(void *, f32, f32);
extern "C" f32 RaceCourse__getCourseLength(void *);

extern "C" void func_0011CB90(W *self, Face *src) {
    Top *top = src->t;
    s32 b = src->i4;
    self->iCC = b;
    s32 c = src->i8;
    self->c8 = 0;
    self->iD0 = c;
    if (top != 0) {
        Cur *cur = (Cur *)((Info *)top->m6C->i80);
        Dim *d;
        self->fD4 = RaceCourse__getCourseLength(cur);
        d = cur->p4->d84;
        self->c8 = d;
        if (d != 0) {
            f32 x = func_00205C50(self);
            f32 y = func_00205CB0(self);
            f32 w = (f32)self->c8->w;
            f32 h = (f32)self->c8->h;
            if (x + w > 624.0f)
                x = 624.0f - w;
            func_00205DF0(self, x, y);
            func_00205E48(self, w, h);
        }
    }
}
