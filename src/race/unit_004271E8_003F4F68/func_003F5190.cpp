/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int n; int pad; float data[1]; };
struct Obj { char pad0[8]; float f8; Node *tab[1]; };
extern "C" int func_003F50A0(void *, float);
extern "C" float func_00559778(float *, int, float);
extern "C" void func_005614F8(void *, int, float, float *, float *);

static inline float fmax_s(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float fmin_s(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

static inline float sum_pair(float a, float b) { return a + b; }

struct Loc { float lim; float pad[3]; float a[6]; };
extern "C" void func_003F5190(Obj *self, Obj *other, float t0, float t1, float t2) {
    Loc v;
    v.lim = t2;
    int i = func_003F50A0(self, t0);
    int j = func_003F50A0(other, t1);
    v.a[0] = 0;
    Node *p = self->tab[i];
    Node *q = other->tab[j];
    float *ap = v.a;
    func_005614F8(p->data, p->n, t0, &v.a[1], &v.a[2]);
    v.a[2] = sum_pair(v.a[1], v.a[2]);
    func_005614F8(q->data, q->n, t1, &v.a[5], &v.a[3]);
    v.a[4] = 1.0f;
    v.lim = fmin_s(fmax_s(v.lim, 0.0f), v.a[4]);
    v.a[3] = v.a[5] - v.a[3];
    self->f8 = func_00559778(ap, 6, v.lim);
}
