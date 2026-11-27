/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta; short pad; void (*fn)(char *, char *, char *, int); };
extern "C" int func_0036A938(char *, int, int, char *) throw();
extern "C" void func_0036AB20(char *self, int arg) {
    char buf[2][0x10];
    char *p = buf[0];
    for (int i = 0; i < 2; i++, p += 0x10) {
        func_0036A938(self, i == 0, arg, p);
    }
    char *a = *(char **)(self + 0x4840);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0xB0);
    e->fn(a + e->delta, buf[0], buf[1], 0);
}
