#include "types.h"
struct E { s64 v; u8 b8; u8 b9; u8 a; u8 b; };
struct S { int n; int pad4; short id; short pad; E e[128]; };
struct It { int p0; const char *name; int p8; int pc; int p10; int p14; };
struct L { It *items; unsigned count; int pad; };
extern "C" {
void func_003FE6F0(S *, char);
void func_0042D140(L *, int);
short func_004B2AC8();
s64 func_00418938(const char *);
int func_004A8368(const char *);
int func_004E5700(const char *, const char *, unsigned);
extern char D_005FA590[];
void func_003FE368(S *self, int id) {
    L l;
    unsigned i;
    func_0042D140(&l, 12);
    if (id == 0) {
        self->id = func_004B2AC8();
        i = 0;
    } else {
        self->id = id;
        i = 0;
    }
    signed char m = -1;
    E *e = self->e;
    do {
        i++;
        e->b8 = 0;
        e->b9 = 0;
        e->v = 0;
        e->a = m;
        e->b = m;
        e++;
    } while (i < 128);
    i = 0;
    self->n = 0;
    if (l.count != 0) {
        u8 one = 1;
        int off = 0;
        do {
            const char *nm = ((It *)((char *)l.items + off))->name;
            E *x = &self->e[self->n];
            if (func_004E5700(nm, D_005FA590, func_004A8368(D_005FA590)) != 0) {
                x->v = func_00418938(((It *)(off + (int)l.items))->name);
                x->b9 = one;
                x->a = self->n;
                x->b = self->n;
                self->n = self->n + 1;
            }
            i++;
            off += 0x18;
        } while (i < l.count);
    }
    func_003FE6F0(self, 1);
}
}
