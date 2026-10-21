/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
struct V3 { float x, y, z; };
struct Sub { char pad[0x18]; s16 f18; };
struct Cur { char pad[0x1A]; u16 f1A; char pad1C[0x60]; Sub *f7C; };
struct Obj {
    char pad0[0x87C]; s32 o570; char pad574[4]; Cur *o578;
};
extern char D_005F75F8[];
extern "C" void func_00380900(void *);
extern "C" void func_00420030(void *, s32);
#define F(off) (*(float *)((char *)self + (off)))
extern "C" void func_00380150(Obj *self, s32 mode) {
    *(s32 *)((char *)self + 0x888) = 1;
    char *p = (char *)self;
    for (s32 i = 0; i < 3; i++) {
        func_00380900(p + 0x890);
        func_00380900(p + 0x8C0);
        func_00380900(p + 0x8F0);
        p += 0x10;
    }
    V3 *a = (V3 *)((char *)self + 0x8B0);
    V3 *b = (V3 *)((char *)self + 0x900);
    V3 *c = (V3 *)((char *)self + 0x920);
    a->x = -0.5f;
    a->y = -2.5f;
    a->z = 0.5f;
    b->z = 0.5f;
    float zero = 0.0f;
    b->x = zero;
    b->y = 60.0f;
    c->y = 1.0f;
    c->x = zero;
    c->z = 1.0f;
    switch (mode) {
    case 1:
    case 2:
        F(0x8D0) = -22.5f;
        a->z = 0.35f;
        break;
    case 3:
        F(0x8D0) = 180.0f;
        b->x = 1000.0f;
        b->y = 60.0f;
        b->z = 0x1.333332p+0f;
        break;
    default: {
        V3 *d = (V3 *)((char *)self + 0x8C0);
        F(0x8D0) = 270.0f;
        d->x = -180.0f;
        d->y = 0;
        d->z = 1.5f;
        b->z = 3.0f;
        break;
    }
    }
    if (self->o578) {
        func_00420030(self->o578, -1);
        Cur *c = self->o578;
        s32 a1 = c->f1A;
        s32 v = D_005F75F8[self->o570];
        if (a1 < v) v = a1;
        c->f7C->f18 = v;
    }
}
