/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int x; char *b; char *e; };
struct VEI { short delta; short index; void (*fn)(void *, int, Vec *, float); };
struct VEF { short delta; short index; void (*fn)(void *, float); };
struct VE1 { short delta; short index; int (*fn)(void *, int); };
struct VEG { short delta; short index; int (*fn)(void *, char *); };
struct Self { char p[0x4C]; char *tbl; };
struct Loc { char *vtbl; int a;  };
struct G { char *tbl; };
extern "C" char D_005AC7A0[];
extern "C" char D_005A7A38[];
extern "C" G *D_005857DC;
struct Result { int value; };
extern "C" Result func_0019C850(Self *, int, Vec *) throw();
extern "C" int func_001A3628(char *, int, int, int, float, float);
extern "C" void func_004F6574(char *, char *, unsigned) throw();
extern "C" void func_005203E8(Vec *, char *, unsigned, char *);
static inline int status(const Result *const x) { return x->value; }
static inline void init(Result *const x, int value) { x->value = value; }
static inline char *begin(Vec *v) { return v->b; }
static inline char *end(Vec *v) { return v->e; }
static inline unsigned size(Vec *v) { return end(v)-begin(v); }
static inline void erase(Vec *v, char *first, char *last) {
    func_004F6574(first, last, end(v)-last);
    v->e -= last-first;
}
static inline void resize(Vec *v, unsigned n, const char &x) {
    if (n < size(v)) erase(v, begin(v)+n, end(v));
    else func_005203E8(v, end(v), n-size(v), (char *)&x);
}
extern "C" int func_0019CEE0(Self *self, int arg1, Vec *v, int arg3) {
    Loc loc;
    char *vt2 = D_005A7A38;
    loc.a = arg3;
    loc.vtbl = D_005AC7A0;
    VEF *e1 = (VEF *)(D_005AC7A0 + 0x10);
    e1->fn((char *)&loc + e1->delta, 0.05f);
    VE1 *e0 = (VE1 *)(self->tbl + 0x38);
    e0->fn((char *)self + e0->delta, arg1);
    VEF *e = (VEF *)(loc.vtbl + 0x10);
    e->fn((char *)&loc + e->delta, 0.98f);
    Result result = func_0019C850(self, arg1, v);
    int r = status(&result);
    if (r) {
        loc.vtbl = vt2;
        return result.value;
    }
    int se0 = (int)v->e;
    char *s1 = v->b;
    int n = se0 - (int)s1;
    int ret;
    if (n == 0) { loc.vtbl = vt2; return 2; }
    {
        int s0 = func_001A3628(s1, n, 0, 0, 0x1.161910p-3f, 0x1.4f49cep-1f);
        if (s0 < 0) { loc.vtbl = vt2; return 2; }
        {
            func_004F6574(v->b, s1 + 8, s0);
            resize(v, s0, char());
            VEF *e3 = (VEF *)(loc.vtbl + 0x10);
            e3->fn((char *)&loc + e3->delta, 1.0f);
            G *g = D_005857DC;
            VEG *eg = (VEG *)(g->tbl + 0x18);
            if (eg->fn((char *)g + eg->delta, v->b) == 0) {
                loc.vtbl = D_005A7A38; return 2;
            }
            loc.vtbl = D_005A7A38;
            return 0;
        }
    }
    loc.vtbl = vt2;
    return 2;
}
