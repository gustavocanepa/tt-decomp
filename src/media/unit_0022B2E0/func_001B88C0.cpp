/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Obj;
struct VEnt { s16 delta; s16 pad; void (*fn)(void *, s32, s32); };
struct VT { char pad[0x378]; VEnt e; };
struct Obj { char pad[4]; VT *vt; };
struct H { Obj *o; char pad[0xC]; };
struct W { s32 v; char pad[0xC]; };

extern "C" void func_001B7F40(void *, int) throw();
extern "C" void func_001B7F98(void *, void *) throw();
extern "C" void func_001DF1F8(void *, int);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_00202788(void *, int);
extern "C" void func_002027E0(void *, void *);

static inline void call(Obj *o, s32 a, s32 b) {
    VEnt *e = &o->vt->e;
    e->fn((char *)o + e->delta, a, b);
}

extern "C" void func_001B88C0(void *arg0, void *arg1, s32 arg2, char *arg3) {
    H h;
    func_001B7F98(&h, arg1);
    if (arg2 >= 2) {
        W a;
        W b;
        W *pa = &a;
        func_001DF250(pa, arg3);
        W *pb = &b;
        func_002027E0(pb, arg3 + 4);
        call(h.o, pa->v, pb->v);
        func_00202788(pb, 2);
        func_001DF1F8(pa, 2);
    } else if (arg2 > 0) {
        W a;
        W *pa = &a;
        func_002027E0(pa, arg3);
        call(h.o, 0, pa->v);
        func_00202788(pa, 2);
    }
    func_001B7F40(&h, 2);
}
