struct Obj {
    int m0;
    int m4;
};

extern "C" int func_0042CEF0(int v);
extern "C" void func_0042C848(Obj *o, int v);
extern "C" void func_0042B350(Obj *o, int v);

extern "C" Obj *func_0042D140(Obj *o, int v) {
    switch (func_0042CEF0(v)) {
    case 0:
        func_0042C848(o, v);
        break;
    case 1:
        func_0042B350(o, v - 10);
        break;
    default:
        o->m0 = 0;
        o->m4 = 0;
        break;
    }
    return o;
}
