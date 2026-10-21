/* compiler: ee-gcc2.96-nogcse */
extern "C" void func_00346860(void *, int) throw();
extern "C" void func_0050E1A8(void *) throw();
struct VEntry { short delta, index; void (*fn)(void *, int); };
extern "C" void func_00347028(char *self, int flags) {
    func_00346860(self + 0x2D8, 2);
    char *a = self + 0x1C;
    if (a != (char *)-0x1c) {
        char *p = self + 0x280;
        if (self + 0x38 != p) {
            char *end = self + 0x38;
            do {
                p -= 0x124;
                VEntry *e = (VEntry *)(*(char **)(p + 0x1c) + 8);
                e->fn(p + e->delta, 2);
            } while(end != p);
        }
    }
    if (flags & 1) return func_0050E1A8(self);
}
