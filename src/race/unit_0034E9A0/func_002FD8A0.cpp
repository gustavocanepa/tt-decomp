/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[2]; unsigned char m2, m3; };
extern "C" int func_002FD870(Obj *, int) throw();
extern "C" int func_002FD880(Obj *, int) throw();
extern "C" int func_002FD890(Obj *, int) throw();

extern "C" int func_002FD8A0(Obj *o, int a, int b, int c) {
    int x = func_002FD870(o, a);
    x = (x != 0) & (func_002FD880(o, b) != 0);
    x = (x != 0) & (func_002FD890(o, c) != 0);
    o->m2 = 0;
    o->m3 = 0;
    return x;
}
