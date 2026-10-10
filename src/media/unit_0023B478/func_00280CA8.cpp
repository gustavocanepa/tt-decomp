extern "C" void func_0026D5B0(void *out, const char *s);
extern "C" const char D_005F02B0[];

struct Obj {
    char pad0[0x10];
    void *out;
};

extern "C" void func_00280CA8(Obj *o, const char *a, const char *b) {
    void **p = &o->out;
    if (*p) {
        if (b)
            func_0026D5B0(*p, b);
        func_0026D5B0(*p, a);
        return func_0026D5B0(*p, D_005F02B0);
    }
}
