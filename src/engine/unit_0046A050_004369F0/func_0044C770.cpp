/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {
    long key;
    long val;
};

struct Pool {
    char pad[0x30];
    struct Entry *items;
    char pad2[4];
    int count;
};

extern "C" void func_004A4D68(void *p);
extern "C" int func_0044C720(void *p, long key) throw();
extern "C" void func_004A4DD8(void *p);
extern "C" void *func_004F6574(void *dst, const void *src, unsigned n) throw();

extern "C" int func_0044C770(Pool *p, long a1, long a2) {
    int found = 0;
    func_004A4D68(p);
    int r = func_0044C720(p, a1);
    if (r < 0) {
        r = ~r;
        int count = p->count;
        struct Entry *e = &p->items[r];
        if (r != count) {
            func_004F6574(e + 1, e, (unsigned)(count - r) * 16);
        }
        e->key = a1;
        found = 1;
        e->val = a2;
        p->count = p->count + 1;
    }
    func_004A4DD8(p);
    return found;
}
