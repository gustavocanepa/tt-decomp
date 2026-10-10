struct List {
    unsigned int count;
    int m4;
    void **items;
};

struct Obj {
    char pad[0x60];
    List *list;
};

extern "C" void func_00369778(void *item);

extern "C" void func_003761D0(Obj *o) {
    unsigned int n = o->list->count;
    for (unsigned int i = 0; i < n; i++)
        func_00369778(o->list->items[i]);
}
