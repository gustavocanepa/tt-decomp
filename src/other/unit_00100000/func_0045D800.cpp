struct Entry {
    int key;
    void *data;
    int size;
    int padC;
};

struct Table {
    char pad0[0xC];
    unsigned int count;
    Entry entries[1];
};

extern "C" void *func_004F4E58(const void *key, const void *base, unsigned int n, unsigned int size,
                               int (*compar)(const void *, const void *)); /* bsearch */
extern "C" int func_0045D7E8(const void *a, const void *b);

extern "C" void *func_0045D800(Table *t, const void *key, int *size) {
    Entry *e = (Entry *)func_004F4E58(key, t->entries, t->count, sizeof(Entry), func_0045D7E8);
    if (!e)
        return 0;
    if (size)
        *size = e->size;
    return e->data;
}
