/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_005DB328[];
extern "C" int func_00574BD0(void *, void *);
extern "C" void func_004C9CC0(void *, int, int, int, int);
extern "C" void *func_004C9C50(void *);
extern "C" void func_004CA520(void *, void *);
extern "C" void func_004CA110(char *self, int a, void *owner) {
    *(int *)self = a;
    *(void **)(self + 4) = owner;
    char *hdr = self + 0x14;
    *(void * volatile *)(self + 0xD0) = D_005DB328;
    func_00574BD0(self + 8, self);
    *(int *)(self + 0xCC) = 0;
    func_004C9CC0(hdr, 0, 0, 0, 0);
    *(char **)(self + 0xC4) = self + 0x18;
    *(void **)(self + 0xC8) = func_004C9C50(hdr);
    void *p = *(void **)(self + 4);
    if (p) func_004CA520(p, self);
}
