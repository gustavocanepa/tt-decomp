/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { short delta; short pad; void (*fn)(char *, char *, int); };
extern "C" int func_0036AA10(char *, char *) throw();
extern "C" int func_004A8268(const char *, const char *) throw();
extern char D_005F6AE0[];
extern "C" void func_0036ABB8(char *self) {
    char buf[0x10];
    func_0036AA10(self, buf);
    if (func_004A8268(buf, D_005F6AE0) != 0) {
        char *a = *(char **)(self + 0x4840);
        Ent *e = (Ent *)(*(char **)(a + 8) + 0xB8);
        e->fn(a + e->delta, buf, 0);
    }
}
