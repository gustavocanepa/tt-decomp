struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Stream {
    int f0;
    VEntry *vtbl;
};

extern "C" void func_004A9360(Stream *s);
extern "C" void func_004A9380(Stream *s);

extern "C" void func_004A9818(Stream *s) {
    func_004A9360(s);
    VEntry *e = &s->vtbl[4];
    e->fn((char *)s + e->delta);
    func_004A9360(s);
    func_004A9380(s);
}
