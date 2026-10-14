/* compiler: ee-gcc2.96-no-strict-aliasing */
struct T {char pad[0x1C]; char *tab;};
struct B {char pad[0xCC]; T *t;};
struct A {char pad[4]; B *b;};
struct Self {A *a; char pad[0x7C]; int n; int st; char pad2[0x24]; float f0; float lo, hi, len;};
struct Loc {char pad[16]; int v;};
struct Out {int pad; float v;};
extern "C" float func_003A97E0(A *, Out *, int *, int);
extern "C" void func_00319760(Self *self, Out *out, int idx){
    Loc loc;
    loc.v = self->st;
    float hi = 500.0f;
    float lo = 0x1.999998p-4f;
    if (idx >= 0) {
        char *e = self->a->b->t->tab + (idx << 6);
        lo = *(float *)(e + 0x24);
        hi = *(float *)(e + 0x28);
        if (lo < 0x1.999998p-4f) lo = 0x1.999998p-4f;
    }
    float *p = &out->v;
    *p = hi;
    float len = func_003A97E0(self->a, out, &loc.v, idx << 6);
    float mn = len + lo;
    float nx = len + self->f0;
    *p = nx;
    if (hi < nx) {
        *p = hi;
        self->f0 = hi - len;
    }
    if (*p < mn) {
        *p = mn;
        self->f0 = lo;
    }
    self->lo = lo;
    self->hi = hi;
    self->n = idx;
    self->len = len;
    self->st = loc.v;
}
