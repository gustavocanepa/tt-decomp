/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short off; short pad; void (*fn)(void *, float); };
struct VT { char p[0x10]; Ent e; };
struct Loc { VT *vptr; int f4; };
extern VT D_005AC7A0;
extern VT D_005A7A38;
extern "C" int func_0019C448(int, int, int, int);

extern "C" int func_0019C308(int arg0, int arg1, int arg2, int arg3, int arg4) {
    Loc l;
    l.vptr = &D_005AC7A0;
    VT *fin = &D_005A7A38;
    l.f4 = arg4;
    Ent *e = &l.vptr->e;
    e->fn((char *)&l + e->off, 0.0f);
    Ent *e2 = &l.vptr->e;
    e2->fn((char *)&l + e2->off, 1.0f);
    int r = func_0019C448(arg0, arg1, arg2, arg3);
    if (r != 0) {
        Ent *e3 = &l.vptr->e;
        e3->fn((char *)&l + e3->off, 1.0f);
        l.vptr = fin;
        return 1;
    }
    l.vptr = fin;
    return r;
}
