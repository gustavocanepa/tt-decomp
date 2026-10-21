typedef long s64;
struct R { char pad[0x18]; s64 f; };
struct T { char pad[8]; R r[1000]; };
extern "C" void func_003FBC08(T *t, int idx) {
    R *sel = &t->r[idx];
    int c = (int)sel->f & 0x3FF;
    if (c != 0) {
        for (int i = 0; i < 1000; i++) {
            R *p = &t->r[i];
            int v = (int)p->f & 0x3FF;
            if (v < c) {
                s64 w = (int)(v + 1);
                s64 nb = w & 0x3FFL;
                p->f = (p->f & ~0x3FFL) | nb;
            }
        }
        sel->f = sel->f & ~0x3FFL;
    }
}
