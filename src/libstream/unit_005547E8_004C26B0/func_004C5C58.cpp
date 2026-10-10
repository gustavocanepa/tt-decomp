extern "C" int func_004C4320(int, int, int);
extern "C" void func_004C5798(void *, int, int, float);

struct Obj {
    char pad[0x60];
    int m60;
    int m64;
    int m68;
};

extern "C" void func_004C5C58(Obj *o, int a, int b, int c) {
    int v = func_004C4320(a, b, c);
    if (v != 0) {
        func_004C5798(o, v, a, 240.0f);
        o->m60 = 2;
        o->m68 = 0;
        return;
    }
    o->m60 = 0;
}
