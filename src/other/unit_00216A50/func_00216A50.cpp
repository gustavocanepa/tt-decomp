typedef int s32;

struct Entry {
    s32 offset;
    char pad[0x1C];
};

struct Table {
    char *base;
    s32 count;
    Entry *entries;
};

extern "C" void func_002168A8(void *, char *);

extern "C" s32 func_00216A50(Table *t, void *dst, s32 i) {
    if (i < t->count) {
        func_002168A8(dst, t->base + t->entries[i].offset);
        return 1;
    }
    return 0;
}
