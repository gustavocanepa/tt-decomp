struct Result {
    int m0;
    int m4;
    int m8;
    int mC;
    int rest[12];
    Result(int a) __asm__("func_003F2358");
    ~Result() __asm__("func_003F2378");
};

struct Table {
    char pad[0x10];
    char *entries;
};

struct Obj {
    int m0;
    Table *table;
};

extern "C" void func_003F39A0(void *entry, int a, Result *res, float f);

extern "C" int func_003EECB8(Obj *o, int idx) {
    Table *t = o->table;
    if (t == 0)
        return 0;
    char *e = t->entries + idx * 16;
    Result r(0);
    func_003F39A0(e, 0, &r, 0.0f);
    return r.m8;
}
