struct VE { short delta; short idx; void *(*fn)(void *); };
struct Obj { int x; char *vt; };
extern char D_005ED178[];
extern "C" const char *func_002A39C0(void *a);
extern "C" void func_00526860(const char *fmt, ...);

extern "C" int func_0022F878(void *self, int a1, Obj *o) {
    if (o != 0) {
        VE *e = (VE *)(o->vt + 0x58);
        const char *s0 = func_002A39C0(e->fn((char *)o + e->delta));
        func_00526860(D_005ED178, s0, func_002A39C0(o));
    }
    return 0;
}
