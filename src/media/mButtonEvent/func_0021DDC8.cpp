/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int pad; char *vt; char pad8[8]; int f10,f14; };
struct E { short delta,index; void *(*fn)(void *); };
extern char D_005EC4E0[],D_005EC4E8[],D_005EC500[];
extern "C" void func_00526860(const char *,...);
extern "C" const char *func_002A39C0(void *);
extern "C" int func_0022F7B8(void *);
extern "C" int func_0022F7C8(void *);
extern "C" int func_0022F610(void *,int,int);
static inline void *vcall(O *o) {
    E *e = (E *)(o->vt+0x58);
    return e->fn((char *)o+e->delta);
}
extern "C" int func_0021DDC8(O *o) {
    func_00526860(D_005EC4E0);
    const char *name = func_002A39C0(vcall(o));
    func_00526860(D_005EC4E8,name,o->f14,o->f10);
    if (func_0022F7C8(o) != 0) {
        int t = func_0022F7B8(o);
        func_0022F610(o,t,func_0022F7C8(o));
    }
    func_00526860(D_005EC500);
    return 1;
}
