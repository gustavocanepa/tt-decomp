struct Entry {
    const char *name;
    int value;
};

struct Table {
    int f0;
    int count;
    Entry *entries;
};

extern "C" int func_0044CD30(const void *a, const void *b);
extern "C" void *func_004F4E58(const void *key, const void *base, unsigned int n, unsigned int size,
                               int (*cmp)(const void *, const void *));

extern "C" int func_0044CD48(Table *t, const char *name) {
    if (!name) {
        return 0;
    }
    if (!*name) {
        return 0;
    }
    Entry *e = (Entry *)func_004F4E58(name, t->entries, t->count, sizeof(Entry), func_0044CD30);
    if (e) {
        return e->value;
    }
    return 0;
}
