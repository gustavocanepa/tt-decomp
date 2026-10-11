struct Entry {
    int pad0[2];
    int a;
    int b;
    int c;
    int pad14;
};

struct Table {
    Entry *entries;
    int count;
    int pad[2];
};

extern "C" void func_0042D140(Table *t, int id);

extern "C" int func_0042BEB8(int i, int *a, int *b, int *c) {
    Table t;
    func_0042D140(&t, 12);
    int ok = 1;
    if (i < t.count) {
        Entry *e = &t.entries[i];
        *a = e->a;
        *b = e->b;
        *c = e->c;
    } else {
        ok = 0;
    }
    return ok;
}
