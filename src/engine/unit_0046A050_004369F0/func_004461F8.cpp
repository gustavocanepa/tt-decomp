#include "types.h"
struct Item { char pad[0x1C]; };
struct Vec { Item *begin; int size; };
struct A { short f0; u8 f2; u8 pad3; Vec v; };
struct Ent { char pad[0x80]; char *f80; };
struct Pt { char pad[8]; };
struct Big {
    char pad0[0x2000];
    char s2000[0x6E14 - 0x2000];
    int f6E14;
    char pad6E18[8];
    Ent *f6E20;
    char pad6E24[4];
    float f6E28;
};
extern "C" void func_00104838(void *);
extern "C" void func_00104868(void *, int);
extern "C" void func_0043FA18(void *, void *, void *, float);
extern "C" int func_00446560(Item *, Pt *, int, float, float);
extern "C" void func_0044C230(void *, int, int);
extern "C" void func_0044C2D8(void *);
extern "C" void func_0056A1E0(void *);
extern "C" void func_0056A2F8(void *, void *, void *);
extern "C" int func_0056A3F0(void *, void *, int);

static inline Item *vbeg(Vec *v) { return v->begin; }
static inline Item *vend(Vec *v) { return v->begin + v->size; }

extern "C" void func_004461F8(A *a, Big *b, float t) {
    char sp[0x40];
    char sp40[0x10];
    if (a->f0 < 0) return;
    func_00104838(sp);
    char *s7 = b->s2000;
    func_0056A1E0(s7);
    int fp = 0x400;
    Vec *vv = &a->v;
    Item *end = vend(vv);
    Item *it = vbeg(vv);
    Pt *p = (Pt *)b;
    {
        while (it != end) {
            int n = func_00446560(it, p, fp, b->f6E28, t);
            for (int k = 0; k < n - 1; k++)
                func_0056A2F8(s7, &p[k], &p[k + 1]);
            it++;
            p += n;
            fp -= n;
        }
    }
    Ent *e = b->f6E20;
    func_0043FA18(e->f80 + a->f0 * 12, b, sp, t);
    func_0044C230(sp40, b->f6E14, *(int *)(s7 + 0x3000) + a->f2 * 2 - 2);
    func_0056A3F0(s7, sp40, 0x4000);
    func_0044C2D8(sp40);
    func_00104868(sp, 2);
}
