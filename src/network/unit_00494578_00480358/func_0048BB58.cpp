/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct W { unsigned int v __attribute__((packed)); } __attribute__((packed));
struct Blk {
    char pad[8];
    char *m8;
};
struct O {
    char pad0[4];
    void *m4;
    char pad1[0x48];
    unsigned int m50;
    unsigned int m54;
    unsigned int m58;
    unsigned int m5C;
};
extern "C" Blk *func_00487850(void *, unsigned int) throw();
extern "C" void func_00487A00(void *, Blk *) throw();

extern "C" int func_0048BB58(O *o, unsigned int a, unsigned int val) {
    unsigned int idx = a * 4;
    unsigned int q = idx / o->m50;
    unsigned int rem = idx % o->m50;
    unsigned int i = 0;
    int r = 0;
    if (__builtin_expect((int)o->m58, 0)) {
        do {
            Blk *b = func_00487850(o->m4, o->m54 + i * o->m5C + q);
            i++;
            r = -5;
            if (b == 0) {
                return r;
            }
            W *w = (W *)(b->m8 + rem);
            val &= 0x0FFFFFFF;
            val |= w->v & 0xF0000000;
            w->v = val;
            func_00487A00(o->m4, b);
            r = 0;
        } while (i < o->m58);
    }
    return r;
}
