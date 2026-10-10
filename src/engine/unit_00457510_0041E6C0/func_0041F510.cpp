struct List {
    int count;
    void *items[1];
};

extern "C" void func_0041EF60(void *item, void *a, void *b);

extern "C" void func_0041F510(List *l, void *a, void *b) {
    for (int i = 0; i < l->count; i++)
        func_0041EF60(l->items[i], a, b);
}
