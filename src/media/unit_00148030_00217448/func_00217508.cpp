/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int pad; char *vt; };
struct Entry { short delta, index; int (*fn)(void *); };
struct Args { int x,y; Obj *z,*w; };
extern "C" void func_00202788(void *, int);
extern "C" void func_002027E0(void *, void *);
extern "C" void func_002171D0(void *, int) throw();
extern "C" void func_00217228(void *, void *) throw();
extern "C" void func_00217748(int, int, int, int, int);
static inline int vcall(Obj *o) {
    Entry *e = (Entry *)(o->vt + 0x68);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_00217508(void *unused, void *src, int n, Args *args) {
    int buf[4];
    if (n >= 4) {
        func_002027E0(buf, args);
        int x = buf[0];
        func_00202788(buf, 2);
        func_002027E0(buf, (char *)args + 4);
        int y = buf[0];
        func_00202788(buf, 2);
        int z = vcall(args->z) != 0;
        int w = vcall(args->w) != 0;
        func_00217228(buf, src);
        func_00217748(buf[0], x, y, z, w);
        func_002171D0(buf, 2);
    }
}
