/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result { int value; };
struct VEI { short delta; short index; void (*fn)(void *, int, int, float); };
struct VEF { short delta; short index; void (*fn)(void *, float); };
struct Vec { int x; char *b; char *e; char *c; };
struct Loc { char *vtbl; int a; char pad[8]; Vec v; char pad2[0x10]; };
extern "C" char D_005AC7A0[];
extern "C" char D_005A7A38[];
extern "C" Result func_0019C850(int, int, Vec *) throw();
extern "C" int func_001A3628(char *, int, int, int, float, float);
extern "C" void *func_004F64C4(void *, const void *, unsigned);
extern "C" void func_004A45D0(char *) throw();
static inline int status(const Result *const x) { return x->value; }
static inline void progress(Loc *const self, float value) {
    VEF *e = (VEF *)(self->vtbl + 0x10);
    e->fn((char *)self + e->delta, value);
}
static inline void fin(Loc *l, char *vt2) {
    if (l->v.b) func_004A45D0(l->v.b);
    l->vtbl = vt2;
}
extern "C" int func_001A1228(int arg0, int arg1, char *arg2, int arg3) {
    Loc loc;
    loc.vtbl = D_005AC7A0;
    loc.a = arg3;
    char *vt2 = D_005A7A38;
    VEF *e1 = (VEF *)(D_005AC7A0 + 0x10);
    e1->fn((char *)&loc + e1->delta, 0.0f);
    progress(&loc, 0.98f);
    loc.v.b = 0;
    loc.v.e = 0;
    loc.v.c = 0;
    Result result = func_0019C850(arg0, arg1, &loc.v);
    int r = result.value;
    if (status(&result)) {
        fin(&loc, vt2);
        return r;
    }
    char *s0 = loc.v.b;
    int n = func_001A3628(s0, loc.v.e - s0, 0, 1, 0x1.4f0328p-1f, 0x1.61f968p-2f);
    if (n < 0) {
        fin(&loc, vt2);
        return 2;
    }
    progress(&loc, 1.0f);
    if (n > 0x14000) {
        fin(&loc, vt2);
        return 2;
    }
    func_004F64C4(arg2, s0 + 8, n);
    *(int *)(arg2 + 0x14000) = n;
    progress(&loc, 1.0f);
    fin(&loc, vt2);
    return 0;
}
