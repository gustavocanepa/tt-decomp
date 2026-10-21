typedef unsigned short u16;
struct El { u16 id; short x; };
struct Vec { El *begin; int size; };
struct Tab { char pad0[0x50]; char *f50; };
struct Ctx { char pad0[0x6E14]; int f6E14; unsigned char f6E18[8]; Tab *f6E20; };
struct Arg { short f0; u16 f2; unsigned char f4[4]; float f8; float fC; Vec v; };
extern "C" void func_00439EC8(int, unsigned) throw();
extern "C" unsigned func_00445370(const unsigned char *, const unsigned char *) throw();
extern "C" void func_00445628(Ctx *) throw();
extern "C" void func_00445838(void *, Ctx *) throw();
extern "C" void func_00473050(void) throw();
extern "C" void func_004730A8(void) throw();
extern "C" void func_004755EC(float, float, float) throw();
extern "C" void func_00475638(float, float, float) throw();

static inline El *vbeg(Vec *v) { return v->begin; }
static inline El *vend(Vec *v) { return v->begin + v->size; }

extern "C" void func_00440708(Arg *a, Ctx *c) {
    if (a->f0 < 0) return;
    func_00439EC8(c->f6E14, func_00445370(c->f6E18, a->f4));
    float sc = (float)a->f2 * 0.0009765625f;
    if (a->f8 != 0.0f || a->fC != 0.0f) {
        func_004730A8();
        func_00473050();
        func_004755EC(a->f8, a->fC, 0.0f);
    }
    Vec *v = &a->v;
    char **tp = (char **)(c->f6E20->f50 + a->f0 * 0x18);
    El *end = vend(v);
    El *cur = vbeg(v);
    El *first = cur;
    while (cur != end) {
        func_00473050();
        func_00475638(sc, sc, 0.0f);
        if (cur == first) func_00445628(c);
        func_00445838(*tp + cur->id * 0xC, c);
        func_004730A8();
        short xx = cur->x;
        cur++;
        func_004755EC((float)xx * 0x1.999998p-5f, 0.0f, 0.0f);
    }
}
