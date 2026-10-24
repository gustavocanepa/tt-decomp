struct Entry {
    int id;
    char pad[0x3C];
};

extern "C" void *func_00411B88(int);
extern "C" int func_004F7B74(void *, const void *);

extern "C" int func_0040FAD8(int idx, void *dst, void *src) {
    if (idx >= 6)
        return 0;
    Entry *e = (Entry *)(0x585CA8 + idx * 4);
    if (!e->id)
        return 0;
    void *p = func_00411B88(e->id);
    if (!p)
        return 0;
    func_004F7B74(src, p);
    return 1;
}
