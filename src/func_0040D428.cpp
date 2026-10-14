struct Obj { char pad[0x10]; unsigned f10; };
struct Out { int f0; int f4; };
struct Tab;
extern Tab *D_00585C10;
extern "C" int func_0040D360(Obj *);
extern "C" int func_004111C8(Tab *, unsigned int);
extern "C" void func_00411298(Tab *, int, Out *);
extern "C" int func_0040D428(Obj *o, int idx, Out *out) {
    int n = func_0040D360(o);
    if (idx >= n) return 0;
    {
        Tab *t = D_00585C10;
        unsigned long k = o->f10;
        int base = func_004111C8(t, k);
        if (base == -1) return 0;
        for (int i = 0; i < n; i++) {
            func_00411298(t, base + i, out);
            if (out->f4 == idx + 1) return 1;
        }
    }
    return 0;
}
