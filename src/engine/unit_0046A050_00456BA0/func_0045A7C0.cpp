/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
extern char D_005DA238[];
extern "C" void func_0045A880(void *);
extern "C" void func_0050E1A8(void *);
extern "C" void func_0045A7C0(char *self, s32 flags) {
    *(char **)(self + 0xA7C) = D_005DA238;
    do { func_0045A880(self); } while (0);
    char *a = self + 0x2C;
    char *p = self + 0x444;
    if (a != (char *)-0x100) {
        if (self + 0x12C != p) {
            do {
                p -= 0x108;
                char *t = *(char **)(p + 0x104) + 8;
                ((void (*)(void *, s32))*(void **)(t + 4))(p + *(short *)t, 2);
            } while (self + 0x12C != p);
        }
    }
    if (flags & 1) return func_0050E1A8(self);
}
