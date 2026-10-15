/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int f0; int f4; char pad[0xA80]; char sub[1]; };
extern "C" int func_004587A0(void *);
extern "C" int func_00458E40(void *) throw();
extern "C" void func_00459950(void *, int);
extern "C" int func_00459A38(void *);
extern "C" void func_00459B70(void *, void *, int);
extern "C" int func_004A8268(const char *, const char *) throw();
extern char D_00602500[];
extern "C" int func_00458EE0(O *o) {
    void *s = o->sub;
    int n = func_00459A38(s);
    int d = n - 2;
    if (func_004587A0(o)) {
        if (d < 0) {
            o->f0 = 1;
            o->f4 = 1;
            return 0;
        }
        if (d < 5) func_00459950(s, d);
        else {
            char buf[8];
            func_00459B70(s, buf, 5);
            buf[4] = 0;
            if (func_004A8268(D_00602500, buf) == 0) {
                int r = func_00458E40(o);
                if (r == 0) return r;
            } else {
                func_00459950(s, n - 7);
            }
        }
        return func_004587A0(o);
    }
    return 0;
}
