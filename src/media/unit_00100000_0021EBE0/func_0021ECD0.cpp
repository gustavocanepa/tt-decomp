/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int pad; char *vt; char pad8[8]; int f10,f14; char pad18[8]; void (*cb)(int,int); };
struct E { short delta,index; void *(*fn)(void *); };
extern char D_005EC5F0[],D_005EC5F8[],D_005EC610[];
extern "C" void func_00526860(const char *,...);
extern "C" const char *func_002A39C0(void *);
extern "C" int func_0022F7B8(void *);
extern "C" int func_0022F7C8(void *);
static inline void *vcall(O *o) {
    E *e = (E *)(o->vt+0x58);
    return e->fn((char *)o+e->delta);
}
extern "C" int func_0021ECD0(O *o) {
    func_00526860(D_005EC5F0);
    const char *name = func_002A39C0(vcall(o));
    func_00526860(D_005EC5F8,name,o->f14,o->f10);
    if (func_0022F7C8(o) != 0 && o->cb != 0) {
        int t = func_0022F7B8(o);
        o->cb(t,func_0022F7C8(o));
    }
    func_00526860(D_005EC610);
    return 1;
}
