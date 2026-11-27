/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { int handle; char pad[0xD0]; };
extern const char *D_00598EF8[];
extern "C" void func_001FEB90(void *);
extern "C" int func_004C9E90(const char *);
extern "C" void func_004CA520(void *, void *);
extern "C" void func_001C5A28(char *self) {
    func_001FEB90(self);
    void *ctx = self + 0x198;
    Entry *p = (Entry *)(self + 0x1D8);
    const char **names = D_00598EF8;
    int n = 1;
    do {
        p->handle = func_004C9E90(*names++);
        func_004CA520(ctx, p);
        p++;
        n--;
    } while (n >= 0);
}
