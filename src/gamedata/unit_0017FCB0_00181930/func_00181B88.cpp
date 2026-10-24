/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short idx; int (*fn)(void *); };
struct Vt { char pad[0xD0]; VE e; };
struct Fb { Vt *vt; };
struct Inner { char pad[0x4C]; Vt *vtbl; char pad2[0x150 - 0x50]; int pad150; int f154; int f158; };
struct Holder { char pad[0x10]; Inner *f10; };
struct Obj { char pad[0x4C]; struct { short d; short i; int a; } *v; };
extern "C" void func_00151A90(void *, int);
extern "C" void func_00151AE8(void *, void *);
extern "C" void func_00180390(void *, int) throw();
extern "C" void func_001803E8(void *, void *) throw();
extern "C" void func_00183430(int, int, int, int);
extern "C" Inner *GT4MC__FileGT4GameData__loadInstance(int, void *, int, void *, void *, void *);
extern char D_005206C0[];
struct T { Holder *h; int p[3]; };
struct U { int v; int p[3]; };
extern char D_00521240[];
extern "C" void func_00181B88(void *a0, void *a1, int n, void *a3) {
    if (n > 0) {
        T h;
        Inner *r = 0;
        func_00151AE8(&h, a3);
        if (h.h->f10 != 0) {
            Obj *o = (Obj *)h.h->f10;
            r = GT4MC__FileGT4GameData__loadInstance(o->v->a, D_00521240, 0, (char *)o + o->v->d, D_005206C0, o);
        }
        if (r != 0) {
            U s3obj; U *s3 = &s3obj;
            func_001803E8(s3, a1);
            int sv = s3->v;
            VE *e = &r->vtbl->e;
            int *q = (int *)((char *)r + 0x198);
            int s1 = q[1];
            int s0 = q[2] - s1;
            int v = e->fn((char *)r + e->delta);
            func_00183430(sv, s1, s0, v);
            func_00180390(s3, 2);
        }
        func_00151A90(&h, 2);
    }
}
