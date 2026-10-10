/* Static initialisation and destruction of a global object (derived from a base whose
   constructor/destructor are out of line): construct + own vtable, or destroy. */
struct Obj {
    char pad0[0x18];
    void *vt;
};

extern Obj D_00584038;
extern char D_005CF678[];
extern "C" Obj *func_0042F9C0(Obj *o);
extern "C" void func_0042F960(Obj *o, int in_chrg);

extern "C" void func_0034BEF0(int initialize, int priority)
{
    if (priority == 0xFFFF) {
        if (initialize == 1) {
            Obj *o = &D_00584038;
            func_0042F9C0(o);
            o->vt = D_005CF678;
        }
        if (initialize == 0)
            func_0042F960(&D_00584038, 0);
    }
}
