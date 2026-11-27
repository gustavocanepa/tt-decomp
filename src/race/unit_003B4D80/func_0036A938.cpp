/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta; short pad; int (*fn)(char *, char *, int, int, int); };
extern "C" int func_0040DE88(char *);
extern "C" int func_0040DEC8(char *);
extern "C" int func_0040F0F8(void *);
extern "C" char *func_004F7B74(char *, const char *);
extern "C" char *func_0036A938(char *self, int flag, char *arg, char *out) {
    char *name = flag != 0 ? self + 0x5564 : self + 0x5574;
    if (*name != 0) {
        func_004F7B74(out, name);
    } else {
        int value;
        if (flag != 0) value = func_0040DE88(self + 0xFD8);
        else value = func_0040DEC8(self + 0xFD8);
        int course = func_0040F0F8(*(void **)(arg + 0x70));
        char *a = *(char **)(self + 0x4840);
        Ent *e = (Ent *)(*(char **)(a + 8) + 0xA8);
        e->fn(a + e->delta, out, value, flag, course == 1);
    }
    return out;
}
