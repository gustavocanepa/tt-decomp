/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int x; char *vt; };
struct Entry { short delta; short index; void (*fn)(void *, int *, int *); };
extern char D_0057A938[];
extern "C" void func_001B1D98(void *, int, int);
extern "C" void func_001DF1F8(void *, int);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" int func_0029E9F0(void *);
extern "C" void func_001D02E8(void *unused, int count, char *args) {
    void *buf0[4];
    void *buf1[4];
    int x, y;
    if (count >= 2) {
        func_0029CF48(buf0, args);
        void **p = buf1;
        func_0029CF48(p, args + 4);
        int a = func_0029E9F0(buf0[0]);
        int b = func_0029E9F0(p[0]);
        func_001B1D98(D_0057A938, a, b);
        func_0029CEF0(p, 2);
        func_0029CEF0(buf0, 2);
    } else if (count == 1) {
        func_001DF250(buf0, args);
        Obj *o = (Obj *)buf0[0];
        Entry *e = (Entry *)(o->vt + 0x220);
        e->fn((char *)o + e->delta, &x, &y);
        func_001B1D98(D_0057A938, x, y);
        func_001DF1F8(buf0, 2);
    }
}
