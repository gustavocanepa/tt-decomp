/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec2 {float x,y;};
typedef void (*VFn)(void *self, int a1, int a2);

extern "C" void func_00444128(void *p) throw();
extern "C" void func_00444920(void *a, void *b) throw();

extern "C" void func_0044BD78(char *p, int arg1) {
    char **slot = (char **)(p + 0x80);
    func_00444128(p);
    *(Vec2 *)(p + 0x90) = *(Vec2 *)(p + 0x3C);
    func_00444920(*(void **)(p + 0x58), p + 0x90);
    char *a3 = *slot;
    if (a3 != 0) {
        char *vt = *(char **)(a3 + 0x5C) + 0x10;
        short adj = *(short *)vt;
        VFn fn = *(VFn *)(vt + 4);
        fn(a3 + adj, arg1, 0);
    }
    a3 = *(char **)(p + 0x74);
    if (a3 != 0 && a3 != *slot) {
        char *vt = *(char **)(a3 + 0x5C) + 0x10;
        short adj = *(short *)vt;
        VFn fn = *(VFn *)(vt + 4);
        fn(a3 + adj, arg1, 0);
    }
}
