struct VEntry {
    short delta;
    short index;
    void *(*fn)(void *, int);
};

struct Obj {
    void *vtbl;
    char pad[0xA4C - 4];
    int count;
};

extern "C" void *func_0031CA98(Obj *self) {
    VEntry *e = (VEntry *)((char *)self->vtbl + 0xE0);
    void *base = (char *)self + e->delta;
    void *list = (char *)self + self->count * 0x1B4 + 0x10;
    void *item = e->fn(base, self->count);
    if (!item)
        return 0;
    if ((char *)item != (char *)*(void **)((char *)list + 0x180))
        return 0;
    return *(void **)((char *)item + 0x1E4);
}
