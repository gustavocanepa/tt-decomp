/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short d; short i; void *fn; };
struct Vt { char pad[0x18]; VE e18; char pad2[0x168 - 0x20]; VE e160; };
struct O { Vt *vt; };
struct R { char pad[0x18]; int f18; };
extern "C" void func_00416CB0(void *, int, float) throw();
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_00416DD8(void *self, O *o, float f) {
    func_00473050();
    func_004751FC();
    VE *e = &o->vt->e18;
    ((void (*)(void *, float))e->fn)((char *)o + e->d, f);
    VE *e2 = &o->vt->e160;
    R *r = ((R *(*)(void *))e2->fn)((char *)o + e2->d);
    func_00416CB0(self, r->f18, f);
    func_004730A8();
}
