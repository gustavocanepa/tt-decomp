/* compiler: ee-gcc2.96-no-strict-aliasing */
struct B; struct C;
struct VE { short adj; short pad; void *(*fn)(char *, B *, C *); };
struct VT { char pad[0xD8]; VE e; };
struct A { char pad[0xA4]; VT *vt; };
struct B { char pad[0xC]; int *p; };
struct C { int kind; int f4; int f8; };
extern "C" void func_004BEB80(int, int, int, A *);
extern "C" void func_004BEBB0(int, int, int, A *);
extern "C" void func_004BEE50(int, int);
extern "C" void *func_00480C30(A *a, B *b, C *c) {
    switch (c->kind) {
    case 0: {
        VE *e = &a->vt->e;
        return e->fn((char *)a + e->adj, b, c);
    }
    case 1:
        func_004BEB80(*b->p, c->f4, c->f8, a);
        return c;
    case 2:
        func_004BEBB0(*b->p, c->f4, c->f8, a);
        return c;
    case 3:
        func_004BEE50(*b->p, c->f4);
        return c;
    default:
        return 0;
    }
}
