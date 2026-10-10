struct Obj {
    char pad0[0x10];
    int a;
    int f14;
    int b;
};

extern "C" int func_00357310(const char *name);
extern "C" char D_005F5618[];
extern "C" char D_005F5620[];

extern "C" void func_0035ACD0(Obj *o) {
    if (o->a == 0) {
        o->a = func_00357310(D_005F5618);
        o->b = func_00357310(D_005F5620);
    }
}
