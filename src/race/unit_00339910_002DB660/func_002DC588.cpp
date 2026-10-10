struct Result {
    int m0;
    int index;
    int pad[2];
};

struct Data {
    int w[20];
};

extern char D_005F2AF8[];

extern "C" void func_00424008(Result *r, void *key, void *o, void *table);
extern "C" void func_002DD060(Data *d, void *o);
extern "C" void func_002DD458(void *out, Data *d);

extern "C" int func_002DC588(void *o, void *key, void *out) {
    Result r;
    func_00424008(&r, key, o, D_005F2AF8);
    if (r.index < 0)
        return 0;
    Data d;
    func_002DD060(&d, o);
    func_002DD458(out, &d);
    return 1;
}
