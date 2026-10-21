/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long s64;
struct Ent { short delta; short pad; void (*fn)(char *, char *, int); };
extern "C" s64 func_0040CFE0(char *);
extern "C" unsigned long long func_0040CFF0(char *);
extern "C" char *GT4Model__CarModel__getModelFileName(s64, char *, int, int);
extern "C" void func_004F7A30(void *, void *);
extern char D_005F6AD8[];
extern "C" void func_0036A8A0(char *self, int arg) {
    char buf[0x50];
    char *model = self + 0xFD8;
    func_0040CFE0(model);
    GT4Model__CarModel__getModelFileName(func_0040CFF0(model), buf, arg == 2, *(int *)(self + 0x484C));
    func_004F7A30(buf, D_005F6AD8);
    char *a = *(char **)(self + 0x4840);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0x80);
    e->fn(a + e->delta, buf, arg);
}
