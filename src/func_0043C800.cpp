/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { char p0[0x14]; int f14; int f18; char p1[8]; void *f24; void *f28; };
extern "C" void func_0043C4C0(O *, void *) throw();
extern "C" void *func_0043C740(int, void *, void *) throw();
extern "C" int func_0043C800(O *o, int ev) {
    void *p = o->f24;
    if (!p) return 0;
    void *q = o->f28;
    if (!q) {
        func_0043C4C0(o, p);
        return 0;
    }
    if (o->f18) {
        if (ev == 0x26) { func_0043C4C0(o, func_0043C740(3,p,q)); return 1; }
        if (ev == 0x28) { func_0043C4C0(o, func_0043C740(2,p,q)); return 1; }
    }
    if (o->f14) {
        if (ev == 0x25) { func_0043C4C0(o, func_0043C740(1,p,q)); return 1; }
        if (ev == 0x27) { func_0043C4C0(o, func_0043C740(0,p,q)); return 1; }
    }
    return 0;
}
