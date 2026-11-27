struct VEnt { short adj; short pad; void *fn; };
struct Obj { char *vt; };
struct Self { char *vt; int f4; int f8; Obj *oC; };
typedef void (*F0)(void *);
typedef int (*F1)(void *);
typedef int (*F5)(void *, int, int, int, int);
extern "C" void func_0047BDC0(int, int);
extern "C" int func_0047BF80(Self *);
extern "C" int func_0047BFD8(Self *, int);
extern "C" int func_0047C018(Self *, int);
extern "C" int func_0047C348(char *, int, int *);

static inline void call1(Obj *b) {
    VEnt *e = (VEnt *)(b->vt + 0x10);
    ((F0)e->fn)((char *)b + e->adj);
}
static inline int call2(Obj *o) {
    VEnt *e = (VEnt *)(o->vt + 0x10);
    return ((F1)e->fn)((char *)o + e->adj);
}
static inline int call3(Obj *b, int a, int c, int d, int e5) {
    VEnt *e = (VEnt *)(b->vt + 0x18);
    return ((F5)e->fn)((char *)b + e->adj, a, c, d, e5);
}

extern "C" int func_0047C090(Self *self, int arg1) {
    int sp0 = 0;
    int s4 = func_0047C348((char *)self + 0x10, arg1, &sp0);
    if (sp0 == 0) {
        if (func_0047BF80(self) == 0) {
            int s0 = func_0047BFD8(self, arg1);
            int s2 = func_0047BFD8(self, arg1 + 1) - s0;
            int s1 = self->f4;
            call1(self->oC);
            int r = call2((Obj *)self);
            call3(self->oC, s4, r, s1 + s0, s2);
        } else {
            int s0 = func_0047C018(self, arg1);
            int s2 = func_0047C018(self, arg1 + 1) - s0;
            int s1 = self->f4;
            call1(self->oC);
            int r = call2((Obj *)self);
            call3(self->oC, s4, r, s1 + s0, s2);
            func_0047BDC0(s4, call2((Obj *)self));
        }
    }
    return s4;
}
