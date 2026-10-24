/* compiler: ee-gcc2.96-stl */
struct VE { short adj; short pad; void (*fn)(char *); };
struct VT { char pad[0x48]; VE e48; };
struct A { char pad[0x60]; int f60; char pad64[0x44]; int fA8; int fAC; };
struct A2 { char pad[0x60]; void *f60; char pad64[0x44]; VT *vt; int fAC; };
struct B { char pad[0x50]; A2 *f50; int f54; };
extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0047EE88(void *);
extern "C" int func_004AC7F0(void *, void *);
extern "C" void func_004AC8B8(void *, void *);
extern "C" void func_0047E690(A2 *a, B *b) {
    void *r;
    func_004A4D68(a);
    r = 0;
    if (a == b->f50 && func_004AC7F0(&a->fAC, ((char *)b + 0x54)) != 0) {
        func_004AC8B8(&a->fAC, ((char *)b + 0x54));
        if (a->fAC == 0) {
            VE *e = &a->vt->e48;
            r = a->f60;
            a->f60 = 0;
            e->fn((char *)a + e->adj);
        }
    }
    func_004A4DD8(a);
    if (r != 0) func_0047EE88(a);
}
